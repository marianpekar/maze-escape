#include "FractalBrownianMotion.h"

void FractalBrownianMotion::GeneratePermutations()
{
    static std::uniform_int_distribution dist(0, 256);

    for (int& p : perms)
    {
        p = dist(gen);
    }
}

float FractalBrownianMotion::Sample(const float x, const float y, const int octaves, const float persistence,
                                    const float low, const float high) const
{
    float sample = 0;
    float frequency = 1;
    float amplitude = 1;
    float max = 0;

    for (auto i = 0; i < octaves; i++)
    {
        sample = SamplePerlin(x * frequency, y * frequency) * amplitude;
        max += amplitude;
        amplitude *= persistence;
        frequency *= 2;
    }

    sample /= max;
    return Remap(sample, -0.33f, 0.33f, low, high);
}

float FractalBrownianMotion::SamplePerlin(const float x, const float y) const
{
    int a = floor(x);
    int b = floor(y);

    float nx = x - a;
    float ny = y - b;

    a &= 255;
    b &= 255;

    const int gi00 = perms[a + perms[b]] % 8;
    const int gi01 = perms[a + perms[b]] % 8;
    const int gi10 = perms[a + perms[b]] % 8;
    const int gi11 = perms[a + perms[b]] % 8;

    const float n00 = Dot(grads[gi00], nx, ny);
    const float n10 = Dot(grads[gi10], nx - 1, ny);
    const float n01 = Dot(grads[gi01], nx, ny - 1);
    const float n11 = Dot(grads[gi11], nx - 1, ny - 1);

    const float u = Fade(nx);
    const float v = Fade(ny);

    const float x1 = Lerp(n00, n10, u);
    const float x2 = Lerp(n01, n11, u);

    return Lerp(x1, x2, v);
}

float FractalBrownianMotion::Dot(const Grad& grad, const float x, const float y)
{
    return std::get<0>(grad) * x + std::get<1>(grad) * y;
}

float FractalBrownianMotion::Lerp(const float a, const float b, const float t)
{
    return (1.0f - t) * a + t * b;
}

float FractalBrownianMotion::Fade(const float t)
{
    return t * t * t * (t * (t * 6.0f - 15.0f) + 10.0f);
}

float FractalBrownianMotion::Remap(const float val, const float min1, const float max1,
                                   const float min2, const float max2)
{
    return min2 + (val - min1) * (max2 - min2) / (max1 - min1);
}
