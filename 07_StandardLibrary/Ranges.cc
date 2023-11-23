#include <iostream>
#include <ranges>
#include <vector>

// Also reminds me of C# Linq
int main()
{
    auto numbers = std::vector<std::int32_t>{1, 2, 3, 4, 5, 6};

    auto results1 = numbers
     | std::views::transform([](const auto n) { return n * 3; })
     | std::views::filter([](const auto n) {return n % 2 == 0; });
    // results contains initial numbers multiplied by 3 which are even.

    // needs to be converted back to vector! E.g.
    auto results_vec = std::vector(results1.begin(), results1.end());

    // C++ 23
    // auto results_vec23 = std::ranges::to<std::vector>();



    return 0;
}
