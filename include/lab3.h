#ifndef LAB3_H
#define LAB3_H

#include <vector>
#include <GL/freeglut.h>

namespace Lab3
{
    std::vector<float> preMultiply(std::vector<float> &vec, std::vector<std::vector<float>> &mat);
    std::vector<float> postMultiply(std::vector<float> &vec, std::vector<std::vector<float>> &mat);
    std::vector<float> negateVector(std::vector<float> &vec);
    std::vector<float> multiplyScalarWithVector(float scalar, std::vector<float> &vec);
    std::vector<float> addVector(std::vector<float> &vec1, std::vector<float> &vec2);
    std::vector<float> subtractVector(std::vector<float> &vec1, std::vector<float> &vec2);
    float computeMagnitude(std::vector<float> &vec);
    std::vector<float> normalize(std::vector<float> &vec);
    float dotProduct(std::vector<float> &vec1, std::vector<float> &vec2);
    std::vector<float> crossProduct(std::vector<float> &vec1, std::vector<float> &vec2);
    std::vector<float> transpose(std::vector<float> &vec);
    void drawSinWave(float amplitude, float frequency, float phase);
    void renderFunction();
    void runLab3();
}

#endif // LAB3_H
