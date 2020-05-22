#include "../include/threads.hh"

static void print_array(const std::vector<double> &arr, std::chrono::milliseconds secs)
{
    for (auto &&n : arr)
    {
        std::cout << n << "\n";
        auto thread = std::this_thread::get_id();
        std::this_thread::sleep_for(secs);
        // std::cout << thread << '\n';
    }
    std::cout << '\n';
}

threads::Threads::Threads() : n(1), size(0), r(0.0), container({})
{
    std::cout << "in class..." << '\n';
}

threads::Threads::Threads(int number, double rnumber, size_t arrsize, std::vector<double> &container) : n(number), r(rnumber), size(arrsize)
{
    std::cout << "in class (overloaded)..." << '\n';
    for (auto i = 0; i < size; ++i)
    {
        container.emplace_back(rnumber);
    }
    std::chrono::milliseconds mini_secs(1500);
    std::chrono::seconds secs(n); //*transfrom from an int to time for threading operations
    print_array(container, mini_secs);
}

threads::Threads::~Threads()
{
    std::this_thread::sleep_for(std::chrono::seconds(n));
}