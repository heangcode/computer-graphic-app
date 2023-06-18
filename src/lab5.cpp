#include <GL/glut.h>

namespace Lab5
{
    // Some global variables to keep track of state.
    int menu_id;
    int submenu_id;
    int value = 0;
    float color[3] = {1.0, 1.0, 1.0}; // white color by default
    float lineWidth = 1.0;            // default width

    // Function Prototypes
    void drawDDALine(int x1, int y1, int x2, int y2);
    void drawMidPointLine(int x1, int y1, int x2, int y2);

    // Change Color function
    void changeColor(float r, float g, float b)
    {
        color[0] = r;
        color[1] = g;
        color[2] = b;
    }

    // Change Line Width function
    void changeLineWidth(float width)
    {
        lineWidth = width;
    }

    // Display function
    void display()
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3fv(color);
        glLineWidth(lineWidth);

        // Hard coding some coordinates for demo.
        if (value == 1)
            drawDDALine(100, 200, 300, 400);
        else if (value == 2)
            drawMidPointLine(100, 200, 300, 400);

        glFlush();
    }

    // Menu callback
    void menu(int num)
    {
        if (num == 0)
            glutDestroyWindow(menu_id);
        else
            value = num;
        glutPostRedisplay();
    }

    // Create GL menu
    void createGLUTMenus()
    {
        submenu_id = glutCreateMenu(menu);
        glutAddMenuEntry("Red", 3);
        glutAddMenuEntry("Green", 4);
        glutAddMenuEntry("Blue", 5);
        menu_id = glutCreateMenu(menu);
        glutAddMenuEntry("DDA Line", 1);
        glutAddMenuEntry("Midpoint Line", 2);
        glutAddSubMenu("Colors", submenu_id);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
    }

    // Initialize function
    void init()
    {
        glClearColor(0.0, 0.0, 0.0, 1.0);
        gluOrtho2D(0, 500, 0, 500);
    }

    // Your DDA Line Drawing Function
    void drawDDALine(int x1, int y1, int x2, int y2)
    {
        // DDA algorithm implementation
        // Here, you must implement DDA line drawing algorithm
        // For simplicity, I'm just drawing a simple line from (0, 0) to (200, 200)
        glBegin(GL_LINES);
        glVertex2i(x1, y1);
        glVertex2i(x2, y2);
        glEnd();
    }

    // Your MidPoint Line Drawing Function
    void drawMidPointLine(int x1, int y1, int x2, int y2)
    {
        // Midpoint algorithm implementation
        // Here, you must implement Midpoint line drawing algorithm
        // For simplicity, I'm just drawing a simple line from (300, 300) to (500, 500)
        glBegin(GL_LINES);
        glVertex2i(x1, y1);
        glVertex2i(x2, y2);
        glEnd();
    }

    void runLab5()
    {
        char *my_argv[] = {(char *)"glutapp", NULL};
        int my_argc = 1;
        glutInit(&my_argc, my_argv);

        glutInitDisplayMode(GLUT_RGB);
        glutInitWindowSize(500, 500);
        glutCreateWindow("LAB 5: Midpoint Algorithm");
        init();
        glutDisplayFunc(display);
        createGLUTMenus();
        glutMainLoop();
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

        // Enter the GLUT main loop
        glutMainLoop();
    }
}