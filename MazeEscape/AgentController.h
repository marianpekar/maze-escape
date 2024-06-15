#pragma once

#include <memory>

struct Node
{
    int x, y;
    int g, h, f;
    std::shared_ptr<Node> parent;
};

class AgentController
{
public:
    static void Move(const int& tx, const int& ty, class Actor& actor, const class Maze& maze);
    static int Heuristic(const int& sx, const int& sy, const int& tx, const int& ty);
};
