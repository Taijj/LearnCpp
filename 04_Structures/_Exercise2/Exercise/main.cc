#include <iostream>

#include "exercise.h"

void LogPosition(PlayerData &data)
{
    std::cout << "Position of Player "
     << data.id
     << ": {" << data.x_pos << ", "
     << data.y_pos <<"}\n";
}

int main()
{
    PlayerData Tobey = {
        .id = 1,
        .x_pos = 1.5,
        .y_pos = 2.5,
        .health = 10,
        .energy = 9001,
        .team = Team::ALLIED
    };

    PlayerData Abe = {
        .id = 12,
        .x_pos = 10,
        .y_pos = -5,
        .health = 0,
        .energy = 13,
        .team = Team::ENEMY
    };

    LogPosition(Tobey);
    LogPosition(Abe);
    return 0;
}
