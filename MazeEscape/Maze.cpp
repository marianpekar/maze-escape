#include "Maze.h"
#include "Console.h"

#include <stack>

Maze::Maze(const int w, const int h) : data(std::vector(w * h, 1)), width(w), height(h)
{
    Generate(1, 1);
}

void Maze::OpenRandom()
{
    static std::uniform_int_distribution dx(6, height - 6);
    static std::uniform_int_distribution dy(6, width - 6);

    for (int i = 0; i < 10; i++)
    {
        int rx = dx(gen);
        int ry = dy(gen);
        while (IsOpen(rx, ry))
        {
            rx -= 1;
            ry += 1;
        }
        Open(rx, ry);
    }
}

void Maze::Generate(const int& x, const int& y)
{
    using Point = std::pair<int, int>;
    std::stack<Point> stack;

    Open(x, y);

    stack.emplace(x, y);

    static constexpr int dx[] = {0, 1, 0, -1};
    static constexpr int dy[] = {-1, 0, 1, 0};

    while (!stack.empty())
    {
        int cx = stack.top().first;
        int cy = stack.top().second;
        stack.pop();
        directions.Shuffle();

        for (int i = 0; i < 4; ++i)
        {
            int nx = cx + dx[directions[i]] * 2;
            int ny = cy + dy[directions[i]] * 2;

            if (!IsValid(nx, ny))
                continue;

            if (data[nx + ny * height] != 0)
            {
                Open((nx + cx) / 2, (ny + cy) / 2);
                Open(nx, ny);
                stack.emplace(nx, ny);
            }
        }
    }

    OpenRandom();
    PlaceExit();
}

void Maze::PlaceExit()
{
    const int ex = height - 3;
    int ey = width / 2;
    while (!IsOpen(ex, ey))
    {
        ey += 1;
    }
    Open(ex + 1, ey);
}

void Maze::Draw(const Console& console) const
{
    console.MoveCursor(0, 0);
    for (int x = 0; x < height - 1; x++)
    {
        for (int y = 0; y < width - 1; y++)
        {
            console.Write(At(x, y) == 1 ? '#' : ' ', Green);
        }
        Console::Write('\n');
    }
}

bool Maze::IsValid(const int& x, const int& y) const
{
    return x >= 0 && x < height - 1 && y >= 0 && y < width - 1;
}
