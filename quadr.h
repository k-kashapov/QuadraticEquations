#pragma once

/// ���������� ������, ������� ��������� ����������, ���� �� ���������� ����� 
const int INF_ROOTS = 100;

/**
 * @brief ������ ��������� ��� ��������
 * @param [in] b_coeff ����������� ��� x
 * @param [in] c_coeff ��������� ����
 * @param [in] *x1 ������ �� ����������, � ������� ����� ������� �����
 * @param [out] n ���������� ������: 1, INF ��� 0
 */
int solve_linear(double b_coeff, double c_coeff, double* x1);

/**
 * @brief ���������� ��� ����� ���� double
 * @param [in] a, b
 * @param [out] bool ���������� 1, ���� a ����� b; 0, ���� ���
 */
char is_equal_approx(double a, double b);

/**
 * ��������� ������������ a, b � c, ��������� �� x1 � x2.������ ���������� ���������.���������� ���������� ������, ���������� ���������� �������� �* x1 �* x2.
 */
int solve_quadratic(double a_coeff, double b_coeff, double c_coeff, double* x1, double* x2);