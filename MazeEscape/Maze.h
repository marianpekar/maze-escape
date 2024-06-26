﻿#pragma once

#include <random>
#include <vector>

class Maze
{
    using Point = std::pair<int, int>;

    class Directions
    {
        std::vector<Point> data = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    public:
        Directions(const std::mt19937& gen) : gen(gen)
        {
        }

        std::mt19937 gen;
        void Shuffle() { std::ranges::shuffle(data, gen); }
        Point& operator[](const int i) { return data[i]; }
    } directions = Directions(gen);

    std::mt19937 gen;
    std::vector<int> data;
    const struct Config* cfg;
    void Open(int x, int y);
    bool IsEdge(int x, int y) const;
    void OpenRandom();

public:
    Maze(const Config* cfg, const std::mt19937& gen) : gen(gen), cfg(cfg)
    {
    }

    void Generate(int x, int y);
    void PlaceExit();
    bool IsOpen(int x, int y) const;
    const int& At(int x, int y) const;
    void Draw(const class Console& console, const class FractalBrownianMotion* fbm) const;
    bool IsValid(int x, int y) const;
};