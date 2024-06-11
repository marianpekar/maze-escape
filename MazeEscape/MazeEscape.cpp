#include <iostream>

#include "Console.h"
#include "Maze.h"
#include "Actor.h"
#include "PlayerController.h"

int main(int argc, char* argv[])
{
    size_t width = 64;
    size_t height = 24;

    Console console;

    Maze maze(width, height);
    maze.Draw(console);

    Actor player(1, 1, '@');
    player.Draw(console);

    while (true)
    {
        PlayerController::GetInput(console, player, maze);    
        player.Draw(console);
    }
    
}
