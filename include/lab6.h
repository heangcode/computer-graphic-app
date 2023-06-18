#ifndef LAB6_H
#define LAB6_H

#include <GL/glut.h>
#include <math.h>

namespace Lab6
{
    // Function to draw pixels
    void drawPixel(int x, int y);

    // Function to draw a circle using Trigonometry
    void trigonometryCircle(int xc, int yc, int r);

    // Function to draw a circle using Midpoint Circle Algorithm
    void midpointCircle(int xc, int yc, int r);

    // Function to draw two circles side by side
    void drawCircles();

    // Main function
    void runLab6();
}

#endif /* LAB6_H */
