#include <iostream>
#include <filesystem>

// A standard when using the FileSystem Library
namespace fs = std::filesystem;

int main()
{
    fs::path projectPath = "P:/Cpp/Self";
    fs::path chapterPath = projectPath;
    chapterPath /= "05_FileAccess"; // Automatically uses right slash for OS

    std::cout << projectPath << '\n';
    std::cout << chapterPath << '\n';

    fs::path currentFilePath = fs::current_path(); // Path to this script file;
    std::cout << currentFilePath << '\n';

    // fs::path has all kinds of quality of life methods for path handling

    // Noteworthy
    fs::directory_iterator iterator; // for iterationg over directories
    fs::exists(""); // file/directory exists
    fs::create_directory(""); // create directory
    fs::copy_file("", ""); // from, to
}
