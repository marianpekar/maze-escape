#include "Actor.h"

#include "Console.h"

Actor::Actor(const int& x, const int& y, const char& avatar, FontColor color) :
    x(x), y(y), px(x), py(y), ix(x), iy(y), avatar(avatar), color(color)
{
}

void Actor::Move(const int& nx, const int& ny)
{
    px = this->x;
    py = this->y;
    this->x = nx;
    this->y = ny;
}

void Actor::Draw(const Console& console) const
{
    if (px != x || py != y)
    {
        console.MoveCursor(px, py);
        Console::Write(' ');
    }

    console.MoveCursor(x, y);
    console.Write(avatar, color);
}

void Actor::Reset()
{
    x = px = ix;
    y = py = iy;
}
