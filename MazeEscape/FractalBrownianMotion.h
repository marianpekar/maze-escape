#pragma once

#include <tuple>
#include <random>
#include <vector>

class FractalBrownianMotion
{
    using Grad = std::tuple<float, float>;

    std::mt19937 gen;

    static constexpr size_t perm_size = 512;

    int perms[perm_size] = {};

    std::vector<Grad> grads = {
        Grad(1, 1),
        Grad(-1, 1),
        Grad(1, -1),
        Grad(-1, -1),
        Grad(1, 0),
        Grad(-1, 0),
        Grad(1, 0),
        Grad(-1, 0)
    };


    static float Dot(const Grad& grad, float x, float y);
    static float Lerp(float a, float b, float t);
    static float Fade(float t);
    static float Remap(float val, float min1, float max1, float min2, float max2);

    float SamplePerlin(float x, float y) const;

public:
    FractalBrownianMotion(const std::mt19937& gen) : gen(gen)
    {
    }

    void GeneratePermutations();
    float Sample(float x, float y, int octaves, float persistence, float low, float high) const;
};