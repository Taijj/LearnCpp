#include <iostream>
#include <vector>

struct Data
{
    float x;
    float y;
};

// C Approach Alias - order dependent
// typedef std::vector<Data> AllData;

// C++ Approach Alias
using AllData = std::vector<Data>;

int main()
{
    auto vector = AllData{
      Data {1.0f, 2.0f},
      Data{4.0f, 6.0f} };

    for(const auto &[_x, _y] : vector) // Structured Binding, & == Reference
        std::cout << _x << " " << _y << std::endl;

    return 0;
}
