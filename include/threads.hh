#ifndef THREADS_HH
#define THREADS_HH

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <future>

namespace threads
{
    class Threads
    {
    private:
        int n;
        double r;
        size_t size;
        std::vector<double> container;
        /* data */
    public:
        Threads(/* args */);
        Threads(int, double, size_t, std::vector<double> &);
        ~Threads();
    };

} // namespace threads

#endif // THREADS_HH
