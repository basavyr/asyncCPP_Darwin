- The `std::async` is a C++11 and C++14 implementation that allows any functions to be executed out of the main thread (not all the time though), when specifically mentioned by the user.
- The async function returns a future. That is actually "an object" which will only start execution when the `.get()` method is called. This method is specific to all the futures.
- The class template std::future provides a mechanism to access the result of asynchronous operations:[["An asynchronous operation (created via" " " "[std::async](https://en.cppreference.com/w/cpp/thread/async)" "," " " "[std::packaged_task](https://en.cppreference.com/w/cpp/thread/packaged_task)" ", or" " " "[std::promise](https://en.cppreference.com/w/cpp/thread/promise)" ") can provide a" " " "std::future" " " "object to the creator of that asynchronous operation."]]Untitled
    - When the asynchronous operation is ready to send a result to the creator, it can do so by modifying __shared state__ (e.g. [std::promise::set_value](https://en.cppreference.com/w/cpp/thread/promise/set_value)) that is linked to the creator's std::future.
- If the std::future obtained from std::async is not moved from or bound to a reference, the destructor of the [std::future](https://en.cppreference.com/w/cpp/thread/future) will block at the end of the full expression until the asynchronous operation completes, essentially making code such as the following synchronous:
- std::async([std::launch::async](http://en.cppreference.com/w/cpp/thread/launch), []{ f(); }); // temporary's dtor waits for f()
std::async([std::launch::async](http://en.cppreference.com/w/cpp/thread/launch), []{ g(); }); // does not start until f() completes
- (note that the destructors of std::futures obtained by means other than a call to std::async never block)
- "The creator of the asynchronous operation can then use a variety of methods to query, wait for, or extract a value from the" " " "std::future" ". These methods may block if the asynchronous operation has not yet provided a value."
- In this GitHub repo, there is an asynchronous implementation that performs the generation of a *futures container* (e.g. a standard vector with futures as elements).
    - The futures are placed after a new task is created (and launched in `async` mode)
    - The key idea is that the created task (if declared locally within the current scope - as an lvalue) **must be moved** into the container, since the promise must be deleted at the end of the scope.

```c++
{
 	auto new_task=std::launch::async,function,arg);
	future_container.emplace_back(std::move(new_task));
	//move otherwise the compiler will fail to build the code
}
```