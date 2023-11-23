#include <iostream>
#include <thread>
#include <cstdint>

void function1()
{
    const auto main_id = std::this_thread::get_id();
    std::cout << "Thread ID: " << main_id << '\n';
}

void function2(std::int32_t number)
{
    const auto main_id = std::this_thread::get_id();
    std::cout << "Thread ID: " << main_id << '\n';
    std::cout << "Number: " << number << '\n';
}

void function3(std::int32_t &number)
{
    const auto main_id = std::this_thread::get_id();
    std::cout << "Thread ID: " << main_id << '\n';
    std::cout << "Number: " << number << '\n';
}

int main()
{
    const auto main_id = std::this_thread::get_id();
    std::cout << "Main Thread ID: " << main_id << '\n';

    std::uint32_t number = 42;

    auto t1 = std::thread(function1); // calls function immediately
    auto t2 = std::thread(function2, number);
    auto t3 = std::thread(function3, std::ref(number)); // needed to pass parameter by reference to a thread
    if(t1.joinable())
        t1.join(); // "wait" for t1 to complete
    if(t2.joinable())
        t2.join();
    if(t3.joinable())
        t3.join();

    return 0;
}
