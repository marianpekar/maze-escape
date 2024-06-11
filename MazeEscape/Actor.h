#pragma once

class Actor
{
    short x, y;
    short px, py;
    char avatar;
    enum FontColor color;
public:
    Actor(short x, short y, char avatar, FontColor color) : x(x), y(y), px(x), py(y), avatar(avatar), color(color) {}
    const short& GetX() const { return x; }
    const short& GetY() const { return y; }
    void Move(short x, short y);
    void Draw(const class Console& console) const;
};
