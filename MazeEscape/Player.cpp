#include "Player.h"

#include "Console.h"

void Player::Move(const short x, const short y)
{
    px = this->x;
    py = this->y;
    this->x = x;
    this->y = y;
}

void Player::Draw(const Console& console) const
{
    console.MoveCursor(px, py);
    Console::Write(' ');
    console.MoveCursor(x, y);
    console.Write('@', Blue);
}
