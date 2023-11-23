#include <iostream>
#include <tuple>
#include <utility>
#include <string>

std::tuple<int, std::string, double> Foo()
{
    return std::make_tuple(1337, "data", 42.0);
}

int main()
{
    std::pair<float, int> somePair = {1337, -25.0f};
    std::cout << somePair.first << " " << somePair.second << '\n';

    std::tuple<float, int, std::string> someTuple = {1337, -25.0f, "Horst"};
    std::cout << std::get<0>(someTuple) << " " << std::get<1>(someTuple) << " " << std::get<2>(someTuple) << '\n';

    const auto [id, name, score] = Foo(); // Structured Binding again
    std::cout << id << ", " << name << ", " << score << '\n';

    return 0;
}
