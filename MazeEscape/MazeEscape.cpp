#include "Config.h"
#include "Console.h"
#include "Maze.h"
#include "Actor.h"
#include "AgentController.h"
#include "FractalBrownianMotion.h"
#include "PlayerController.h"
#include <format>

int main(int argc, char* argv[])
{
    Config cfg;
    cfg.Parse(argc, argv);
    
    Console console;

    int scorePlayer = 0;
    int scoreBaba = 0;

    std::random_device rd;
    const std::mt19937 gen = std::mt19937(rd());

    Maze maze(&cfg, gen);

    PlayerController controller;
    Actor player(1, 1, cfg.playerChar, static_cast<FontColor>(cfg.playerColor));

    Actor baba(cfg.mazeWidth - 3, 1, cfg.babaChar, static_cast<FontColor>(cfg.babaColor));

    FractalBrownianMotion* fbm = cfg.wallColor == -1 ? new FractalBrownianMotion(gen) : nullptr;

    while (true)
    {
        Console::Clear();

        if (fbm)
        {
            fbm->GeneratePermutations();
        }

        maze.Generate(1, 1);
        maze.Draw(console, fbm);

        player.Draw(console);
        baba.Draw(console);

        console.MoveCursor(cfg.mazeWidth / 2 - 12, cfg.mazeHeight);
        console.Write(std::format("Player: {}", scorePlayer).c_str(), static_cast<FontColor>(cfg.playerColor));
        console.MoveCursor(cfg.mazeWidth / 2 + 4, cfg.mazeHeight);
        console.Write(std::format("Baba: {}", scoreBaba).c_str(), static_cast<FontColor>(cfg.babaColor));

        while (true)
        {
            if (player.GetX() == baba.GetX() && player.GetY() == baba.GetY() || player.HasForfeit())
            {
                scoreBaba++;
                break;
            }

            if (player.GetY() == cfg.mazeHeight - (cfg.isHeightOdd ? 1 : 2))
            {
                scorePlayer++;
                break;
            }

            controller.Move(console, player, maze, cfg);
            player.Draw(console);

            AgentController::Move(player.GetX(), player.GetY(), baba, maze);
            baba.Draw(console);
        }

        player.Reset();
        controller.Reset();
        baba.Reset();
    }
}