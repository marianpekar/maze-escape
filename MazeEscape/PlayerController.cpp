#include "PlayerController.h"
#include "Actor.h"
#include "Maze.h"
#include "Console.h"

void PlayerController::GetInput(const Console& console, Actor& player, const Maze& maze)
{
    static int nx = player.GetX();
    static int ny = player.GetY();

    switch (console.GetKey())
    {
    case 119:
        ny--;
        break;
    case 115:
        ny++;
        break;
    case 97:
        nx--;
        break;
    case 100:
        nx++;
        break;
    default: ;
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