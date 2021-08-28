#pragma once

/// Количество корней, которое программа возвращает, если их бесконечно много 
const int INF_ROOTS = 100;

int solve_linear(double b_coeff, double c_coeff, double* x1);

char is_equal_approx(double a, double b);

int solve_quadratic(double a_coeff, double b_coeff, double c_coeff, double* x1, double* x2);
