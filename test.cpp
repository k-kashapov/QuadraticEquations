#include <stdio.h>
#include <assert.h>
#include "test.h"

void addTest(double a, double b, double c, int res, double x1_res, double x2_res, const char *comment) 
{

    double x1 = 0.0, x2 = 0.0;
    
    printf("Test: %s\n", comment);
    int roots_num = solve_quadratic(a, b, c, &x1, &x2);
    if (roots_num != res || !is_equal_approx(x1, x1_res) || !is_equal_approx(x2, x2_res))
    {
        printf("\nTest failed: expected %d roots, got %d;\n", res, roots_num);
        printf("expected x1 = %lf, got %lf;\n", x1_res, x1);
        printf("expected x2 = %lf, got %lf;\n", x2_res, x2);
        printf("Input values: a = %lf, b = %lf, c = %lf;\n\n", a, b, c);
    }


}

void start_tests() 
{
    addTest(4, 5, 1, 2, -0.25, -1, "ordinary quad equation");
    addTest(0, 5, -1, 1, 0.2, 0.0, "ordinary lin equation");
    addTest(4, 0, -1, 2, 0.5, -0.5, "quadr equation, b = 0");
    addTest(4, -5, 0, 2, 1.25, 0.0, "quadr equation, c = 0");
    addTest(0, 0, 0, INF_ROOTS, 0.0, 0.0, "0 = 0");
    addTest(4, -1, 67, 0, 0.0, 0.0, "quadr equation, d < 0");
    addTest(9, 6, 1, 1, -1.0 / 3, 0.0, "quadr equation, d = 0");
    addTest(0, 0, 3, 0, 0.0, 0.0, "3 = 0");

    printf("All tests complete!");
}
