#include <cstdint>
#include <iostream>

#include "exercise.h"

namespace computation
{
    // Exercise 1
    double mean_array_value(int* array, const std::size_t length)
    {
        double sum = 0.0f;
        for(int i = 0; i < length; ++i)
            sum += array[i];

        return sum/length;
    }

    double mean_array_value(double* array, const std::size_t length)
    {
        double sum = 0.0f;
        for(int i = 0; i < length; ++i)
            sum += array[i];

        return sum/length;
    }

} // namespace computation
