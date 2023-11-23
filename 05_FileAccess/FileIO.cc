#include <iostream>
#include <fstream>
#include <string>

std::string Read(const std::string &path)
{
    std::string line;
    std::string text;

    std::ifstream inputFile;
    inputFile.open(path);

    if(inputFile.is_open())
    {
        while(std::getline(inputFile, line))
            text += line + '\n';
    }

    inputFile.close();

    std::cout << text << '\n';
    return text;
}

void Write(const std::string &path, const std::string &text)
{
    std::ofstream outputFile;
    outputFile.open(path);

    if(outputFile.is_open())
    {
        outputFile << text; // Replaces EVERYTHING
    }

    outputFile.close();
}

int main()
{
    const std::string path = "TextInput.txt";

    Write(path, Read(path) + "\nNEWSTUFF");

    return 0;
}
