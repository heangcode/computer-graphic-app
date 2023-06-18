#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <cmath>

namespace Lab4
{
    // RGB for axis
    static GLfloat aRed = 0.1;
    static GLfloat aGreen = 0.2;
    static GLfloat aBlue = 0.3;

    // RGB for unit
    static GLfloat uRed = 0.4;
    static GLfloat uGreen = 0.5;
    static GLfloat uBlue = 0.6;

    static int chooseARGB;
    static int chooseURGB;
    static int choosegeoType;
    static int choosestar;

    // Method for Axis Menu
    void selectAxisMenu(int choice)
    {

        printf("Choice: %d", choice);
        if (choice == 0)
        {
            exit(0);
        }
        else
        {
            chooseARGB = choice;
        }
        glutPostRedisplay();
    }

    //     Method for Unit Menu
    void selectUnitMenu(int choice)
    {

        printf("Choice: %d", choice);
        if (choice == 0)
        {
            exit(0);
        }
        else
        {
            chooseURGB = choice;
        }
        glutPostRedisplay();
    }

    // Method for Geometric type menu
    void selectGeoMenu(int choice)
    {

        printf("Choice: %d", choice);
        if (choice == 0)
        {
            exit(0);
        }
        else
        {
            choosegeoType = choice;
        }
        glutPostRedisplay();
    }

    // Method for star type menu
    void selectStarMenu(int choice)
    {

        printf("Choice: %d", choice);
        if (choice == 0)
        {
            exit(0);
        }
        else
        {
            choosestar = choice;
        }
        glutPostRedisplay();
    }

    void createMenu()
    {

        int axismenu;
        int unitmenu;
        int defaults;
        int geometricType;
        int starType;

        // Axis Color menu
        axismenu = glutCreateMenu(selectAxisMenu);

        // submenu for axis color
        glutAddMenuEntry("Blue", 1);
        glutAddMenuEntry("Green", 2);
        glutAddMenuEntry("Yellow", 3);

        // Unit Color menu
        unitmenu = glutCreateMenu(selectUnitMenu);

        // submenu for unit color
        glutAddMenuEntry("Brown", 1);
        glutAddMenuEntry("Cyan", 2);
        glutAddMenuEntry("White", 3);

        // Geometric type menu
        geometricType = glutCreateMenu(selectGeoMenu);

        // submenu for geometric type
        glutAddMenuEntry("Point", 1);
        glutAddMenuEntry("Line", 2);

        // Star type menu
        starType = glutCreateMenu(selectStarMenu);

        // submenu for star type
        glutAddMenuEntry("5_Star", 1);
        glutAddMenuEntry("6_Star", 2);
        glutAddMenuEntry("7_star", 3);
        glutAddMenuEntry("2_Color_Star", 4);

        defaults = glutCreateMenu(selectAxisMenu);

        //    add all menu
        glutAddSubMenu("Axis Color", axismenu);
        glutAddSubMenu("Unit Color", unitmenu);
        glutAddSubMenu("Geometric Type", geometricType);
        glutAddSubMenu("Star Type", starType);

        glutAddMenuEntry("Exit", 0);

        glutAttachMenu(GLUT_RIGHT_BUTTON);
    }
    void sinWavePoint()
    {
        glPointSize(2);

        glBegin(GL_POINTS);
        GLdouble i;
        for (i = -250; i < 250; i += 5)
        {
            double x = i;
            double y = 40 * sin(x / 30 + 6);
            glVertex2d(x, y);
        }
    }

    void axis()
    {
        glLineWidth(3);
        glBegin(GL_LINES);
        //    Y-axis
        glVertex2f(0, -250);
        glVertex2f(0, 250);

        //    X-axis
        glVertex2f(-250, 0);
        glVertex2f(250, 0);
    }

    void sinWave()
    {

        glLineWidth(2);
        glBegin(GL_LINE_STRIP);
        GLdouble i;
        for (i = -250; i < 250; i += 1)
        {
            double x = i;
            double y = 40 * sin(x / 30 + 6);
            glVertex2d(x, y);
        }
    }

    void star1()
    {

        glBegin(GL_LINE_LOOP);
        glVertex2f(0, 250);
        glVertex2f(-157.64, -250);
        glVertex2f(250, 79);
        glVertex2f(-250, 79);
        glVertex2f(157.64, -250);
    }

    void star2()
    {

        glBegin(GL_LINE_LOOP);
        glVertex2f(0, 250);
        glVertex2f(-250, -125);
        glVertex2f(250, -125);

        glEnd();
        glBegin(GL_LINE_LOOP);
        glVertex2f(0, -250);
        glVertex2f(-250, 125);
        glVertex2f(250, 125);
    }

