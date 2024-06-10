#pragma once

#include <windows.h>

enum FontColor
{
    Black = 0x0,
    Blue = 0x1,
    Green = 0x2,
    Aqua = 0x3,
    Red = 0x4,
    Purple = 0x5,
    Yellow = 0x6,
    White = 0x7,
    Gray = 0x8,
    LightBlue = 0x9,
    LightGreen = 0xa,
    LightAqua = 0xb,
    LightRed = 0xc,
    LightPurple = 0xd,
    LightYellow = 0xe,
    BrightLight = 0xf
};

class Console
{
public:
    HANDLE hConsole;
    Console();
    static void Write(const char& ch);
    void MoveCursor(short x, short y) const;
    void Write(const char& ch, FontColor color) const;
    static void Clear();
};