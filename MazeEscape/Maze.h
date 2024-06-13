#pragma once

#include <random>
#include <vector>

#include "FractalBrownianMotion.h"

class Maze
{
    class Directions
    {
        std::vector<int> data = { 0, 1, 2, 3 };
    public:
        Directions(const std::mt19937& gen) : gen(gen) {}
        std::mt19937 gen;
        void Shuffle() { std::ranges::shuffle(data, gen); }
        int& operator[](const int i) { return data[i]; }
    } directions = Directions(gen);

    std::mt19937 gen;
    std::vector<int> data;
    int width;
    int height;
    void Open(const int& x, const int& y) { data[x + y * height] = 0; }
    void OpenRandom();
public:
    Maze(const int& w, const int& h, const std::mt19937& gen) : gen(gen), width(w), height(h) {}
    void Generate(const int& x, const int& y);
    void PlaceExit();
    bool IsOpen(const int& x, const int& y) const { return data[x + y * height] < 1; }
    const int& At(const int& x, const int& y) const { return data[x + y * height]; }
    void Draw(const class Console& console, const FractalBrownianMotion& fbm);
    bool IsValid(const int& x, const int& y) const;
};
