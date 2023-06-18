#include <GL/glut.h>
#include <string>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include "../include/lab2.h"

namespace Lab2
{
    void drawAxes()
    {
        glColor3f(0.0, 0.0, 0.0); // Set color to black for axes

        // Draw x-axis
        glBegin(GL_LINES);
        glVertex2f(-100.0, 0.0);
        glVertex2f(100.0, 0.0);
        glEnd();

        // Draw y-axis
        glBegin(GL_LINES);
        glVertex2f(0.0, -100.0);
        glVertex2f(0.0, 100.0);
        glEnd();

        // Draw unit lines and labels
        for (int i = -90; i <= 90; i += 10)
        {
            std::string s = std::to_string(i);
            const char *c = s.c_str();

            // Draw unit line
            glBegin(GL_LINES);
            glVertex2f(i, -1.0);
            glVertex2f(i, 1.0);
            glEnd();

            // Draw label
            glRasterPos2f(i, -5.0);
            for (int j = 0; j < s.size(); ++j)
            {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, c[j]);
            }
        }
    }

    void drawParabola(float a)
    {
        glColor3f(0.0, 0.0, 1.0); // Set color to blue for parabola

        // Draw parabola
        glBegin(GL_LINE_STRIP);
        for (float x = -100.0; x <= 100.0; x += 0.01)
        {
            float y = a * x * x;
            glVertex2f(x, y);
        }
        glEnd();
    }

    void display(void)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        drawAxes();
        drawParabola(0.01); // You can modify this parameter
        glFlush();
    }

    void init(void)
    {
        glClearColor(1.0, 1.0, 1.0, 0.0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
    }

    void runLab2()
    {
        char *my_argv[] = {(char *)"glutapp", NULL};
        int my_argc = 1;
        glutInit(&my_argc, my_argv);
        glutInitWindowSize(500, 500);
        glutCreateWindow("Lab 2: Axis and Parabola");
        init();
        glutDisplayFunc(display);
        glutMainLoop();
    }
}
