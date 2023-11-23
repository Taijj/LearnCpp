#include <iostream>
#include <string>

void print_found_index(const std::size_t index, const std::string &methodName)
{
    std::cout << "Method: " << methodName << '\n';
    if(index != std::string::npos)
        std::cout << "Found at index: " << index << '\n';
    else
        std::cout << "Not Found!" << index << '\n';
}

void FindMethods(const std::string &text)
{
    const std::string search1 = "Drei";
    const std::size_t index1 = text.find(search1, 5); // Find first, starting at 5, workd for the following, too.
    print_found_index(index1, "find");

    const std::string search2 = "i";
    const std::size_t index2 = text.rfind(search2); // Find last
    print_found_index(index2, "rfind");

    const std::string search3 = "ZD";
    const std::size_t index3 = text.find_first_of(search3); // Find first of either
    print_found_index(index3, "rfind");

    const std::string search4 = "ZD";
    const std::size_t index4 = text.find_last_of(search4); // Find first of either
    print_found_index(index4, "rfind");
}

void Substringing(const std::string &text)
{
    std::string input = text;
    std::cout << "Input: " << input << '\n';
    input.clear(); // Empty string
    std::cout << "Input: " << input << '\n';

    // Concatenate
    std::string concat1 = text + ", Vier";
    std::cout << "Other: " << concat1 << '\n';

    std::string concat2 = concat1;
    concat2.append( {',', ' ', 'F', 'u', 'e', 'n', 'f'} );
    std::cout << "Other: " << concat2 << '\n';

    // Comparisons
    std::string compare1 = "Tobey";
    std::string compare2 = "Tobiatsch";

    std::cout << "1 == 2: " << std::boolalpha << (compare1 == compare2) << '\n'; // Case sensitive
    int compareValue = compare1.compare(compare2); // 0 == Equal, otherwise difference in ASCIIvalues
    std::cout << "Equality: " << compareValue << '\n';

    // Substr, Replace
    std::string substring = compare2.substr(5, 4); // "tsch"
    const std::size_t subIndex = compare2.find(substring);
    if(subIndex != std::string::npos)
        compare2.replace(subIndex, substring.size(), "REPLACED");

    std::cout << "Other: " << compare2 << '\n';
}

void Iterations(const std::string &text)
{
    char firstCharacter = text[0];
    std::cout << "First: " << firstCharacter << '\n';

    for(auto it = text.begin(); it != text.end(); ++it)
        std::cout << *it;
    std::cout << "\n\n";

    for(const char c : text)
        std::cout << c;
    std::cout << "\n\n";

    for(auto it = text.rbegin(); it != text.rend(); ++it) // r == reverse
        std::cout << *it;
    std::cout << "\n\n";

    const float value = 12.03f;
    const std::string valueString = std::to_string(value);
    std::cout << valueString << '\n';
}

int main()
{
    const std::string text = "Eins, Zwei, Drei";

    //FindMethods(text);
    //Substringing(text);
    Iterations(text);

    return 0;
}
