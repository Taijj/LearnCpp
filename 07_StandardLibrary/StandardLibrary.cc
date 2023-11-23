#include <iostream>
#include <cstdint>
#include <vector>
#include <random>
#include <chrono>
#include <execution>
#include <limits>
#include <cmath>

constexpr static auto NUM_ELEMENTS = 1'000'000U;
using Elements = std::vector<std::int32_t>;

using Clock = std::chrono::steady_clock;
using TimeUnit = std::chrono::milliseconds;



void Random(Elements &elements, bool logToConsole = false)
{
    // Could also be extracted as a "Generator" method, with making these static
    // so they are only created ones with std::generate() or std::transform()
    // Algorithm Header provides more utility that remind me of C# System.Linq
    auto seed = std::random_device{}; // Physical Random number
    auto generator = std::mt19937{seed()}; // Create Random Generator with seed
    auto distribution = std::uniform_int_distribution<std::int32_t>{-10, 10}; // Distribution definition

    for(std::size_t i = 0; i < elements.size(); ++i)
    {
        elements[i] = distribution(generator); // Generates a random number between -10 and 10

        if(logToConsole && i < 10)
            std::cout << elements[i] << '\n';
    }
}

void Chrono(Elements &elements)
{
    //Use Steady Clock for actual CPU time measurements (system_clock)

    const auto start_time = Clock::now();
    Random(elements);
    const auto end_time = Clock::now();
    const auto elapsedTime = std::chrono::duration_cast<TimeUnit>(end_time - start_time).count();

    std::cout << "Elapsed Time: " << elapsedTime << '\n';
}

void Limits()
{
    // Float and Double comparison, a.k.a. "almost equal"
    double x = 10.2;
    double y = 10.33;
    bool areAlmostEqual = std::abs(x - y) <= std::numeric_limits<double>::epsilon();
    std::cout << areAlmostEqual << '\n';
    std::cout.precision(17); // Define how precisely numbers should be roundend in console
}

int main()
{
    // Random
    auto my_vector = Elements(NUM_ELEMENTS, 0U);

    // Random(my_vector, true);
    // Chrono(my_vector);

    // In Numeric Header
    // Accumulate & Reduce - do basically the same, but Reduce has a parallel option and might change order
    std::reduce(my_vector.begin(), my_vector.end(), 2); // sums up whole vector and adds 2
    std::reduce(std::execution::par, my_vector.begin(), my_vector.end(), 0); // the same in parallel and add 0 in the end
    // std::accumulate(my_vector.begin(), my_vector.end(), 0, <Method>) // Also works with custom methods
    // std::execution::par <- try to always use, if available

    // There are many more...


    // std::function<TReturn(Params)> shorter: std::function<FunctionSignature>

    return 0;
}
