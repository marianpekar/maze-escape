#include "Maze.h"
#include "Console.h"
#include <stack>

void Maze::Generate(const int& x, const int& y)
{
    data = std::vector(width * height, 1);

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

void Maze::OpenRandom()
{
    static std::uniform_int_distribution dx(6, height - 6);
    static std::uniform_int_distribution dy(6, width - 6);

    for (int i = 0; i < 12; i++)
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

void Maze::Draw(const Console& console, const FractalBrownianMotion& fbm)
{
    console.MoveCursor(0, 0);
    for (int x = 0; x < height - 1; x++)
    {
        for (int y = 0; y < width - 1; y++)
        {
            const int at = At(x, y);
            if (at <= 0)
            {
                Console::Write(' ');
            }
            else if (at == 1)
            {
                static constexpr FontColor colors[]{Gray, Green, Purple, Yellow, Aqua};
                static constexpr float noiseScale = 0.0004f;
                float sample = fbm.Sample(static_cast<float>(x) * noiseScale, static_cast<float>(y) * noiseScale / 2, 8, 32,0, 5);
                console.Write('#', colors[static_cast<FontColor>(sample)]);
            }
        }
        Console::Write('\n');
    }
}

bool Maze::IsValid(const int& x, const int& y) const
{
    return x >= 0 && x < height - 1 && y >= 0 && y < width - 1;
}
