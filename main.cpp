#include <stdio.h>
#include <math.h>
#include <assert.h>

#pragma warning(disable:4996) // Отключает ошибку, связанную со scanf, в Visual Studio

const int INF_ROOTS = 100;
const double EPSILON = 0.000001;

// Принимает коэф-ы b и c, указатель на x1. Решает уравнение как линейное, возвращает количество корней: 1, INF или 0, ответ помещает в *x1 
int solve_linear(double b_coeff, double c_coeff, double* x1);

// Сравнивает два числа типа double
char is_equal_approx(double a, double b);

// Принимает коэффициенты a, b и c, указатели на x1 и x2. Решает квадратное уравнение. Возвращает количество корней, результаты вычислений помещает в *x1 и *x2 
int solve_quadratic(double a_coeff, double b_coeff, double c_coeff, double* x1, double* x2);

int main(int argc, char* argv[])
{
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

char is_equal_approx(double a, double b)
{
    return (fabs(a - b) <= EPSILON);
}

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
            // Все коэф-ы равны нулю => Х принадлежит (-Inf; Inf)
            return INF_ROOTS;
        }
        else
        {
            return 0;
        }


    return 0;
}

int solve_quadratic(double a_coeff, double b_coeff, double c_coeff, double* x1, double* x2)
{
    assert(isfinite(a_coeff));
    assert(isfinite(b_coeff));
    assert(isfinite(c_coeff));
    assert(x1 != NULL);
    assert(x2 != NULL);

    double discriminant = b_coeff * b_coeff - 4 * a_coeff * c_coeff; // Дискриминант

    if (discriminant < 0)
    { // Нет корней
        return 0;
    }

    double d_sqrt = sqrt(discriminant);

    if (a_coeff == 0)
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
            printf("D = %lf\n", discriminant);
            *x1 = (-b_coeff + d_sqrt) / 2 / a_coeff;
            *x2 = (-b_coeff - d_sqrt) / 2 / a_coeff;
            return 2;
        }
}
