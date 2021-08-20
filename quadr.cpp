#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "quadr.h"

/// ��������� ��� ��������� ����� ���� double
const double EPSILON = 0.000001;

/**
 * @brief ���������� ��� ����� ���� double
 * @param [in] a, b
 * \return 1, ���� a ����� b; 0, ���� ���
 */
char is_equal_approx(double a, double b)
{
    return (fabs(a - b) < EPSILON);
}

/**
 * @brief ������ ��������� ��� ��������
 * @param [in] b_coeff ����������� ��� x
 * @param [in] c_coeff ��������� ����
 * @param [in] *x1 ������ �� ����������, � ������� ����� ������� �����
 * \return ���������� ������: 1, INF ��� 0
 */
int solve_linear(double b_coeff, double c_coeff, double* x1)
{
    if (!is_equal_approx(b_coeff, 0))
    {
        *x1 = -c_coeff / b_coeff;
        return 1;
    }
    else
        if (is_equal_approx(c_coeff, 0))
        {
            // ��� ����-� ����� ���� => � ����������� (-Inf; Inf)
            return INF_ROOTS;
        }
        else
        {
            return 0;
        }


    return 0;
}

/**
 * @brief ������ ���������� ���������, ���������� ���������� �������� � *x1 � *x2
 * \param [in] a,b,c ������������
 * \param [in] *x1, *x2 ��������� �� x1 � x2
 * \return ���������� ������
 */
int solve_quadratic(double a_coeff, double b_coeff, double c_coeff, double* x1, double* x2)
{
    assert(isfinite(a_coeff));
    assert(isfinite(b_coeff));
    assert(isfinite(c_coeff));
    assert(x1 != NULL);
    assert(x2 != NULL);

    double discriminant = b_coeff * b_coeff - 4 * a_coeff * c_coeff; // ������������

    if (discriminant < 0)
    { // ��� ������
        return 0;
    }

    double d_sqrt = sqrt(discriminant);

    if (is_equal_approx(a_coeff, 0))
    {
        return solve_linear(b_coeff, c_coeff, x1);
    }
    else
        if (is_equal_approx(discriminant, 0))
        {
            *x1 = -b_coeff / 2 / a_coeff;
            return 1;
        }
        else
        {
            //printf("D = %lf\n", discriminant);
            *x1 = (-b_coeff + d_sqrt) / 2 / a_coeff;
            *x2 = (-b_coeff - d_sqrt) / 2 / a_coeff;
            return 2;
        }
}

