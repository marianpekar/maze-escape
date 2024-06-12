#include "Console.h"
#include "Maze.h"
#include "Actor.h"
#include "AgentController.h"
#include "PlayerController.h"

int main(int argc, char* argv[])
{
    int width = 32;
    int height = 16;

    Console console;

    Maze maze(width, height);
    maze.Draw(console);

    Actor player(1, 1, '@', Blue);
    player.Draw(console);

    Actor baba(width - 3, 1, 'B', Red);
    baba.Draw(console);

    int i = 0;
    while (true)
    {
        PlayerController::GetInput(console, player, maze);    
        player.Draw(console);
        
        AgentController::Move(player.GetX(), player.GetY(), baba, maze);
        baba.Draw(console);
    }
}
