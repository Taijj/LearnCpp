#include <fstream>
#include <iostream>
#include <string>

struct PlayerData
{
    std::uint32_t id;
    float x;
    float y;
};

void PrintPlayerPos(const PlayerData &player)
{
    std::cout << "Pos: (" << player.x << ", " << player.y << ")\n";
}

int AppendTo(const std::string &line, const std::string path)
{
    std::ofstream file;
    file.open(path, std::ios::out | std::ios::app); // flags: open as output and append
    if(file.fail())
        return 1;

    file << line << '\n';

    if(file.good() == false)
        return 1;

    file.close();
    return 0;
}

int WriteBin(const PlayerData data, const std::string &filePath)
{
    std::ofstream file;
    file.open(filePath, std::ios::out | std::ios::binary); // flags again
    if(file.fail())
        return 1;

    // C style cast from PlayerData to char pointer,
    // Pointer to start of structure with byte size
    file.write((char*)&data, sizeof(PlayerData));
    file.close();
    return 0;
}

int ReadBin(const PlayerData &data, const std::string &filePath)
{
    std::ifstream file;

    file.open(filePath, std::ios::in | std::ios::binary);
    if(file.fail())
        return 1;

    file.read((char*)&data, sizeof(PlayerData)); // 12 Byte

    if(!file.good())
        return 1;
    return 0;
}

int main()
{
    const std::string text = "I mog nimma!";
    const std::string fileName1 = "TextAppend.txt";
    AppendTo(text, fileName1);

    const PlayerData writePlayer = {.id = 0, .x = 10.0f, .y = 110.0f};
    const std::string fileName2 = "text.bin";
    WriteBin(writePlayer, fileName2);

    const PlayerData readPlayer = {};
    ReadBin(readPlayer, fileName2);
    PrintPlayerPos(readPlayer);

    return 0;
}
