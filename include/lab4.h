#ifndef LAB4_H
#define LAB4_H

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <cmath>

namespace Lab4
{
    // RGB for axis
    extern GLfloat aRed;
    extern GLfloat aGreen;
    extern GLfloat aBlue;

    // RGB for unit
    extern GLfloat uRed;
    extern GLfloat uGreen;
    extern GLfloat uBlue;

    extern int chooseARGB;
    extern int chooseURGB;
    extern int choosegeoType;
    extern int choosestar;

    // Method for Axis Menu
    void selectAxisMenu(int choice);

    // Method for Unit Menu
    void selectUnitMenu(int choice);

    // Method for Geometric type menu
    void selectGeoMenu(int choice);

    // Method for star type menu
    void selectStarMenu(int choice);

    void createMenu();

    void sinWavePoint();

    void axis();

    void sinWave();

    void star1();

    void star2();

    void star3();

    void star4();

    void display();

    void init();

    void runLab4();
}

#endif // LAB4_H
