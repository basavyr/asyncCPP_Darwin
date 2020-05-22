#include "../include/futures.hh"
#include "../include/threads.hh"

#include <memory>
// #include<utility>
// #include <functional>

//! OLD routine using future library
// int main()
// {
//     // Futures::Future::threadID();
//     // Futures::threadID();
//     //Futures::Future::sleep(2);
//     int myarray[5] = {1, 2, 3, 4, 5};
//     //Futures::Future::fastLoop(myarray, 5);
//     //Futures::Future::slowLoop(myarray, 5);
//     Futures::threadID();
//     std::future<void> f1 = std::async(std::launch::deferred, Futures::Future::fastStream, '-', 100);
//     std::future<void> f2 = std::async(std::launch::async, Futures::Future::slowStream, '*', 200);
//     // f1.get();
//     // f2.get();
// }

//? updated routine running code @ 22 May 2020
int main()
{
    std::vector<double> my_vector{};
    auto x = std::make_unique<threads::Threads>(1, 4.3, 20, my_vector);
}
