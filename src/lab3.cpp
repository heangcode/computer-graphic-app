#include <iostream>
#include <vector>
#include <cmath>
#include <GL/freeglut.h>

namespace Lab3
{
    std::vector<float> preMultiply(std::vector<float> &vec, std::vector<std::vector<float>> &mat)
    {
        std::vector<float> result(mat[0].size(), 0);
        for (int i = 0; i < mat[0].size(); ++i)
            for (int j = 0; j < vec.size(); ++j)
                result[i] += mat[j][i] * vec[j];
        return result;
    }

    std::vector<float> postMultiply(std::vector<float> &vec, std::vector<std::vector<float>> &mat)
    {
        std::vector<float> result(mat.size(), 0);
        for (int i = 0; i < mat.size(); ++i)
            for (int j = 0; j < vec.size(); ++j)
                result[i] += mat[i][j] * vec[j];
        return result;
    }

    std::vector<float> negateVector(std::vector<float> &vec)
    {
        std::vector<float> result(vec.size());
        for (int i = 0; i < vec.size(); ++i)
            result[i] = -vec[i];
        return result;
    }

    std::vector<float> multiplyScalarWithVector(float scalar, std::vector<float> &vec)
    {
        std::vector<float> result(vec.size());
        for (int i = 0; i < vec.size(); ++i)
            result[i] = vec[i] * scalar;
        return result;
    }

    std::vector<float> addVector(std::vector<float> &vec1, std::vector<float> &vec2)
    {
        std::vector<float> result(vec1.size());
        for (int i = 0; i < vec1.size(); ++i)
            result[i] = vec1[i] + vec2[i];
        return result;
    }

    std::vector<float> subtractVector(std::vector<float> &vec1, std::vector<float> &vec2)
    {
        std::vector<float> result(vec1.size());
        for (int i = 0; i < vec1.size(); ++i)
            result[i] = vec1[i] - vec2[i];
        return result;
    }

    float computeMagnitude(std::vector<float> &vec)
    {
        float sum = 0;
        for (auto &val : vec)
            sum += val * val;
        return sqrt(sum);
    }

    std::vector<float> normalize(std::vector<float> &vec)
    {
        std::vector<float> result(vec.size());
        float mag = computeMagnitude(vec);
        for (int i = 0; i < vec.size(); ++i)
            result[i] = vec[i] / mag;
        return result;
    }

    float dotProduct(std::vector<float> &vec1, std::vector<float> &vec2)
    {
        float result = 0;
        for (int i = 0; i < vec1.size(); ++i)
            result += vec1[i] * vec2[i];
        return result;
    }

    std::vector<float> crossProduct(std::vector<float> &vec1, std::vector<float> &vec2)
    {
        std::vector<float> result(3);
        result[0] = vec1[1] * vec2[2] - vec1[2] * vec2[1];
        result[1] = vec1[2] * vec2[0] - vec1[0] * vec2[2];
        result[2] = vec1[0] * vec2[1] - vec1[1] * vec2[0];
        return result;
    }

    std::vector<float> transpose(std::vector<float> &vec)
    {
        return vec; // As this is vector, not a matrix, transpose will result in the same vector
    }

    void drawSinWave(float amplitude, float frequency, float phase)
    {
        glBegin(GL_LINE_STRIP);
        for (float t = -1.0; t <= 1.0; t += 0.001)
        {
            float x = t;
            float y = amplitude * sin(frequency * t + phase);
            glVertex2f(x, y);
        }
        glEnd();
    }

    void renderFunction()
    {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0f, 0.0f, 0.0f);
        drawSinWave(1.0, 2 * M_PI, 0.0);
        glFlush();
    }

    void runLab3()
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

        // Create the window
        glutCreateWindow("Lab3 Window");

        // Set the display function
        glutDisplayFunc(renderFunction);

        // Enter the GLUT main loop
        glutMainLoop();
    }
}
