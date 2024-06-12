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
        std::mt19937 gen = std::mt19937(rd());
        void Shuffle() { std::ranges::shuffle(data, gen); }
        int& operator[](const int i) { return data[i]; }
    } directions;
    
    std::vector<int> data;
    int width;
    int height;
    void Open(const int& x, const int& y) { data[x + y * height] = 0; }
    void Generate(const int& x, const int& y);
public:
    Maze(int w, int h);
    void PlaceExit();
    bool IsOpen(const int& x, const int& y) const { return data[x + y * height] == 0; }
    const int& At(const int& x, const int& y) const { return data[x + y * height]; }
    void Draw(const class Console& console) const;
};
