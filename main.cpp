#include <stdio.h>
#include <string.h>
#include "test.h"

// Отключает ошибку, связанную со scanf, в Visual Studio
#pragma warning(disable:4996) 

int main(int argc, char* argv[])
{
    if (argc == 2 && !strcmp(argv[1], "-test")){
        start_tests();
        return 0;
    }

    double a_coeff = 0.0, b_coeff = 0.0, c_coeff = 0.0; // Коэф-ы в конечном уравнении
    
    printf("ax^2 + bx + c = 0\n");
    printf("Input coefficients: a b c\n");
    scanf("%lf %lf %lf", &a_coeff, &b_coeff, &c_coeff); // Считываем коэф-ы

    double x1 = 0.0, x2 = 0.0;
    
    char roots = solve_quadratic(a_coeff, b_coeff, c_coeff, &x1, &x2);

    switch (roots) // Смотрим, сколько корней
    {
    case 0:
        printf("No roots");
        break;
    case 1:
        printf("One root: x = %lf", x1);
        break;
    case 2:
        printf("Roots: x1 = %lf, x2 = %lf", x1, x2);
        break;
    case INF_ROOTS:
        printf("Any x will do");
        break;
    default:
        printf("Something went wrong");
        break;
    }
    
    return 0;
}

