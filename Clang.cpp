﻿#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#pragma warning(disable:4996)


int check_linear(long double a, long double b, long double c) 
{
	if (a == 0) 
	{ // Если а == 0
		if (b) 
		{
			return 1;
		}
		else if (c == 0)
		{
			// Все коэф-ы равны нулю => Х принадлежит (-Inf; Inf)
			return 100;
		}
		else
		{
			return -1;
		}
	}
	
	return 0;
}
/*Возвращает количество корней*/
int solve(long double a, long double b, long double c, long double *x1, long double *x2) 
{
	
	long double d = b * b - 4 * a * c; // Дискриминант
	int lin = 0;

	if (d < 0) 
	{ // Нет корней
		return 0;
	}

	if (lin = check_linear(a, b, c)) 
	{
		switch (lin)
		{
		case 1:
			*x1 = -c / b;
			return 1;
		case 100:
			return 100;
		default:
			return 0;
		}
		
	}
	else if(d == 0)
	{
		*x1 = -b / 2 / a;
		return 1;
	}
	else
	{
		printf("D = %lf\n", d);
		*x1 = (-b + sqrt(d)) / 2 / a;
		*x2 = (-b - sqrt(d)) / 2 / a;
		return 2;
	}
}

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
	case 100:
		printf("Any x will do");
		break;
	default:
		break;
	}
	
	return 0;
}
