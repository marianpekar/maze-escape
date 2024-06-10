#include <iostream>

#include "Console.h"
#include "Maze.h"
#include "Player.h"

int main(int argc, char* argv[])
{
    size_t width = 24;
    size_t height = 48;

    Console console;

    while (true)
    {
        Maze maze(width, height);
        maze.Draw(console);
        
        Player player(1, 1);
        player.Draw(console);
        std::cin.get();
    }


    return 0;
}
