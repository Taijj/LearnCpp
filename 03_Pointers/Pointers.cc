#include <iostream>
#include <cstdint>

// This is the old C way of using pointers
void General()
{
    int* p = new int{4}; // Reserve new int with a value of 4 on the Heap
    *p = 4; // Write a value of 4 to the variable stored at pointer

    std::cout << "Adress of p: " << &p << "\n"; // Reference
    std::cout << "Address p points to: " << p << "\n";
    std::cout << "Value at p's address: " << *p << "\n"; // Dereference

    *p = 1337;

    std::cout << "Adress of p: " << &p << "\n";
    std::cout << "Address p points to: " << p << "\n";
    std::cout << "Value at p's address: " << *p << "\n"; // 1337

    // Release Memory at the address p points to, p still points though
    // p itself resides on the Stack and is managed automatically by scope
    delete p;
}


void NullPointer()
{
    auto* p = new std::int32_t{4}; // May also return a NullPointer, if no memory is available!

    // Otherwise the pointer still contains a "valid" value, which is total bogus.
    // This way the program will crash
    delete p;
    p = nullptr;

    if(p != nullptr) // Null check
    {
        std::cout << p << std::endl;
        std::cout << *p << std::endl;
    }
}

// Arrays passed as parameters are "decaying" into pointers, which is the reason I have to handle
// array size manually
void ArrayPointers()
{
    auto array_size = std::size_t{10};
    auto* array = new std::int32_t[array_size]; // Allocate memory for multiple elements

    for(std::size_t i = 0; i < array_size; i++)
        array[i] = i;

    for(std::size_t i = 0; i < array_size; i++)
        std::cout << array[i] << std::endl;

    delete[] array; // Release ALL memory, without the braces only the first element is deallocated
}



int main()
{
    ArrayPointers();
    return 0;
}
