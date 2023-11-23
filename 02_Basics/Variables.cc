// File endings may also be .cpp (doens't matter)
// Variable Rules
// - name cannot start with number
// - name cannot contain whitespaces
// - name must be unique

#include <iostream>
#include <cstdint>
#include <array>
#include <vector>
#include <string>

int main()
{
    // Intro
    int someInteger = 2;
    float someFloat = 2.2;

    std::cout // "Console Object"
    << "Output: " // Shift something into it
    << someFloat // Shift more into it
    << std::endl; // Add line break a.k.a \n

    // ====
    // Number Types
    // ====

    // Actual sizes depend on operating system
    bool someBool = true; // 1 Byte - 1 Bit
    char someChar = 10; // 1 Byte - 8 Bit (2^8 = 256)
    short someShort = 300; // 2 Bytes - 16 Bit (2^16 = 65.000)
    int someInt = 100'00; // 4 Byte - 32 Bit (2^32 = 4.000.000.000) - use ' to make number more readable
    long long someLongLong = 5'000'000'000; // 8 Byte - 64 bit (2^64)

    float someFloat = 10.0; // 4 Bytes - 32 Bit
    double someDouble = 10.0; // 8 Bytes - 64 Bit

    // Crossplatform alternative Integers with Bit - Compiler selects the respective type
    std::uint8_t i = 1;
    std::uint16_t j = 1;
    std::int32_t k = 1;
    std::int64_t l = 1;

    // Without explicit namespace, convention dependent
    int8_t m = 1;
    int16_t n = 1;
    uint32_t o = 1;
    uint64_t p = 1;

    // ====
    // Character Types
    // Dependent on Englisj ASCII table
    // ====

    char letterA = 'A'; // char is a number and an ASCII character
    int aAsInt = (int)letterA; // 65

    // ====
    // Constants
    // Should be used every time a value will not be changed, for optimization reasons
    // "const" == Variable is not changed during RUNTIME, after it was initially assigned
    // "constexpr" == Expression is evaluated during COMPILETIME, only works with compile time information
    // Global consts have to be declared as static manually
    // ====

    const int FOO = 2;
    constexpr int BAR = 2 * 3 * 5;
    //constinit // Soon

    static int counter = 0; // Created once at compile time, heap vs stack

    // ====
    // Arrays
    // ====
    const std::size_t length = 10; // automatically determines most efficient data type (32 vs 64 bit etc)
    const std::array<std::int32_t, length> array1 = {};
    int length = array1.size();

    auto someVector = std::vector<std::int_fast32_t>(5, 0); // equivalent to List<T>
    for(const auto &val : someVector) // Foreach, with constant reference
        std::cout << val << std::endl;

    // ====
    // Strings
    // ====
    const std::string someString = "HAI GAIS!";
    int length = someString.length();

    const auto index = someString.find("GA");
    if(index == std::string::npos)
        std::cout << "Not Found!" << std::endl;


    return 0;
}
