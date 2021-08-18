#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cmath>

#define STR_LEN 1000
#define isletter(c) (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
#define approved(c) (c >= '0' && c <= '9' || isletter(c) || c == '-' || c == '+')

int main(int argc, char* argv[])
{
	char var_name = 'x';

	char c = getchar();
	while (!approved(c)) // Пропускаем все символы, которые не явл. цифрами или буквами или + или -
		c = getchar();
	
	char str[STR_LEN]; // Строка для запоминания цифр коэффициентов
	char* ptr = str; 
	long double last_coef = 0.0; // Последний введённый коэф.
	int coef_len = 0; // Его длина
	
	long double a = 0.0, b = 0.0, cc = 0.0; // Коэф-ы в конечном уравнении
	int other_side = 1; // Ввод чисел слева (1) или справа (-1) от равно

	while (c != '\n') {
		if (isspace(c));
		else if (c == '-' || c == '+' || c == '=') {
			
			if (coef_len > 0) // Если ситуация по типу ...1234.0 +...
			{
				*ptr = '\0';
				last_coef = other_side * (*(ptr - 1) == '-') ? -1 : (coef_len == 0) ? 1 : atof(ptr - coef_len);
				last_coef *= other_side;
				cc += last_coef;
				coef_len = 0;
			}
			if (c == '=') other_side = -1;
			else
			{
				*ptr++ = c; // Сохраняем знак следующего коэф-а
				coef_len++;
			}
		}
		else if (isdigit(c) || c == '.') 
		{
			*ptr++ = c;
			coef_len++;
		}
		else
		{
			*ptr = '\0';
			last_coef = (*(ptr - 1) == '-') ? -1 : (coef_len == 0) ? 1 : atof(ptr - coef_len);
			last_coef *= other_side;
			coef_len = 0;

			if (isletter(c)) { // Если попалась буква, то запоминаем её как имя переменной в уравнении
				var_name = c;
				char next = getchar();

				if (next == '^') {
					char power = getchar();
					switch (power)
					{
					case '2':
						a += last_coef;
						break;
					case '1':
						b += last_coef;
						break;
					case '0':
						cc += last_coef;
						break;
					default:
						printf("invalid power");
						return 1;
					}
				}
				else {

					b += last_coef; // Была найдена буква, но не степень => это первая степень
					if (next == '-') {
						*ptr++ = '-';
					}
					
				}
			}
			
		}

		c = getchar();
	}

	if (coef_len > 0) // Чекаем, если последним был введен свободный член
	{
		*ptr = '\0';
		last_coef = (*(ptr - 1) == '-') ? -1 : (coef_len == 0) ? 1 : atof(ptr - coef_len);
		last_coef *= other_side;
		cc += last_coef;
		coef_len = 0;
	}

	printf("%f%c^2 %f%c %f = 0\n", a, var_name, b, var_name, cc);

	long double d = b * b - 4 * a * cc;
	printf("d = %lf\n", d);
	if (d < 0) {
		printf("No roots");
		return 0;
	}
	
	long double x1, x2;
	
	x1 = (-b + sqrt(d)) / 2 / a;
	x2 = (-b - sqrt(d)) / 2 / a;

	printf("Roots: %c1 = %lf, %c2 = %lf", var_name, x1, var_name, x2);
}
