#include <iostream>
#include "include/lab1.h"
#include "include/lab2.h"
#include "include/lab3.h"
#include "include/lab4.h"
#include "include/lab5.h"
#include "include/lab6.h"
#include "include/lab7.h"

int main()
{
    while (true)
    {
        std::cout << "\nMenu:\n";
        std::cout << "1. LAB 1: Simple Drawing\n";
        std::cout << "2. LAB 2: Drawing axis and Parabola\n";
        std::cout << "3. LAB 3: Sin Wave\n";
        std::cout << "4. LAB 4: Drawing Star\n";
        std::cout << "5. LAB 5: Midpoint Algorithm\n";
        std::cout << "6. Lab 6: Midpoint Circle Algorithm\n";
        std::cout << "7. Lab 7: Clipping\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            Lab1::runLab1();
            break;
        case 2:
            Lab2::runLab2();
            break;
        case 3:
            Lab3::runLab3();
            break;
        case 4:
            Lab4::runLab4();
            break;
        case 5:
            Lab5::runLab5();
            break;
        case 6:
            Lab6::runLab6();
            break;
        case 7:
            Lab7::runLab7();
            break;
        case 0:
            std::cout << "Exiting...\n";
            return 0;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
