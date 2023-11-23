#pragma once
#include <cstdint>

enum class Team
{
    ALLIED,
    ENEMY
};

struct PlayerData
{
    std::uint32_t id;
    float x_pos;
    float y_pos;
    uint32_t health;
    uint32_t energy;
    Team team;
};