    void star3()
    {
        glLineWidth(1);
        glBegin(GL_LINE_LOOP);
        glVertex2f(0, 250);
        glVertex2f(-54.22, 112.62);
        glVertex2f(-195.43, 156);
        glVertex2f(-121.86, 27.84);
        glVertex2f(-243.75, -55.56);
        glVertex2f(-97.76, -78);
        glVertex2f(-108.57, -225.2);
        glVertex2f(0, -125);
        glVertex2f(108.34, -225.31);
        glVertex2f(97.68, -78);
        glVertex2f(243.7, -55.81);
        glVertex2f(121.89, 27.71);
        glVertex2f(195.6, 155.7);
        glVertex2f(54.34, 112.57);
        glVertex2f(0, 250);
    }

    void star4()
    {
        glLineWidth(2);
        glBegin(GL_TRIANGLES);
        //    red part
        glColor3f(1, 0, 0);
        glVertex2f(0, 250);
        glVertex2f(0, 0);
        glVertex2f(73.47, 101.13);

        glVertex2f(237.76, 77.25);
        glVertex2f(0, 0);
        glVertex2f(118.88, -38.63);

        glVertex2f(146.95, -202.25);
        glVertex2f(0, -125);
        glVertex2f(0, 0);

        glVertex2f(-146.95, -202.25);
        glVertex2f(-118.88, -38.63);
        glVertex2f(0, 0);

        glVertex2f(-237.76, 77.25);
        glVertex2f(-73.47, 101.13);
        glVertex2f(0, 0);

        //    gray part
        glColor3f(0.1, 0.1, 0.1);
        glVertex2f(0, 250);
        glVertex2f(0, 0);
        glVertex2f(-73.47, 101.13);

        glVertex2f(237.76, 77.25);
        glVertex2f(0, 0);
        glVertex2f(73.47, 101.13);

        glVertex2f(146.95, -202.25);
        glVertex2f(118.88, -38.63);
        glVertex2f(0, 0);

        glVertex2f(-146.95, -202.25);
        glVertex2f(0, -125);
        glVertex2f(0, 0);

        glVertex2f(-237.76, 77.25);
        glVertex2f(-118.88, -38.63);
        glVertex2f(0, 0);
    }
    void display()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(aRed, aGreen, aBlue);
        axis();
        glEnd();

        /*condition for axis color
         * if 1 = blue
         * if 2 = green
         * if 3 = yellow*/
        if (chooseARGB == 1)
        {
            aRed = 0;
            aGreen = 0;
            aBlue = 1;
        }
        else if (chooseARGB == 2)
        {
            aRed = 0;
            aGreen = 1;
            aBlue = 0;
        }
        else if (chooseARGB == 3)
        {
            aRed = 1;
            aGreen = 1;
            aBlue = 0;
        }

        /*condition for unit color
         * if 1 = brown
         * if 2 = cyan
         * if 3 = white*/
        if (chooseURGB == 1)
        {
            uRed = 1.0;
            uGreen = 0.5;
            uBlue = 0;
        }
        else if (chooseURGB == 2)
        {
            uRed = 0.5;
            uGreen = 1;
            uBlue = 1;
        }
        else if (chooseURGB == 3)
        {
            uRed = 1;
            uGreen = 1;
            uBlue = 1;
        }

        /*condition for geometric type
         * if 1 = point
         * if 2 = line*/
        if (choosegeoType == 1)
        {
            glColor3f(uRed, uGreen, uBlue);
            sinWavePoint();
            glEnd();
        }
        else if (choosegeoType == 2)
        {
            glColor3f(uRed, uGreen, uBlue);
            sinWave();
            glEnd();
        }

        /*condition for star
         * if 1 = 5_star
         * if 2 = 6_star
         * if 3 = 7_star
         * if 4 = 2_color_star*/
        if (choosestar == 1)
        {
            glColor3f(uRed, uGreen, uBlue);
            star1();
            glEnd();
        }
        else if (choosestar == 2)
        {
            glColor3f(uRed, uGreen, uBlue);
            star2();
            glEnd();
        }
        else if (choosestar == 3)
        {
            glColor3f(uRed, uGreen, uBlue);
            star3();
            glEnd();
        }
        else if (choosestar == 4)
        {
            glColor3f(0.5, 0.2, 0.1);
            star4();
            glEnd();
        }
        glFlush();
    }
    void init()
    {
        glClearColor(0, 0, 0, 0);
        gluOrtho2D(-250, 250, -250, 250);
    }

    void runLab4()
    {
        char *my_argv[] = {(char *)"glutapp", NULL};
        int my_argc = 1;
        glutInit(&my_argc, my_argv);

        // Set the window size
        int width = 500;
        int height = 500;
        glutInitWindowSize(width, height);

        // Get the screen width and height
        int screenWidth = glutGet(GLUT_SCREEN_WIDTH);
        int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);

        // Calculate the starting x and y position for the window
        int x = (screenWidth - width) / 2;
        int y = (screenHeight - height) / 2;

        // Set the initial window position to the calculated values
        glutInitWindowPosition(x, y);

        glutInitDisplayMode(GLUT_RGBA);
        glutCreateWindow("Lab 4 : Drawing Star");
        createMenu();
        init();
        glutDisplayFunc(display);

        // Enter the GLUT main loop
        glutMainLoop();
    }
}