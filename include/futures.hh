#ifndef FUTURES_HH
#define FUTURES_HH

#include <iostream>
#include <thread>
#include <future>
#include <string>
#include <ctime>
#include <chrono>
#include <cmath>

//adds random generator for testing the future generator
#include <random>
namespace Futures
{
    class Future
    {
    public:
        static void threadID();
        static void sleep(int);
        static void slowLoop(int[], int);
        static void fastLoop(int[], int);
        static void fastStream(char, int);
        static void slowStream(char, int);

    public:
        void show();

    public:
        //the input function must be of int-type
        static std::vector<std::future<int>> generateFutures(size_t n_futures, int timer, int (*function)(int arg));
        static void newLine();
    };
    class RNG
    {
    private:
        static constexpr int seed = 1137; //use this seed for debug purposes

    public:
        static int give_random_int(int left, int right);
    };
} // namespace Futures

#endif // FUTURES_HH
