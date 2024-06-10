
#include <iostream>

#include "Console.h"
#include "Maze.h"

int main(int argc, char* argv[])
{
    size_t width = 16;
    size_t height = 32;
    
    Console console;
    
    Maze maze(width,height);

    for(size_t x = 0; x < width - 1; x++)
    {
        for(size_t y = 0; y < height - 1; y++)
        {
            console.Write(maze.At(x, y) == 1 ? '#' : ' ', Yellow);
        }
        console.Write('\n');
    }
    
    return 0;
}
