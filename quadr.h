#pragma once

/// Количество корней, которое программа возвращает, если их бесконечно много 
const int INF_ROOTS = 100;

/**
 * @brief Решает уравнение как линейное
 * @param [in] b_coeff Коэффициент при x
 * @param [in] c_coeff Свободный член
 * @param [in] *x1 Ссылка на переменную, в которую будет помещён ответ
 * @param [out] n Количество корней: 1, INF или 0
 */
int solve_linear(double b_coeff, double c_coeff, double* x1);

/**
 * @brief Сравнивает два числа типа double
 * @param [in] a, b
 * @param [out] bool Возвращает 1, если a равно b; 0, если нет
 */
char is_equal_approx(double a, double b);

/**
 * Принимает коэффициенты a, b и c, указатели на x1 и x2.Решает квадратное уравнение.Возвращает количество корней, результаты вычислений помещает в* x1 и* x2.
 */
int solve_quadratic(double a_coeff, double b_coeff, double c_coeff, double* x1, double* x2);