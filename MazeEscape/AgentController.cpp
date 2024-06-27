#include "AgentController.h"
#include "Actor.h"
#include "Maze.h"

#include <algorithm>
#include <cmath>
#include <vector>

void AgentController::Move(const int tx, const int ty, Actor& actor, const Maze& maze)
{
    if (actor.GetX() == tx && actor.GetY() == ty)
        return;

    const int& sx = actor.GetX();
    const int& sy = actor.GetY();

    static constexpr int dx[] = {0, 1, 0, -1};
    static constexpr int dy[] = {-1, 0, 1, 0};

    std::vector<std::shared_ptr<Node>> open, closed;

    const std::shared_ptr<Node> startNode = std::make_shared<Node>(Node{sx, sy, 0, Heuristic(sx, sy, tx, ty), 0, nullptr});
    open.push_back(startNode);

    while (!open.empty())
    {
        std::shared_ptr<Node> currentNode = *std::ranges::min_element(open, [](const std::shared_ptr<Node>& lhs, const std::shared_ptr<Node>& rhs)
        {
            return lhs->f < rhs->f;
        });

        std::erase(open, currentNode);
        closed.push_back(currentNode);

        if (currentNode->x == tx && currentNode->y == ty)
        {
            while (currentNode->parent->parent != nullptr)
            {
                currentNode = currentNode->parent;
            }

            actor.Move(currentNode->x, currentNode->y);
            return;
        }

        for (int i = 0; i < 4; ++i)
        {
            int nx = currentNode->x + dx[i];
            int ny = currentNode->y + dy[i];

            if (!maze.IsValid(ny, nx) || !maze.IsOpen(ny, nx))
                continue;

            if (!std::ranges::none_of(closed, [nx, ny](const std::shared_ptr<Node>& node)
            {
                return node->x == nx && node->y == ny;
            }))
            {
                continue;
            }

            std::shared_ptr<Node> neighborNode = std::make_shared<Node>(Node{nx, ny, currentNode->g + 1, Heuristic(nx, ny, tx, ty), 0, currentNode});
            neighborNode->f = neighborNode->g + neighborNode->h;
            open.push_back(neighborNode);
        }
    }
}

int AgentController::Heuristic(const int sx, const int sy, const int tx, const int ty)
{
    return std::abs(sx - tx) + std::abs(sy - ty);
}