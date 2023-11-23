#include <cstdint>
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

using namespace std::chrono_literals;

namespace
{
    const static auto NUM_THREADS = std::uint32_t{3U};
}

void function(const std::stop_token token, std::int32_t value)
{
    const auto thread_id = std::this_thread::get_id();
    const std::stop_callback callback(token, [thread_id] {
        std::cout << "Stop requested for: " << thread_id << '\n'; // when thread stopped
    });

    while (!token.stop_requested())
    {
        std::cout << value++ << ' ' << std::flush;
        std::this_thread::sleep_for(200ms);
    }
}

int main()
{
    std::vector<std::jthread> threads(NUM_THREADS); // auto joining threads (c++20)
    for( auto &thread : threads)
        thread = std::jthread(function, 5); // stop token is passed implicitly

    std::this_thread::sleep_for(1s);

    std::cout << '\n';
    for( auto &thread : threads)
    {
        std::cout << "Requests stop for " << thread.get_id() << '\n';
        thread.request_stop();
    }

    std::cout << "Destructor starts\n";
    return 0;
}
