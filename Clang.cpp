#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#pragma warning(disable:4996)

int main(int argc, char* argv[])
{
	long double coefs[3] = { 0.0, 0.0, 0.0 }; // Коэф-ы в конечном уравнении
	
	for (int i = 0; i < 3; i++) {
		printf("Input coefficient of x^%d\n", 2 - i); 
		scanf("%lf", &coefs[i]); // Считываем коэф-ы
	}

	long double d = coefs[1] * coefs[1] - 4 * coefs[0] * coefs[2]; // Дискриминант

	printf("D = %lf\n", d);

	if (d < 0) { // Нет корней
		printf("No roots");
		return 0;
	}
	
	if (coefs[0] == 0) { // Если а == 0
		if (coefs[1]) // Если b != 0, то корень = -c / b
		{
			printf("One root: x = %lf", -coefs[2] / coefs[1]);
			return 0;
		}
		else if (coefs[2] == 0)
		{
			printf("Any x will do"); // Все коэф-ы равны нулю => Х принадлежит (-Inf; Inf)
			return 0;
		}
		else
		{
			printf("No roots");
			return 0;
		}
	}

	if (d == 0) {
		long double x1 = -coefs[1] / 2 / coefs[0];
		printf("One root: x = %lf", x1);
		return 0;
	}
	else 
	{
		long double x1, x2;

		x1 = (-coefs[1] + sqrt(d)) / 2 / coefs[0];
		x2 = (-coefs[1] - sqrt(d)) / 2 / coefs[0];

		printf("Roots: x1 = %lf, x2 = %lf", x1, x2);
		return 0;
	}
}
