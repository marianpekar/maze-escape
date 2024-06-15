#pragma once

class PlayerController
{
public:
    int nx{1};
    int ny{1};
    void Move(const class Console& console, class Actor& player, const class Maze& maze, const struct Config& cfg);
    void Reset();
};