#include <cstdint>
#include <iostream>

#include "exercise2.h"

// Exercise 1
void push_back(std::int32_t* &input_array,
               const std::size_t size,
               const std::int32_t value)
{
    std::size_t newLength = size+1;
    auto* newArray = new std::int32_t[newLength];
    for(std::size_t i = 0; i < size; i++)
        newArray[i] = input_array[i];
    newArray[size] = value;

    delete[] input_array;
    input_array = newArray;
}

// Exercise 2
void pop_back(std::int32_t* &input_array, const std::size_t size)
{
    std::size_t newLength = size-1;
    auto* newArray = new std::int32_t[newLength];
    for(std::size_t i = 0; i < newLength; i++)
        newArray[i] = input_array[i];

    delete[] input_array;
    input_array = newArray;
}
