#include <iostream>

// Basically Generics
// Compiler automatically genereates needed methods/classes etc.
// Constraints also exist.
template <typename T>
T max(T a, T b)
{
    return a > b ? a : b;
}

/**
 * @brief This is a docs string
 *
 * @return Void
 */
int main()
{
    return 0;
}
