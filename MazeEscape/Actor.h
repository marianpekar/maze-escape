#pragma once

class Actor
{
    int x, y, px, py, ix, iy;
    char avatar;
    int color;
    bool forfeit;

public:
    Actor(int x, int y, char avatar, int color);
    int GetX() const { return x; }
    int GetY() const { return y; }
    void Move(int nx, int ny);
    void Draw(const class Console& console) const;
    void Reset();
    bool HasForfeit() const;
    void Forfeit();
};