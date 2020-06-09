#include "../include/futures.hh"

namespace Futures
{
    //! declare the random seeds as static members due to issues with in-class declaration
    static std::random_device rd;
    static std::mt19937 twister{rd()};

    void Future::threadID()
    {
        const std::string scope = "In class";
        const std::string message = "The function is running on the thread ID: ";
        std::cout << scope;
        newLine();
        std::cout << message;
        newLine();
        std::cout << std::this_thread::get_id();
        newLine();
    }

    void Future::sleep(int duration)
    {
        std::cout << "Started process...";
        newLine();
        std::this_thread::sleep_for(std::chrono::seconds(duration));
        std::cout << "Stopped process...";
        newLine();
    }

    void Future::show()
    {
        auto now = std::chrono::system_clock::now();
        std::time_t date = std::chrono::system_clock::to_time_t(now);
        std::cout << std::ctime(&date);
        newLine();
    }

    void Future::slowLoop(int arr[], int arrsize)
    {
        std::cout << "started slow loop...";
        newLine();
        for (int i = 0; i < arrsize; ++i)
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "arr[i] = " << arr[i];
            newLine();
        }
        Futures::Future::threadID();
    }

    void Future::fastLoop(int arr[], int arrsize)
    {
        std::cout << "started fast loop...";
        newLine();
        for (int i = 0; i < arrsize; ++i)
        {
            std::cout << "arr[i] = " << arr[i];
            newLine();
        }
        Futures::Future::threadID();
    }

    void Future::fastStream(char s, int ms)
    {
        for (int i = 0; i < 50; ++i)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(ms));
            std::cout << s;
        }
        Futures::Future::threadID();
    }

    void Future::slowStream(char s, int ms)
    {
        for (int i = 0; i < 50; ++i)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(ms));
            std::cout << s;
        }
        Futures::Future::threadID();
    }
    //! this function was outside the namespace (needs to be eliminated or refactored)
    // void Future::threadID()
    // {
    //     // const std::string scope = "In namespace";
    //     // const std::string message = "The function is running on the thread ID: ";
    //     // std::cout << scope;
    //     // newLine();
    //     // std::cout << message;
    //     // newLine();
    //     std::cout << std::this_thread::get_id();
    //     newLine();
    // }

    void Future::newLine()
    {
        std::cout << "\n";
    }

    std::vector<std::future<int>> Future::generateFutures(size_t n_futures, int timer, int (*function)(int arg))
    {
        std::vector<std::future<int>> results;
        int min_num = 0;
        int max_num = 10;
        for (auto task_id = 0; task_id < n_futures; ++task_id)
        {
            auto new_task = std::async(std::launch::async, function, RNG::give_random_int(min_num, max_num));
            //move the task into the future container so that the promise doesn't remain blocked at the end of the scope
            results.emplace_back(std::move(new_task));
        }
        return results;
    }

    int RNG::give_random_int(int left, int right)
    {
        //init the twister
        std::uniform_int_distribution<int> int_dist(left, right);
        auto rand_int = int_dist(twister);
        return static_cast<int>(rand_int);
    };
} // namespace Futures
