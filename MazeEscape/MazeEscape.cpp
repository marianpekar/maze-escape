#include <iostream>

#include "Console.h"
#include "Maze.h"
#include "Actor.h"

int main(int argc, char* argv[])
{
    size_t width = 64;
    size_t height = 24;

    Console console;

    Maze maze(width, height);
    maze.Draw(console);

    Actor player(1, 1, '@');
    player.Draw(console);

    short nx = player.GetX();
    short ny = player.GetY();
    while (true)
    {
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
        }

        if (maze.IsOpen(ny, nx))
        {
            player.Move(nx,ny);
            player.Draw(console);
        }
        else
        {
            nx = player.GetX();
            ny = player.GetY();
        }
    }

    std::cin.get();

    return 0;
}