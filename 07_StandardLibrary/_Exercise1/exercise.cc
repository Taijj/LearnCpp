#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>
#include <execution>

#include "exercise.h"

bool areEqual(const BinaryArray &target, const BinaryArray &input)
{
    return std::equal(std::execution::par,
     target.begin(), target.end(),
     input.begin());
}

// Exercise 2
std::vector<bool> shuffle_till_equal(const BinaryArray &target,
                                     BinaryArray input)
{
    while(!areEqual(target, input))
        std::random_shuffle(input.begin(), input.end());
    return input;
}

// Exercise 3
std::vector<bool> smart_shuffle_till_equal(const BinaryArray &target,
                                           BinaryArray input)
{
    for(std::size_t i = 0; i < target.size(); i++)
    {
        while(!areEqual(target, input))
        {
            if(target[i] == input[i])
                break;
            std::random_shuffle(input.begin() + i, input.end());
        }
    }
    return input;
}
