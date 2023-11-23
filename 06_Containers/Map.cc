#include <iostream>
#include <map>
#include <string>
#include <cstdint>

int main()
{
    std::map<std::string, std::uint32_t> map = {};
    map["Hoarst"] = 13;
    map["Mark"] = 12;
    map["Magdalena"] = 33;

    for(const auto &pair : map) // unordered
        std::cout << pair.first << " " << pair.second << '\n';

    // map.find() // Does Key exist C++ 17
    // map.contains() // Does Key exist C++ 20

    return 0;
}
