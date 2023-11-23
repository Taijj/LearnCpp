#include <iostream>

// User Input: Length of one side of a square
// Output: perimeter and area of square.

int main()
{
    float side;
    std::cout << "Square side length: \n";
    std::cin >> side;

    // TODO: Error handling

    float perimeter = side*4;
    float area = side * side;

    std::cout << "A square which sides has a lenght of "
    << side
    << " has a perimeter of "
    << perimeter
    << " and an area of "
    << area
    << std::endl;
}
