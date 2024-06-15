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
    int noiseColor1 = 8;
    int noiseColor2 = 2;
    int noiseColor3 = 5;
    int noiseColor4 = 6;
    int noiseColor5 = 3;
    float noiseScale = 0.0004f;
    int noiseOctaves = 8;
    float noisePersistence = 32.f;
};