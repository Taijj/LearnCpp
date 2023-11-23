#include <iostream>
#include <string>

// Variadic: Unknown number of parameters

// Pre C++ 17 weird recursion
// template <typename T>
// T concat(T first)
// {
//     return first;
// }

// template <typename T, typename... Args>
// T concat(T first, Args... args)
// {
//     return first + concat(args...);
// }

// Post C++ 17 Fold Expression
template <typename T, typename... Args>
T concat(Args... args)
{
    // Special care needs to be taken with different operators
    // e.g. division
    return (args + ...); // Fold
}



int main()
{
    std::string s1 = "Ha";
    std::string s2 = "ll";
    std::string s3 = "o";

    std::cout << concat<std::string>(s1, s2, s3) << std::endl; // "Hallo"
    std::cout << concat<int>(2, 3, 4) << std:: endl; // 9

    return 0;
}
