#pragma once

class Actor
{
    int x, y, px, py, ix, iy;
    char avatar;
    int color;
    bool forfeit;

public:
    Actor(const int& x, const int& y, const char& avatar, const int& color);
    const int& GetX() const { return x; }
    const int& GetY() const { return y; }
    void Move(const int& nx, const int& ny);
    void Draw(const class Console& console) const;
    void Reset();
    bool HasForfeit() const;
    void Forfeit();
};