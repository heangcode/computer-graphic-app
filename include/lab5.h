#ifndef LAB5_H
#define LAB5_H

#include <GL/glut.h>

namespace Lab5
{
    // Function Prototypes
    void drawDDALine(int x1, int y1, int x2, int y2);
    void drawMidPointLine(int x1, int y1, int x2, int y2);
    void changeColor(float r, float g, float b);
    void changeLineWidth(float width);
    void display();
    void menu(int num);
    void createGLUTMenus();
    void runLab5();
}
#endif /* LAB5_H */