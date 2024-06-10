#include "Maze.h"

#include <algorithm>
#include <random>

void Maze::Directions::Shuffle()
{
    std::mt19937 g(rd());
    std::ranges::shuffle(data, g);
}

Maze::Maze(const size_t w, const size_t h) : data(std::vector(w * h, 1)), width(w), height(h)
{
    Dig(1, 1);
}

void Maze::Dig(const size_t x, const size_t y)
{
    directions.Shuffle();

    for (size_t i = 0; i < 4; i++)
    {
        switch (directions[i])
        {
        case 0: // Up
            if (x + 3 >= width || IsOpen(x + 2, y))
                continue;

            Open(x + 2, y);
            Open(x + 1, y);
            Dig(x + 2, y);
            break;

        case 1: // Right
            if (y + 3 >= height || IsOpen(x, y + 2))
                continue;

            Open(x, y + 2);
            Open(x, y + 1);
            Dig(x, y + 2);
            break;

        case 2: // Down
            if (x <= 2 || IsOpen(x - 2, y))
                continue;

            Open(x - 2, y);
            Open(x - 1, y);
            Dig(x - 2, y);
            break;

        case 3: // Left
            if (y <= 2 || IsOpen(x, y - 2))
                continue;

            Open(x, y - 2);
            Open(x, y - 1);
            Dig(x, y - 2);
            break;

        default:
            break;
        }
    }
}
