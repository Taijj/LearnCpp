#include <iostream>

void WriteToConsole(std::string text)
{
    std::cout << text;
}

int main()
{
    char left = 'a';
    char right = 'd';
    char up = 'w';
    char down = 's';
    char exit = 'x';

    WriteToConsole("MOVE!\n");
    while(true)
    {
        char input;
        std::cin >> input;

        if(input == exit)
            break;

        if(input == left)
            WriteToConsole("Moves Left\n");
        else if(input == right)
            WriteToConsole("Moves Right\n");
        else if(input == up)
            WriteToConsole("Moves Up\n");
        else if(input == down)
            WriteToConsole("Moves Down\n");
        else
            WriteToConsole("Invalid Input\n");
    }

    return 0;
}
