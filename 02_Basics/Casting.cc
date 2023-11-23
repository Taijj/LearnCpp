#include <iostream>

void casting()
{
    // Avoid implicit casting like this:
    int a = 1;
    float b = a;

    // C Type Casting - AVOID!
    // C++ Type Casting static_cast<newType>(varName) <- compiler save:
    float c = static_cast<float>(a);
    double d = 12.3;
    float e = static_cast<float>(d);
}

void autoKeyword()
{
    // Basically "var"
    auto b = 12U;

    // Uniform Initialization
    float k = 12.3;
    int l = int{k}; // <- Only case where a "to lower" compiler warning will be generated!
}
