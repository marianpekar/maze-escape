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
    static void Move(int tx, int ty, class Actor& actor, const class Maze& maze);
    static int Heuristic(int sx, int sy, int tx, int ty);
};
