#include <iostream>
#include <string>

bool IsPalindrom(std::string_view text)
{
    for(std::size_t i = 0; i < text.length(); ++i)
    {
        if(text[i] != text[text.length()-1-i])
            return false;
    }
    return true;
}

int main()
{
    const std::string text = "Tobiatsch";
    const bool isPalindrom = IsPalindrom(text);

    std::cout << "\"" << text << "\" is a Palindrom? " << std::boolalpha << isPalindrom << '\n';
    return 0;
}
