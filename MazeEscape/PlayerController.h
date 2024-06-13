#pragma once

class PlayerController
{
public:
    int nx{1};
    int ny{1};
    void GetInput(const class Console& console, class Actor& player, const class Maze& maze);
    void Reset();
};
