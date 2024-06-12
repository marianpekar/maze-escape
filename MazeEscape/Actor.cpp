#include "Actor.h"

#include "Console.h"

void Actor::Move(const int& nx, const int& ny)
{
    px = this->x;
    py = this->y;
    this->x = nx;
    this->y = ny;
}

void Actor::Draw(const Console& console) const
{
    console.MoveCursor(px, py);
    Console::Write(' ');
    console.MoveCursor(x, y);
    console.Write(avatar, color);
}