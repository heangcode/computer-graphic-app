#include <GL/glut.h>
#include <vector>

#define RESIZE_REGION 1
#define ADD_LINES 2
#define CLIP 3
#define CLIP_COLOR 4

namespace Lab7
{
    // Define the clipping region and scale factor
    float scaleFactor = 1.0;
    std::vector<std::pair<int, int>> linePoints; // A vector to hold the points of lines

    // Clipping region coordinates
    float clipRegionLeft = -0.5;
    float clipRegionRight = 0.5;
    float clipRegionBottom = -0.5;
    float clipRegionTop = 0.5;

    // Clip color
    float clipColorR = 0.0;
    float clipColorG = 1.0;
    float clipColorB = 0.0;

    void drawRegion()
    {
        glPushMatrix();
        glScalef(scaleFactor, scaleFactor, 1.0); // Apply the scale factor

        // Draw the clipping region as a white square
        glColor3f(1.0, 1.0, 1.0);
        glRectf(clipRegionLeft, clipRegionBottom, clipRegionRight, clipRegionTop);

        glPopMatrix();
    }

    void drawLines()
    {
        glBegin(GL_LINES);
        for (size_t i = 0; i < linePoints.size(); i += 2)
        {
            if (linePoints[i].first >= clipRegionLeft && linePoints[i].first <= clipRegionRight &&
                linePoints[i].second >= clipRegionBottom && linePoints[i].second <= clipRegionTop &&
                linePoints[i + 1].first >= clipRegionLeft && linePoints[i + 1].first <= clipRegionRight &&
                linePoints[i + 1].second >= clipRegionBottom && linePoints[i + 1].second <= clipRegionTop)
            {
                // Both points are inside the clipping region, draw the line segment in red
                glColor3f(1.0, 0.0, 0.0);
            }
            else
            {
                // At least one point is outside the clipping region, draw the line segment in green
                glColor3f(0.0, 1.0, 0.0);
            }

            glVertex2i(linePoints[i].first, linePoints[i].second);
            glVertex2i(linePoints[i + 1].first, linePoints[i + 1].second);
        }
        glEnd();
    }

    void drawScene()
    {
        glClear(GL_COLOR_BUFFER_BIT);

        drawRegion();
        drawLines();

        glutSwapBuffers();
    }

