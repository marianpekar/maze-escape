#include "Maze.h"

#include <random>
#include <stack>

Maze::Maze(const size_t w, const size_t h) : data(std::vector(w * h, 1)), width(w), height(h)
{
    Generate(1, 1);
}

void Maze::Generate(size_t x, size_t y)
{
    using Point = std::pair<int, int>;
    std::stack<Point> stack;

    Open(x, y);

    stack.emplace(x, y);

    static constexpr int dx[] = {0, 1, 0, -1};
    static constexpr int dy[] = {-1, 0, 1, 0};

    while (!stack.empty())
    {
        int x = stack.top().first;
        int y = stack.top().second;
        stack.pop();
        directions.Shuffle();

        for (size_t i = 0; i < 4; ++i)
        {
            int nx = x + dx[directions[i]] * 2;
            int ny = y + dy[directions[i]] * 2;

            if (nx <= 0 || nx >= width - 1 || ny <= 0 || ny >= height - 1)
                continue;

            if (data[nx + ny * width] != 0)
            {
                Open((nx + x) / 2, (ny + y) / 2);
                Open(nx, ny);
                stack.emplace(nx, ny);
            }
        }
    }
}
