#include "../include/futures.hh"
#include <iostream>
#include <thread>
#include <future>
#include <string>
#include <ctime>
#include <chrono>

namespace Futures
{
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
    Futures::threadID();
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
    Futures::threadID();
}

void Future::fastStream(char s, int ms)
{
    for (int i = 0; i < 50; ++i)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
        std::cout << s;
    }
    Futures::threadID();
}

void Future::slowStream(char s, int ms)
{
    for (int i = 0; i < 50; ++i)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
        std::cout << s;
    }
    Futures::threadID();
}

void threadID()
{
    // const std::string scope = "In namespace";
    // const std::string message = "The function is running on the thread ID: ";
    // std::cout << scope;
    // newLine();
    // std::cout << message;
    // newLine();
    std::cout << std::this_thread::get_id();
    newLine();
}
void newLine()
{
    std::cout << "\n";
}

} // namespace Futures