    void clipLines()
    {
        std::vector<std::pair<int, int>> clippedLinePoints;

        for (size_t i = 0; i < linePoints.size(); i += 2)
        {
            float x1 = linePoints[i].first;
            float y1 = linePoints[i].second;
            float x2 = linePoints[i + 1].first;
            float y2 = linePoints[i + 1].second;

            bool point1Inside = (x1 >= clipRegionLeft && x1 <= clipRegionRight && y1 >= clipRegionBottom && y1 <= clipRegionTop);
            bool point2Inside = (x2 >= clipRegionLeft && x2 <= clipRegionRight && y2 >= clipRegionBottom && y2 <= clipRegionTop);

            if (point1Inside && point2Inside)
            {
                // Both points are inside the clipping region, add the line segment as is
                clippedLinePoints.push_back(linePoints[i]);
                clippedLinePoints.push_back(linePoints[i + 1]);
            }
            else if (point1Inside && !point2Inside)
            {
                // Point 1 is inside and Point 2 is outside, clip the line segment
                float clippedX, clippedY;
                if (x1 == x2)
                {
                    // Vertical line, clip based on y-coordinate
                    if (y1 < clipRegionBottom)
                    {
                        clippedX = x1 + (clipRegionBottom - y1) * (x2 - x1) / (y2 - y1);
                        clippedY = clipRegionBottom;
                    }
                    else
                    {
                        clippedX = x1 + (clipRegionTop - y1) * (x2 - x1) / (y2 - y1);
                        clippedY = clipRegionTop;
                    }
                }
                else
                {
                    // Non-vertical line, clip based on x-coordinate
                    if (x1 < clipRegionLeft)
                    {
                        clippedX = clipRegionLeft;
                        clippedY = y1 + (clipRegionLeft - x1) * (y2 - y1) / (x2 - x1);
                    }
                    else
                    {
                        clippedX = clipRegionRight;
                        clippedY = y1 + (clipRegionRight - x1) * (y2 - y1) / (x2 - x1);
                    }
                }

                clippedLinePoints.push_back(std::make_pair(clippedX, clippedY));
                clippedLinePoints.push_back(linePoints[i + 1]);
            }
            else if (!point1Inside && point2Inside)
            {
                // Point 1 is outside and Point 2 is inside, clip the line segment
                float clippedX, clippedY;
                if (x1 == x2)
                {
                    // Vertical line, clip based on y-coordinate
                    if (y1 < clipRegionBottom)
                    {
                        clippedX = x1 + (clipRegionBottom - y1) * (x2 - x1) / (y2 - y1);
                        clippedY = clipRegionBottom;
                    }
                    else
                    {
                        clippedX = x1 + (clipRegionTop - y1) * (x2 - x1) / (y2 - y1);
                        clippedY = clipRegionTop;
                    }
                }
                else
                {
                    // Non-vertical line, clip based on x-coordinate
                    if (x1 < clipRegionLeft)
                    {
                        clippedX = clipRegionLeft;
                        clippedY = y1 + (clipRegionLeft - x1) * (y2 - y1) / (x2 - x1);
                    }
                    else
                    {
                        clippedX = clipRegionRight;
                        clippedY = y1 + (clipRegionRight - x1) * (y2 - y1) / (x2 - x1);
                    }
                }

                clippedLinePoints.push_back(linePoints[i]);
                clippedLinePoints.push_back(std::make_pair(clippedX, clippedY));
            }
        }

        linePoints = clippedLinePoints;
    }

    void resizeRegion()
    {
        scaleFactor += 0.1; // Increase the scale factor by 0.1
    }

    void changeClipColor()
    {
        // Change the clip color to a random color
        clipColorR = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        clipColorG = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        clipColorB = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    }

    void addLines()
    {
        // Generate random lines and add them to the linePoints vector
        int numLines = 5; // Number of lines to add

        for (int i = 0; i < numLines; ++i)
        {
            int x1 = rand() % 10 - 5; // Random x-coordinate for point 1
            int y1 = rand() % 10 - 5; // Random y-coordinate for point 1
            int x2 = rand() % 10 - 5; // Random x-coordinate for point 2
            int y2 = rand() % 10 - 5; // Random y-coordinate for point 2

            linePoints.push_back(std::make_pair(x1, y1));
            linePoints.push_back(std::make_pair(x2, y2));
        }
    }

    void menu(int item)
    {
        switch (item)
        {
        case RESIZE_REGION:
            resizeRegion();
            break;
        case ADD_LINES:
            addLines();
            break;
        case CLIP:
            clipLines();
            break;
        case CLIP_COLOR:
            changeClipColor();
            break;
        default:
            break;
        }

        glutPostRedisplay();
    }

    void runLab7()
    {
        char *my_argv[] = {(char *)"glutapp", NULL};
        int my_argc = 1;
        glutInit(&my_argc, my_argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
        glutInitWindowSize(500, 500);
        glutCreateWindow("Lab 7: Clipping");

        int menuID = glutCreateMenu(menu);
        glutAddMenuEntry("Resize Clipping Region", RESIZE_REGION);
        glutAddMenuEntry("Add Lines", ADD_LINES);
        glutAddMenuEntry("Clip", CLIP);
        glutAddMenuEntry("Clip Color", CLIP_COLOR);
        glutAttachMenu(GLUT_RIGHT_BUTTON);

        glutDisplayFunc(drawScene);

        glClearColor(0.0, 0.0, 0.0, 1.0); // Set clear color to black

        glutMainLoop();
    }
}
