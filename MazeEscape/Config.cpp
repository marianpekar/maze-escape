#include "Config.h"

#include <algorithm>
#include <string>

void Config::Parse(int argc, char* argv[])
{
    for (int i = 1; i < argc - 1; i++)
    {
        std::string key = std::string(argv[i]);
        std::string val = std::string(argv[i + 1]);

        std::ranges::transform(key, key.begin(), [](const unsigned char c) { return std::tolower(c); });

        if (key == "width" || key == "w") mazeWidth = std::stoi(val);
        else if (key == "height" || key == "h") mazeHeight = std::stoi(val);
        else if (key == "wallchar" || key == "wch") wallChar = val[0];
        else if (key == "holes" || key == "o") wallHolesCount = std::stoi(val);
        else if (key == "wallcolor" || key == "wco") wallColor = std::stoi(val);
        else if (key == "playercolor" || key == "pco") playerColor = std::stoi(val);
        else if (key == "playerchar" || key == "pch") playerChar = val[0];
        else if (key == "babacolor" || key == "bco") babaColor = std::stoi(val);
        else if (key == "babachar" || key == "bch") babaChar = val[0];
        else if (key == "keyup" || key == "ku") keyUp = val[0];
        else if (key == "keydown" || key == "kd") keyDown = val[0];
        else if (key == "keyleft" || key == "kl") keyLeft = val[0];
        else if (key == "keyright" || key == "kr") keyRight = val[0];
        else if (key == "keyforfeit" || key == "kf") forfeitKey = val[0];
        else if (key == "noisecolor1" || key == "nco1") noiseColor1 = std::stoi(val);
        else if (key == "noisecolor2" || key == "nco2") noiseColor2 = std::stoi(val);
        else if (key == "noisecolor3" || key == "nco3") noiseColor3 = std::stoi(val);
        else if (key == "noisecolor4" || key == "nco4") noiseColor4 = std::stoi(val);
        else if (key == "noisecolor5" || key == "nco5") noiseColor5 = std::stoi(val);
        else if (key == "noisescale" || key == "nscl") noiseScale = std::stof(val);
        else if (key == "noiseoctaves" || key == "noct") noiseOctaves = std::stoi(val);
        else if (key == "noisepersistence" || key == "nper") noisePersistence = std::stof(val);

        isWidthOdd = mazeWidth % 2 != 0;
        isHeightOdd = mazeHeight % 2 != 0;
    }
}
