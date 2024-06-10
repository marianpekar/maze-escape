#include "Console.h"

#include <iostream>

Console::Console()
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Console::Write(const char& ch)
{
    std::cout << ch;
}

void Console::Write(const char& ch, const FontColor color) const
{
    SetConsoleTextAttribute(hConsole, color);
    std::cout << ch;
    SetConsoleTextAttribute(hConsole, White);
}

void Console::Clear()
{
    system("cls");
}

