#include <format>

#include "Console.h"
#include "Maze.h"
#include "Actor.h"
#include "AgentController.h"
#include "PlayerController.h"

int main(int argc, char* argv[])
{
    int width = 64;
    int height = 24;

    Console console;

    int scorePlayer = 0;
    int scoreBaba = 0;
    
    while(true)
    {
        Maze maze(width, height);
        maze.Draw(console);

        Actor player(1, 1, '@', Blue);
        player.Draw(console);

        Actor baba(width - 3, 1, 'B', Red);
        baba.Draw(console);

        console.MoveCursor((width / 2) - 12, height);
        console.Write(std::format("Player: {}", scorePlayer).c_str(), Blue);
        console.MoveCursor((width / 2) + 4, height);
        console.Write(std::format("Baba: {}", scoreBaba).c_str(), Red);

        while (true)
        {
            if (player.GetX() == baba.GetX() && player.GetY() == baba.GetY())
            {
                scoreBaba++;
                break;
            }

            if (player.GetY() == height - 2)
            {
                scorePlayer++;
                break;
            }
            
            PlayerController::GetInput(console, player, maze);    
            player.Draw(console);
        
            AgentController::Move(player.GetX(), player.GetY(), baba, maze);
            baba.Draw(console);
        }
    }
}
