#pragma once

class Player
{
    short x, y;
    short px, py;
public:
    Player(short x, short y) : x(x), y(y), px(x), py(y) {}
    const short& GetX() const { return x; }
    const short& GetY() const { return y; }
    void Move(short x, short y);
    void Draw(const class Console& console) const;
};
