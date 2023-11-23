#include <iostream>
#include <string>

#include "exercise.h"

// Exercise 2
std::string_view get_oldest_friend(const Friends &friends)
{
    std::string result = friends.begin()->first; // Key friend name
    std::int32_t oldestAge = friends.begin()->second.first; // Age
    for(const auto &f : friends)
    {
        auto age = f.second.first;
        if(age > oldestAge)
        {
            oldestAge = age;
            result = f.first;
        }
    }
    return result;
}

std::string_view get_heaviest_friend(const Friends &friends)
{
    std::string result = friends.begin()->first; // Key friend name
    std::int32_t heaviestWeight = friends.begin()->second.second; // Weight
    for(const auto &f : friends)
    {
        auto weight = f.second.second;
        if(weight > heaviestWeight)
        {
            heaviestWeight = weight;
            result = f.first;
        }
    }
    return result;
}
