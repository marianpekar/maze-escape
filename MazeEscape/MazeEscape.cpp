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

    Maze maze(width, height);
    maze.Draw(console);

    Actor player(1, 1, '@', Blue);
    player.Draw(console);

    Actor baba(width - 3, 1, 'B', Red);
    baba.Draw(console);

    while (true)
    {
        PlayerController::GetInput(console, player, maze);    
        player.Draw(console);
        
        AgentController::Move(player.GetX(), player.GetY(), baba, maze);
        baba.Draw(console);
    }
}
