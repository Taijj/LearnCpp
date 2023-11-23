#include <cstdlib>
#include <iostream>

// argc: argument count
// argv: argument values
int main(int argc, char** argv) // ** 2D pointer decayed array
{
    for (int i = 0; i < argc; ++i)
        std::cout << argv[i] << std::endl;

    if(argc > 1)
        int argValue = std::atoi(argv[1]); // "Array to Integer"
    return 0;
}
