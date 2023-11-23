#include <iostream>

int main()
{
    int a = 1;
    int b = 2;
    int c = 3;

    int* pointer1 = &a;
    int* pointer2 = &b;
    int* pointer3 = &c;

    // 4 + 9 = 13
    *pointer1 = (2 * (*pointer2)) + (3 * (*pointer3));
    pointer1 = &b;
    pointer3 = &a;

    // 2 + 13
    *pointer2 = *pointer1 + *pointer3;

    std::cout << a << '\n'; // 13
    std::cout << *pointer1 << '\n'; // 15
    std::cout << *pointer2 << '\n'; // 15
    std::cout << *pointer3 << '\n'; // 13

    return 0;
}
