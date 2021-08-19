#include <stdio.h>
#include <math.h>
#include <assert.h>

#pragma warning(disable:4996)

#define INF_ROOTS 100
#define EPSILON 0.000001

/*Принимает коэф-ы b и c, указатель на x1. Решает уравнение как линейное, возвращает количество корней: 1, INF или 0, ответ помещает в *x1 */
int solve_linear(long double b, long double c, long double* x1);

/*Сравнивает два числа типа long double*/
char is_equal_approx(long double a, long double b);

/*Принимает коэффициенты a, b и c, указатели на x1 и x2. Возвращает количество корней, результаты вычислений помещает в *x1 и *x2 */
int solve(long double a, long double b, long double c, long double* x1, long double* x2);


int main(int argc, char* argv[])
{
	long double a = 0.0, b = 0.0, c = 0.0; // Коэф-ы в конечном уравнении
	
	printf("ax^2 + bx + c = 0\n");
	printf("Input coefficients: a b c\n");
	scanf("%lf %lf %lf", &a, &b, &c); // Считываем коэф-ы

	long double x1 = 0.0, x2 = 0.0;
	
	char roots = solve(a, b, c, &x1, &x2);

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

char is_equal_approx(long double a, long double b)
{
	return (abs(a - b) <= EPSILON);
}

int solve_linear(long double b, long double c, long double* x1)
{
	if (!is_equal_approx(b, 0))
	{
		*x1 = -c / b;
		return 1;
	}
	else if (is_equal_approx(c, 0))
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

int solve(long double a, long double b, long double c, long double* x1, long double* x2)
{
	assert(isfinite(a));
	assert(isfinite(b));
	assert(isfinite(c));
	assert(x1 != NULL);
	assert(x2 != NULL);

	long double d = b * b - 4 * a * c; // Дискриминант
	int lin = 0;

	if (d < 0)
	{ // Нет корней
		return 0;
	}

	long double d_sqrt = sqrt(d);

	if (a == 0)
	{
		return solve_linear(b, c, x1);
	}
	else if (is_equal_approx(d, 0))
	{
		*x1 = -b / 2 / a;
		return 1;
	}
	else
	{
		printf("D = %lf\n", d);
		*x1 = (-b + d_sqrt) / 2 / a;
		*x2 = (-b - d_sqrt) / 2 / a;
		return 2;
	}
}
