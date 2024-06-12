#pragma once

class Actor
{
    int x, y;
    int px, py;
    char avatar;
    enum FontColor color;
public:
    Actor(const int& x, const int& y, char avatar, FontColor color) : x(x), y(y), px(x), py(y), avatar(avatar), color(color) {}
    const int& GetX() const { return x; }
    const int& GetY() const { return y; }
    void Move(const int& nx, const int& ny);
    void Draw(const class Console& console) const;
};
