
#include <iostream>

#include "Console.h"
#include "Maze.h"

int main(int argc, char* argv[])
{
    size_t width = 24;
    size_t height = 48;
    
    Console console;

    while (true)
    {
        Maze maze(width,height);
    
        for(size_t x = 0; x < width - 1; x++)
        {
            for(size_t y = 0; y < height - 1; y++)
            {
                console.Write(maze.At(x, y) == 1 ? '$' : ' ', Yellow);
            }
            console.Write('\n');
        }
        console.Write('\n');

        std::cin.get(); 
        console.Clear();
    }

    return 0;

}
