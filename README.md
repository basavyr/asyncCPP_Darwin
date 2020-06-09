# Asynchronous programming in `C++`

Testing Asynchronous CPP programming on macOS Catalina. Using `std::future` and `std::async` libraries to perform thread computations.

[This project](https://github.com/basavyr/useful-cpp-algorithms/tree/master/projects/asyncxx) contains an additional implementation dedicated to asynchronous programming.

## Previous patch

___

> ## Update **May 2020**

1. Restructures the project
   1. adds `include` and `src` dirs.
   2. adds extra `threads` namespace, for computing data within the `Threads` class.
2. Implements `CMake` configuration for building the project
3. Adds documentation for the project.
4. Implements run-time scripts for both `future` and `threads` sources.

> ## Update **June 2020**

* Uses different routines that are converted into *futures*
* The user can choose to generate an arbitrary number of futures (tasks) and then `get` them via the `future.get()` implementation
* Different functions are launched in `async` mode.
* Implements random function for testing (with `random)`
* Uses the `move` operator for putting futures into a container, since compiler will complain if copied (promises must be destroyed at the end of the scope).

More research can be found on the Roam Research page dedicated to [*Asynchronous Programming in C++*](sources/AsyncfunctionsC++.md).

## Docs

[here](./sources/docs.md)

Promises

![here](./sources/promise.png)