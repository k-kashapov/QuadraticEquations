#include <stdio.h>
#include <assert.h>
#include "test.h"

/**
 * @brief Добавить тест сравнения даблов
 * 
 * \param a, b Даблы
 * \param res Ожидаемый результат
 */
void addTestEquals(double a, double b, char res) {
    
    printf("Test: %lf and %lf\n", a, b);
    if (is_equal_approx(a, b) != res)
    {
        printf("\nTest failed: expected %d, got %d;\n\n", res, !res);
    }
}

/**
 * @brief Добавить тест квадратного уравнения
 * 
 * \param a, b, c Коэффициенты уравнения
 * \param res Ожидаемое количество корней
 * \param x1_res Ожидаемое значение x1
 * \param x2_res Ожидаемое значение x2
 * \param comment Комментарий к тесту
 */
void addTestQuadr(double a, double b, double c, int res, double x1_res, double x2_res, const char *comment) 
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

/**
 * @brief Прогоняет программу через юнит-тесты
 */
void start_tests() 
{
    addTestEquals(5.43, -99999.0, 0);
    addTestEquals(0.0, 0.0, 1);
    addTestEquals(0.123451, 0.12345, 0);
    addTestEquals(-0.000001, 0.0, 0);
    addTestEquals(0.0000004, 0.0, 1);

    addTestQuadr(4, 5, 1, 2, -0.25, -1, "ordinary quad equation");
    addTestQuadr(0, 5, -1, 1, 0.2, 0.0, "ordinary lin equation");
    addTestQuadr(4, 0, -1, 2, 0.5, -0.5, "quadr equation, b = 0");
    addTestQuadr(4, -5, 0, 2, 1.25, 0.0, "quadr equation, c = 0");
    addTestQuadr(0, 0, 0, INF_ROOTS, 0.0, 0.0, "0 = 0");
    addTestQuadr(4, -1, 67, 0, 0.0, 0.0, "quadr equation, d < 0");
    addTestQuadr(9, 6, 1, 1, -1.0 / 3, 0.0, "quadr equation, d = 0");
    addTestQuadr(0, 0, 3, 0, 0.0, 0.0, "3 = 0");

    printf("All tests complete!");
}
