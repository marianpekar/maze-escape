#include "Console.h"

#include <iostream>

Console::Console()
{
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    hIn = GetStdHandle(STD_INPUT_HANDLE);
}

void Console::Write(const char& ch)
{
    std::cout << ch;
}

void Console::MoveCursor(const SHORT& x, const SHORT& y) const
{
    COORD coord{x, y};
    SetConsoleCursorPosition(hOut, coord);
}

void Console::Write(const char& ch, const FontColor color) const
{
    SetConsoleTextAttribute(hOut, color);
    std::cout << ch;
    SetConsoleTextAttribute(hOut, White);
}

const int& Console::GetKey() const
{
    INPUT_RECORD InputRecord;
    DWORD Events;

    while (true)
    {
        ReadConsoleInput(hIn, &InputRecord, 1, &Events);

        if (InputRecord.EventType == KEY_EVENT && InputRecord.Event.KeyEvent.bKeyDown)
        {
            return InputRecord.Event.KeyEvent.uChar.AsciiChar;
        }
    }
}

void Console::Clear()
{
    system("cls");
}
