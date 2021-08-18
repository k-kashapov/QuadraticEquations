#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#pragma warning(disable:4996)


int check_linear(long double a, long double b, long double c) {
	if (a == 0) { // Если а == 0
		if (b) // Если b != 0, то корень = -c / b
		{
			printf("One root: x = %lf", -c / b);
			return 1;
		}
		else if (c == 0)
		{
			printf("Any x will do"); // Все коэф-ы равны нулю => Х принадлежит (-Inf; Inf)
			return 1;
		}
		else
		{
			printf("No roots");
			return 1;
		}
	}
}

void solve_quadratic(long double a, long double b, long double c, long double d) {
	if (d == 0) {
		long double x1 = -b / 2 / a;
		printf("One root: x = %lf", x1);
		return;
	}
	else
	{
		long double x1, x2;

		x1 = (-b + sqrt(d)) / 2 / a;
		x2 = (-b - sqrt(d)) / 2 / a;

		printf("Roots: x1 = %lf, x2 = %lf", x1, x2);
		return;
	}
}

int main(int argc, char* argv[])
{
	long double a = 0.0, b = 0.0, c = 0.0; // Коэф-ы в конечном уравнении
	
	printf("ax^2 + bx + c = 0\n");
	printf("Input coefficients: a b c\n");
	scanf("%lf %lf %lf", &a, &b, &c); // Считываем коэф-ы

	long double d = b * b - 4 * a * c; // Дискриминант

	printf("D = %lf\n", d);

	if (d < 0) { // Нет корней
		printf("No roots");
		return 0;
	}
	
	if (!check_linear(a, b, c))
		solve_quadratic(a, b, c, d);
	
	return 0;
}
