#pragma once

class Actor
{
    int x, y, px, py, ix, iy;
    char avatar;
    enum FontColor color;
public:
    Actor(const int& x, const int& y, const char& avatar, FontColor color);
    const int& GetX() const { return x; }
    const int& GetY() const { return y; }
    void Move(const int& nx, const int& ny);
    void Draw(const class Console& console) const;
    void Reset();
};
