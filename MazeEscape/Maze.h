#pragma once

#include <random>
#include <vector>

class Maze
{
    class Directions
    {
        std::vector<int> data = { 0, 1, 2, 3 };
    public:
        std::random_device rd;
        void Shuffle();
        int& operator[](const size_t i) { return data[i]; }
    };
    Directions directions;
    
    std::vector<int> data;
    size_t width;
    size_t height;
    void Open(const size_t x, const size_t y) { data[x + y * width] = 0; }
    void Dig(size_t x, size_t y);
public:
    Maze(size_t w, size_t h);
    bool IsOpen(const size_t x, const size_t y) const { return data[x + y * width] == 0; }
    const int& At(const size_t x, const size_t y) const { return data[x + y * width]; }
    
};
