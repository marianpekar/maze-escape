#include "Actor.h"

#include "Console.h"


void Actor::Move(const short x, const short y)
{
    px = this->x;
    py = this->y;
    this->x = x;
    this->y = y;
}

void Actor::Draw(const Console& console) const
{
    console.MoveCursor(px, py);
    Console::Write(' ');
    console.MoveCursor(x, y);
    console.Write(avatar, Blue);
}