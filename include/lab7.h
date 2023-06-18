#ifndef LAB7_H
#define LAB7_H

#include <GL/glut.h>
#include <vector>

#define RESIZE_REGION 1
#define ADD_LINES 2
#define CLIP 3
#define CLIP_COLOR 4

namespace Lab7
{
    void drawRegion();
    void drawLines();
    void drawScene();
    void clipLines();
    void resizeRegion();
    void changeClipColor();
    void addLines();
    void menu(int item);
    void runLab7();
}

#endif // LAB7_H
