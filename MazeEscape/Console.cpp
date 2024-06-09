#include "Console.h"

#include <iostream>

Console::Console()
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Console::Write(const std::string& str)
{
    std::cout << str;
}

void Console::Write(const std::string& str, const FontColor color) const
{
    SetConsoleTextAttribute(hConsole, color);
    std::cout << str;
    SetConsoleTextAttribute(hConsole, White);
}

void Console::Write(int x, int y, const std::string& str)
{

}