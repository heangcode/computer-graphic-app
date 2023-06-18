#include <GL/glut.h>
#include <stdio.h>
#include <string>
#include <math.h>
#include "../include/lab1.h"
#include <iostream>

#define PI 3.1415926535897932384626433832795

namespace Lab1
{
    void display(void)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        float radius = 50.0; // Radius of circle
        float twoPi = 2.0f * PI;
        glBegin(GL_POLYGON);
        glColor3f(1.0, 0.0, 0.0); // Red color
        for (int i = 0; i <= 100; i++)
        {
            float theta = i * twoPi / 100;
            float x = radius * cos(theta);
            float y = radius * sin(theta);
            glVertex2f(x + 75, y + 75); // Circle centered at (75, 75)
        }
        glEnd();
        glFlush();
    }

    void init(void)
    {
        glClearColor(1.0, 1.0, 1.0, 0.0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, 150.0, 0, 150.0);
    }

    void runLab1()
    {
        char *my_argv[] = {(char *)"glutapp", NULL};
        int my_argc = 1;
        glutInit(&my_argc, my_argv);
        glutInitWindowSize(500, 500);
        int screen_width = 1920;
        int screen_height = 1080;
        int window_width = 500;
        int window_height = 500;
        int window_x = (screen_width - window_width) / 2;
        int window_y = (screen_height - window_height) / 2;
        glutInitWindowPosition(window_x, window_y);
        glutCreateWindow("Lab 1: Simple Drawing");
        init();
        glutDisplayFunc(display);
        glutMainLoop();
    }

}