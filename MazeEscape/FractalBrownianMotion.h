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


    static float Dot(const Grad& grad, const float& x, const float& y);
    static float Lerp(const float& a, const float& b, const float& t);
    static float Fade(const float& t);
    static float Remap(const float& val, const float& min1, const float& max1, const float& min2, const float& max2);

    float SamplePerlin(const float& x, const float& y) const;

public:
    FractalBrownianMotion(const std::mt19937& gen) : gen(gen) {}
    void GeneratePermutations();
    float Sample(const float& x, const float& y, const int& octaves, const float& persistence, const float& low, const float& high) const;
};
