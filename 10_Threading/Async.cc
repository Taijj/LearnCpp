#include <future>
#include <iostream>

int function (const int input)
{
    std::cout << input << '\n';
    return input*2;
}

int main()
{
    int input = 1;

    // usually used for io heavy stuff, e.g. downloads
    //
    auto handle = std::async( // returns an std::future<int> dependent on funciton return type, a.k.a a handle
        std::launch::async, // Laucnh policy - in this case starts a thread
        function, // function to call asynchronously
        input); //function parameters

    // ...

    // Get value, wait if not available, yet
    auto result = handle.get();
    std::cout << result << '\n';

    return 0;
}
