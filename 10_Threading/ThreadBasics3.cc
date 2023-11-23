#include <array>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <thread>
#include <mutex>

namespace
{
    const static auto NUM_THREADS = std::uint32_t{3U};

    auto GLOBAL_COUNTER = std::uint32_t{0};
    auto MUTEX_COUNTER = std::mutex{};
    const static auto NUM_INCREMENTS = std::uint32_t{100'000};
}

void function (const std::int_fast32_t input, std::int32_t &output)
{
    output = input*2;

    auto localCounter = 0;
    for(std::uint32_t i = 0; i < NUM_INCREMENTS; ++i)
        ++localCounter;

    // Thread safety
    auto guard = std::lock_guard<std::mutex>(MUTEX_COUNTER);
    GLOBAL_COUNTER += localCounter;
}

int main()
{
    std::array<std::thread, NUM_THREADS> threads; // old syntax, won't creat anything, yet

    auto inputs = std::array<std::int32_t, NUM_THREADS>{};
    auto outputs = std::array<std::int32_t, NUM_THREADS>{};
    std::iota(inputs.begin(), inputs.end(), 0);

    for(std::uint32_t i = 0; i < NUM_THREADS; ++i)
        threads[i] = std::thread(function, inputs[i], std::ref(outputs[i]));

    //...

    for(std::uint32_t i = 0; i < NUM_THREADS; ++i)
    {
        if(threads[i].joinable())
            threads[i].join();
    }

    for(std::uint32_t i = 0; i < NUM_THREADS; ++i)
    {
        std::cout << "Input: " << inputs[i] << " and output: " << outputs[i] << '\n';
    }
    return 0;
}
