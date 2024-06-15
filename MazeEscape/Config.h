#pragma once

struct Config
{
    Config() = default;
    int mazeWidth = 64;
    int mazeHeight = 24;
    char wallChar = '#';
    int wallHolesCount = 12;
    int wallColor = -1;
    int playerColor = 1;
    char playerChar = '@';
    int babaColor = 4;
    char babaChar = 'B';
    char keyUp = 'w';
    char keyDown = 's';
    char keyLeft = 'a';
    char keyRight = 'd';
    char forfeitKey = 'k';
};