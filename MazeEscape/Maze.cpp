#include "Maze.h"
#include "Console.h"
#include "FractalBrownianMotion.h"
#include "Config.h"
#include <stack>

void Maze::Generate(const int& x, const int& y)
{
    data = std::vector(cfg->mazeWidth * cfg->mazeHeight, 1);

    using Point = std::pair<int, int>;
    std::stack<Point> stack;

    Open(x, y);

    stack.emplace(x, y);

    static constexpr int dx[] = {0, 1, 0, -1};
    static constexpr int dy[] = {-1, 0, 1, 0};

    while (!stack.empty())
    {
        const int cx = stack.top().first;
        const int cy = stack.top().second;
        stack.pop();
        directions.Shuffle();

        for (int i = 0; i < 4; ++i)
        {
            int nx = cx + dx[directions[i]] * 2;
            int ny = cy + dy[directions[i]] * 2;

            if (!IsValid(nx, ny))
                continue;

            if (data[nx + ny * cfg->mazeHeight] != 0)
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

void Maze::Open(const int& x, const int& y)
{
    data[x + y * cfg->mazeHeight] = 0;
}

void Maze::OpenRandom()
{
    static std::uniform_int_distribution dx(6, cfg->mazeHeight - 6);
    static std::uniform_int_distribution dy(6, cfg->mazeWidth - 6);

    for (int i = 0; i < cfg->wallHolesCount; i++)
    {
        int rx = dx(gen);
        int ry = dy(gen);
        if (IsOpen(rx, ry) || IsEdge(rx, ry))
        {
            i--;
            continue;
        }
        Open(rx, ry);
    }
}

bool Maze::IsEdge(const int& x, const int& y) const
{
    return x == 0 || x == cfg->mazeHeight - 2 || y == 0 || y == cfg->mazeWidth - 1;
}

void Maze::PlaceExit()
{
    const int ex = cfg->mazeHeight - 3;
    int ey = cfg->mazeWidth / 2;
    while (!IsOpen(ex, ey))
    {
        ey += 1;
    }
    Open(ex + 1, ey);
}

bool Maze::IsOpen(const int& x, const int& y) const
{
    return data[x + y * cfg->mazeHeight] < 1;
}

const int& Maze::At(const int& x, const int& y) const
{
    return data[x + y * cfg->mazeHeight];
}

void Maze::Draw(const Console& console, const FractalBrownianMotion* fbm) const
{
    console.MoveCursor(0, 0);
    for (int x = 0; x < cfg->mazeHeight - 1; x++)
    {
        for (int y = 0; y < cfg->mazeWidth - 1; y++)
        {
            const int at = At(x, y);
            if (at <= 0)
            {
                Console::Write(' ');
            }
            else if (at == 1)
            {
                FontColor color;
                if (fbm != nullptr)
                {
                    static int colors[]{cfg->noiseColor1, cfg->noiseColor2, cfg->noiseColor3, cfg->noiseColor4, cfg->noiseColor5};
                    const float sample = fbm->Sample(
                        static_cast<float>(x) * cfg->noiseScale,
                        static_cast<float>(y) * cfg->noiseScale / 2,
                        cfg->noiseOctaves,
                        cfg->noisePersistence, 0, 5);
                    color = static_cast<FontColor>(colors[static_cast<int>(sample)]);
                }
                else
                {
                    color = static_cast<FontColor>(cfg->wallColor);
                }

                console.Write(cfg->wallChar, color);
            }
        }
        Console::Write('\n');
    }
}

bool Maze::IsValid(const int& x, const int& y) const
{
    return x >= 0 && x < cfg->mazeHeight - 1 && y >= 0 && y < cfg->mazeWidth - 1;
}