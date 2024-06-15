#include "PlayerController.h"
#include "Actor.h"
#include "Maze.h"
#include "Console.h"
#include "Config.h"

void PlayerController::Move(const Console& console, Actor& player, const Maze& maze, const Config& cfg)
{
    nx = player.GetX();
    ny = player.GetY();

    int key = console.GetKey();
    if (key == static_cast<int>(cfg.keyUp))
    {
        ny--;
    }
    else if (key == static_cast<int>(cfg.keyDown))
    {
        ny++;
    }
    else if (key == static_cast<int>(cfg.keyLeft))
    {
        nx--;
    }
    else if (key == static_cast<int>(cfg.keyRight))
    {
        nx++;
    }
    else if (key == static_cast<int>(cfg.forfeitKey))
    {
        player.Forfeit();
        return;
    }

    if (maze.IsOpen(ny, nx))
    {
        player.Move(nx, ny);
    }
    else
    {
        nx = player.GetX();
        ny = player.GetY();
    }
}

void PlayerController::Reset()
{
    nx = ny = 1;
}