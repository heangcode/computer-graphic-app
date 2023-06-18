#include <GL/glut.h>
#include <math.h>

// Define some constants for the menu item IDs
#define TRIG_CIRCLE 1
#define MIDPOINT_CIRCLE 2
#define RED 3
#define BLUE 4
#define WIDTH_1 5
#define WIDTH_2 6

namespace Lab6
{
    int circleType = TRIG_CIRCLE;
    float colorR = 1.0, colorG = 0.0, colorB = 0.0;
    float pointSize = 1.0;

    void drawPixel(int x, int y)
    {
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
    }

    void trigonometryCircle(int xc, int yc, int r)
    {
        float theta;
        for (theta = 0; theta <= 2 * 3.1416; theta += 0.01)
        {
            int x = r * cos(theta) + xc;
            int y = r * sin(theta) + yc;
            drawPixel(x, y);
        }
    }

    void midpointCircle(int xc, int yc, int r)
    {
        int x = r, y = 0;
        int P = 1 - r;

        drawPixel(xc + x, yc + y);
        drawPixel(xc - x, yc + y);
        drawPixel(xc + x, yc - y);
        drawPixel(xc - x, yc - y);
        drawPixel(xc + y, yc + x);
        drawPixel(xc - y, yc + x);
        drawPixel(xc + y, yc - x);
        drawPixel(xc - y, yc - x);

        while (x > y)
        {
            y++;
            if (P <= 0)
            {
                P = P + 2 * y + 1;
            }
            else
            {
                x--;
                P = P + 2 * y - 2 * x + 1;
            }
            if (x < y)
            {
                break;
            }
            drawPixel(xc + x, yc + y);
            drawPixel(xc - x, yc + y);
            drawPixel(xc + x, yc - y);
            drawPixel(xc - x, yc - y);
            if (x != y)
            {
                drawPixel(xc + y, yc + x);
                drawPixel(xc - y, yc + x);
                drawPixel(xc + y, yc - x);
                drawPixel(xc - y, yc - x);
            }
        }
    }

    void drawCircles()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(colorR, colorG, colorB);
        glPointSize(pointSize);

        trigonometryCircle(-50, 0, 50);
        if (circleType == MIDPOINT_CIRCLE)
        {
            midpointCircle(50, 0, 50);
        }

        glFlush();
    }

    void menu(int item)
    {
        switch (item)
        {
        case TRIG_CIRCLE:
            circleType = TRIG_CIRCLE;
            break;
        case MIDPOINT_CIRCLE:
            circleType = MIDPOINT_CIRCLE;
            break;
        case RED:
            colorR = 1.0;
            colorG = 0.0;
            colorB = 0.0;
            break;
        case BLUE:
            colorR = 0.0;
            colorG = 0.0;
            colorB = 1.0;
            break;
        case WIDTH_1:
            pointSize = 1.0;
            break;
        case WIDTH_2:
            pointSize = 2.0;
            break;
        default:
            break;
        }

        glutPostRedisplay();
    }

    void runLab6()
    {
        char *my_argv[] = {(char *)"glutapp", NULL};
        int my_argc = 1;
        glutInit(&my_argc, my_argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutCreateWindow("Lab 8: Midpoint Circle Algorithm");
        gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
        glutDisplayFunc(drawCircles);
        glutInitWindowSize(500, 500);

        int menuID = glutCreateMenu(menu);
        glutAddMenuEntry("Trigonometry Circle", TRIG_CIRCLE);
        glutAddMenuEntry("Midpoint Circle", MIDPOINT_CIRCLE);
        glutAddMenuEntry("Red", RED);
        glutAddMenuEntry("Blue", BLUE);
        glutAddMenuEntry("Width 1", WIDTH_1);
        glutAddMenuEntry("Width 2", WIDTH_2);
        glutAttachMenu(GLUT_RIGHT_BUTTON);

        int width = 500;
        int height = 500;
        glutInitWindowSize(width, height);
        int screenWidth = glutGet(GLUT_SCREEN_WIDTH);
        int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);
        int x = (screenWidth - width) / 2;
        int y = (screenHeight - height) / 2;
        glutInitWindowPosition(x, y);

        glutMainLoop();
    }
}
