// Urok_1__Modul__9__Domasnaa_rabota_1521864835.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


#include <iostream>
#include <cstdio>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <Windows.h>

#define sz1 5
#define sz2 6

int main()
{
	printf(" Urok_1__Modul__9__Domasnaa_rabota_1521864835\n");
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int n = 0;

	do {
		if (n == 1)
		{
			/* 	1.	Дан двумерный массив целых чисел
			a.	Сформировать одномерный массив,
			каждый элемент которого равен наибольшему по модулю элементу
			соответствующего столбца двумерного массива
			b.	Сформировать одномерный массив,
			каждый элемент которого равен наибольшему по модулю элементу
			соответствующей строки двумерного массива			*/
			int arr[sz1][sz2];
			int *arr_a = (int*)(malloc(sizeof(int)*sz1));
			if (arr_a == NULL)
				printf("arr_a - pamiat NE videlena\n");
			int *arr_b = (int*)(malloc(sizeof(int)*sz2));
			if (arr_b == NULL)
				printf("arr_b - pamiat NE videlena\n");
						
			printf("двумерный массив целых чисел\n");
			for(int i=0; i<sz1; i++)
			{
				for (int j = 0; j < sz2; j++)
				{
					*(*(arr + i) + j) = 10 + rand() % 50;
					printf("%3d", *(*(arr + i) + j));
				}
				printf("\n");
			}
			printf("\n");
			int cnt = 0;
			for (int i = 0; i < sz1; i++)
			{
				int max = *(*(arr + i) +0);
				for (int j = 0; j<sz2; j++)
				{
					if (*(*(arr + i) + j) > max)
						max = *(*(arr + i) + j);
				}
				*(arr_b + cnt) = max;
				cnt++;
			}
			printf("\n");
			printf("b. одномерный массив, из наибольших элементов строки двумерного массива \n");
			for (int j = 0; j < cnt; j++)
				printf("\t %4d %d\n", *(arr_b + j), j);
			
			cnt = 0;
			for (int j = 0; j < sz2; j++)
			{
				int max = *(*(arr + 0) + j);
				for (int i = 0; i<sz1; i++)
				{
					if (*(*(arr + i) + j)  > max)
					{
						max = *(*(arr + i) + j);
					}
				}
					*(arr_a + cnt) = max; 
					cnt++;
			}
			
			printf("a одномерный массив, из наибольших элементов столбца двумерного массива \n");
			for (int j = 0; j < cnt; j++)
				printf("\t%4d %d\n", *(arr_a + j), j);
			printf("\n");
		}

		else if (n == 2)
		{
			/*	2. 	Дан двумерный массив целых чисел
			a.	Сформировать одномерный массив,
			каждый элемент которого равен первому четному элементу
			соответствующего столбца двумерного массива
			(	если такого элемента в столбце нет, то он равен нулю).
			b.	Сформировать одномерный массив,
			каждый элемент которого равен последнему нечетному элементу
			соответствующей строки двумерного массива
			(	если такого элемента в строке нет, то он равен нулю). 		*/
			int arr[sz1][sz2];
			int *arr_a = (int*)(malloc(sizeof(int)*sz1));
			if (arr_a == NULL)
				printf("arr_a - pamiat NE videlena\n");
			int *arr_b = (int*)(malloc(sizeof(int)*sz2));
			if (arr_b == NULL)
				printf("arr_b - pamiat NE videlena\n");
			
			printf("двумерный массив целых чисел\n");
			for (int i = 0; i<sz1; i++)
			{
				for (int j = 0; j < sz2; j++)
				{
					*(*(arr + i) + j) = 10 + rand() % 105;
					printf("%3d\t", *(*(arr + i) + j));
				}
				printf("\n");
			}
			//----------------------------------------------------------------
			int cnt = 0;
			
			for (int j = 0; j<sz2; j++)
			{
				int fl = 0;
				for (int i = 0; i < sz1; i++)
				{
					if (*(*(arr + i) + j)%2==0)
					{
						*(arr_a + cnt) = *(*(arr + i) + j); 
						fl = 1;
						break;
					}
					}
				if (fl == 0) *(arr_a + cnt) = 0;
				cnt++;

			}
			printf("a. массив первых четных элементов столбца двумерного массива \n");
			for (int j = 0; j < cnt; j++)
			{
				printf("\t%4d %d\n", *(arr_a + j), j);
			}
		//--------------------------------------------------------------------------------
			cnt = 0;
			
			for (int i = 0; i < sz1; i++)
			{
				int fl = 0;
				for (int j = 0; j<sz2; j++)
				{
					if (*(*(arr + i) + sz2-j-1) % 2 != 0)
					{
						*(arr_b + cnt) = *(*(arr + i) + sz2-j-1);
						fl = 1;
						break;
					}
				}
				if (fl == 0) *(arr_b + cnt) = 0;
				cnt++;
			}
			printf("b. массив из последних нечетных элементов строки двумерного массива \n");
			for (int j = 0; j < cnt; j++)
				printf("\t%4d %d\n", *(arr_b + j), j);
			printf("\n");
		}


		else if (n == 3)
		{
			/*	3. 	Дан двумерный массив.
			a.	Сформировать одномерный массив,
			каждый элемент которого равен количеству элементов
			соответствующего столбца двумерного массива, больших данного числа
			b.	Сформировать одномерный массив,
			каждый элемент которого равен сумме элементов
			соответствующей строки двумерного массива, меньших данного числа. */
			
			int arr[sz1][sz2];
			int *arr_a = (int*)(malloc(sizeof(int)*sz1));
			if (arr_a == NULL)
				printf("arr_a - pamiat NE videlena\n"); 
			int *arr_b = (int*)(malloc(sizeof(int)*sz2));
			if (arr_b == NULL)
				printf("arr_b - pamiat NE videlena\n");
			int dan_chislo = 6 + rand() % 4;
			printf("данное число %d \n", dan_chislo);
			printf("двумерный массив целых чисел\n");
			for (int i = 0; i<sz1; i++)
			{
				for (int j = 0; j < sz2; j++)
				{
					*(*(arr + i) + j) = 5 + rand() % 5;
					printf("%3d\t", *(*(arr + i) + j));
				}
				printf("\n");
			}

			for (int j = 0; j<sz2; j++)
			{
				int cnt = 0;
				for (int i = 0; i < sz1; i++)
				{
					if (*(*(arr + i) + j)> dan_chislo)
					{
						cnt++;
					}
				}
				*(arr_a + j) = cnt;
			}
			printf("a. массив из количества элементов столбца двумерного массива больших данного числа \n");
			for (int j = 0; j < sz2; j++)
			{
				printf("%3d", *(arr_a + j));
			}
			printf("\n");
			//--------------------------------------------------------------------------------
			
			
			for (int i = 0; i < sz1; i++)
			{
				int S = 0;
				for (int j = 0; j<sz2; j++)
				{
					if (*(*(arr + i) + j)< dan_chislo)
					{
						S += *(*(arr + i) + j);
					}
				}
				*(arr_b + i) = S;
			}
			printf("b. массив из сумм элементов строки двумерного массива меньших данного числа \n");
			for (int j = 0; j < sz1; j++)
				printf("%3d", *(arr_b + j));
			printf("\n");
		}


		else if (n == 4)
		{
			/*	4. 	Дан двумерный массив размером N x M, заполненный целыми числами
			a.	Все его элементы, кратные трем, записать в одномерный массив.
			b.	Все его положительные элементы записать в один одномерный массив,
			а остальные — в другой 		*/
			int arr[sz1][sz2];
			int m = sz1;
			int n = sz2;
			int kr3 = 0;
			int pol = 0;
			int dr = 0;
			printf("двумерный массив целых чисел\n");
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					*(*(arr + i) + j) = 8 + rand() % 12 - rand() % 15;	
					printf("%3d", *(*(arr + i) + j));
					if (*(*(arr + i) + j) % 3 == 0) kr3++;
					if (*(*(arr + i) + j) > 0) pol++;
				}
				printf("\n");
			}
			dr = m * n - pol;
			int *arr_a = (int*)(malloc(sizeof(int)*kr3));
			if (arr_a == NULL)
				printf("arr_a - pamiat NE videlena\n");
			int *arr_b = (int*)(malloc(sizeof(int)*pol));
			if (arr_b == NULL)
				printf("arr_b - pamiat NE videlena\n");
			int *arr_b1 = (int*)(malloc(sizeof(int)*dr));
			if (arr_b1 == NULL)
				printf("arr_b - pamiat NE videlena\n");
			int k = 0;
			int l = 0;
			int t = 0;
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (*(*(arr + i) + j) % 3 == 0)
					{
						*(arr_a + l) = *(*(arr + i) + j); l++;
					}
					
					if (*(*(arr + i) + j) > 0)
					{
						*(arr_b + k) = *(*(arr + i) + j); k++;
					}
					else 
					{
						*(arr_b1 + t) = *(*(arr + i) + j); t++;
					}
				
				}
			}
			printf("a.	Все его элементы, кратные трем, записать в одномерный массив.\n");
			for (l = 0; l < kr3; l++)
				printf("%4d", *(arr_a + l));
			printf("\n");
			printf("b.	Все его положительные элементы записать в один одномерный массив,\n");
			for (k = 0; k < pol;k++)
				printf("%4d", *(arr_b + k));
			printf("\n");
			printf("а остальные — в другой 	\n");
			for (t = 0; t < dr; t++)
				printf("%4d", *(arr_b1 + t));
			printf("\n");
						
		}

		else if (n == 5)
		{
			/*	5. 	Ввести целые числа. Создать из них массив.
			Вычислить сумму чётных элементов массива 		*/
			int dan_chislo = 8 + rand() % 8;
			int s = 0;
			printf("Ввести целое число N= %d \n", dan_chislo);
			int *arr = (int*)(malloc(sizeof(int)*dan_chislo));
			printf("и массив из N вещественных чисел:\n");
			for (int i = 0; i < dan_chislo; i++)
			{
				*(arr + i) = rand() % 9 + rand() % 9;
				printf("%6d", *(arr + i));
				if (*(arr + i)%2==0) s+= *(arr + i);
			}
			printf("\n");
			printf("сумма чётных элементов массива =  %d \n", s);

			printf("\n");
		}

		else if (n == 6)
		{
			/*	6. 	Ввести целое число N и массив из N вещественных чисел.
			Определить количество отрицательных элементов массива 			*/
			int dan_chislo = 5 + rand() % 11;
			int cnt = 0;
			printf("Ввести целое число N= %d \n", dan_chislo);
			double *arr = (double*)(malloc(sizeof(double)*dan_chislo));
			printf("и массив из N вещественных чисел:\n");
			for (int i = 0; i < dan_chislo; i++)
			{
				float a = rand() % 9;
				float b = rand() % 9;
				*(arr + i) = 1.5 + 0.55*a - 0.65*b;
				printf("%7.2f", *(arr + i));
				if (*(arr + i) < 0) cnt++;
			}
			printf("\n");
			printf("количество отрицательных элементов массива =  %d \n", cnt); 
			
			printf("\n");
		}
		else if (n == 7)
		{
			/*	7. 	Ввести целое число N.
			Создать массив из N вещественных чисел.
			Вычислить произведение элементов, модуль которых меньше 7. 			*/
			int dan_chislo = 8 + rand() % 6;
			double P = 1;
			printf("Ввести целое число N= %d \n", dan_chislo);
			double *arr = (double*)(malloc(sizeof(double)*dan_chislo));
			printf("и массив из N=%d вещественных чисел:\n", dan_chislo);
			for (int i = 0; i < dan_chislo; i++)
			{
				float a = rand() % 7;
				float b = rand() % 8;
				*(arr + i) = 3.5 + 0.65*a - 0.55*b;
				printf("%7.2f", *(arr + i));
				if (abs(*(arr + i))< 7) P *= *(arr + i);
			}
			printf("\n");
			printf("произведение элементов, модуль которых меньше 7=  %7.2f \n", P);
			printf("\n");

		}

		else if (n == 8)
		{
			/*	8. 	Ввести вещественные числа.
			Создать из них массив определить наибольший элемент массива.  			*/
			double max = 0;
			int dan_chislo = 6 + rand() % 6;
			printf("Ввести целое число N= %d \n", dan_chislo);
			double *arr = (double*)(malloc(sizeof(double)*dan_chislo));
			printf("и массив из N вещественных чисел:\n");
			for (int i = 0; i < dan_chislo; i++)
			{
				float a = rand() % 21;
				float b = rand() % 14;
				*(arr + i) = 4.5 + 26.77*a - .21*b;
				printf("%7.2f", *(arr + i));
				if (*(arr + i) > max) max = *(arr + i);
			}
			printf("\n");
			printf(" наибольший элемент массива %9.2f \n", max);
			printf("\n");
		}

		else if (n == 9)
		{
			/*	9. 	Ввести целое число N и массив из N целых чисел.
			Определить наименьший элемент массива 			*/
			double min = 21+14;
			int dan_chislo = 11 + rand() % 4;
			printf("Ввести целое число N= %d \n", dan_chislo);
			int *arr = (int*)(malloc(sizeof(int)*dan_chislo));
			printf("и массив из N  %d целых чисел:\n", dan_chislo);
			for (int i = 0; i < dan_chislo; i++)
			{
				*(arr + i) = rand() % 21 + rand() % 14;
				printf("%3d", *(arr + i));
				if (*(arr + i) < min) min = *(arr + i);
			}
			printf("\n");
			printf(" наименьший элемент массива %7d \n", min);
			printf("\n");
		}

		else if (n == 10)
		{
			/*	10. Ввести вещественные числа. 	Создать из них массив.
			Определить среднее арифметическое элементов массива. 	*/
			float S = 0;
			int dan_chislo = 5 + rand() % 4;
			printf("Ввести целое число N= %d \n", dan_chislo);
			double *arr = (double*)(malloc(sizeof(double)*dan_chislo));
			printf("и массив из N=%d вещественных чисел:\n", dan_chislo);
			for (int i = 0; i < dan_chislo; i++)
			{
				float a = rand() % 21;
				float b = rand() % 14;
				*(arr + i) = 4.5 + 6.77*a - 5.21*b;
				printf("%8.2f", *(arr + i));
				 S += *(arr + i);
			}
			S = S / dan_chislo;
			printf("\n");
			printf(" среднее арифметическое элементов массива %7.2f \n", S);
			printf("\n");
		}

		else if (n == 11)
		{
			/*	11. Ввести вещественные числа. 	Создать из них массив.
			Определить количество неотрицательных элементов массива 	*/
			int dan_chislo = 5 + rand() % 9;
			int cnt = 0;
			printf("Ввести целое число N= %d \n", dan_chislo);
			double *arr = (double*)(malloc(sizeof(double)*dan_chislo));
			printf("и массив из N вещественных чисел:\n");
			for (int i = 0; i < dan_chislo; i++)
			{
				float a = rand() % 9;
				float b = rand() % 9;
				*(arr + i) = 1.5 + 0.55*a - 0.65*b;
				printf("%8.2f", *(arr + i));
				if (*(arr + i) >= 0) cnt++;
			}
			printf("\n");
			printf("количество неотрицательных элементов массива =  %d \n", cnt);

			printf("\n");
		}

		else if (n == 12)
		{
			/*	12. Ввести целое число N и массив из N вещественных чисел.
			Определить индекс последнего отрицательного элемента  		*/
			int dan_chislo = 5 + rand() % 11;
			int cnt = 0;
			printf("Ввести целое число N= %d \n", dan_chislo);
			double *arr = (double*)(malloc(sizeof(double)*dan_chislo));
			
			printf("и массив из N вещественных чисел:\n");
			for (int i = 0; i < dan_chislo; i++)
			{
				float a = rand() % 9;
				float b = rand() % 9;
				*(arr + i) = 1.5 + 0.55*a - 0.65*b;
				printf("%7.2f", *(arr + i));
			}
			printf("\n");
			for (int i = 0; i < dan_chislo; i++)
			{
				if (*(arr + i) < 0) cnt = i;
			}
			printf("индекс последнего отрицательного элемента =  %d \n", cnt);
			printf("\n");
		}

		else if (n == 13)
		{
			/*	13. Ввести целое число N. Создать массив из N вещественных чисел.
			Вычислить сумму минимального и максимального элементов. 		*/
			int dan_chislo = 5 + rand() % 11;
			
			printf("Ввести целое число N= %d \n", dan_chislo);
			double *arr = (double*)(malloc(sizeof(double)*dan_chislo));
			printf("и массив из N вещественных чисел:\n");
			for (int i = 0; i < dan_chislo; i++)
			{
				float a = rand() % 9;
				float b = rand() % 9;
				*(arr + i) = 1.5 + 0.55*a - 0.65*b;
				printf("%7.2f", *(arr + i));
			}
			printf("\n");
			float min = *arr;
			float max = *arr;
			for (int i = 0; i < dan_chislo; i++)
			{
				if (*(arr + i) > max) max = *(arr + i);
				if (*(arr + i) < min) min = *(arr + i);
			}
			printf("сумма минимального %7.2f и максимального %7.2f элементов=  %7.2f \n", min, max, min+max);
			printf("\n");
		}

		else if (n == 14)
		{
			/*	14. Ввести вещественные числа. 	Создать из них массив.
			Вычислить произведение минимального и максимального элементов. 		*/
			int dan_chislo = 5 + rand() % 11;

			printf("Ввести целое число N= %d \n", dan_chislo);
			double *arr = (double*)(malloc(sizeof(double)*dan_chislo));
			printf("и массив из N вещественных чисел:\n");
			for (int i = 0; i < dan_chislo; i++)
			{
				float a = rand() % 9;
				float b = rand() % 9;
				*(arr + i) = 1.5 + 0.55*a - 0.65*b;
				printf("%7.2f", *(arr + i));
			}
			printf("\n");
			float min = *arr;
			float max = *arr;
			for (int i = 0; i < dan_chislo; i++)
			{
				if (*(arr + i) > max) max = *(arr + i);
				if (*(arr + i) < min) min = *(arr + i);
			}
			printf("произведение минимального %7.2f и максимального %7.2f элементов=  %7.2f \n", min, max, min * max);
			printf("\n");
		}

		else if (n == 15)
		{
			/*	15. Ввести целое число N и массив из N целых чисел.
			Определить, есть ли в массиве число 20. 			*/
			int rand_chislo = 4 + rand() % 12;
			int cnt = 0;
			printf("Ввести целое число N= %d \n", rand_chislo);
			int *arr = (int*)(malloc(sizeof(int)*rand_chislo));
			printf("и массив из N вещественных чисел:\n");
			for (int i = 0; i < rand_chislo; i++)
			{
				*(arr + i) = rand() % 20 + rand() % 5; 
				printf("%4d", *(arr + i));
				if (*(arr + i) == 20) cnt++;
			}
			printf("\n");
			if (cnt>0)
			printf(" в массиве число 20 повторятется %d раз \n", cnt);
			else printf(" в массиве нет числа 20 \n");
			printf("\n");
		}
		printf("Vvod nomera zadania 1 - 15, 0-exit: ");
		scanf_s("%d", &n);
	} while (n != 0);
return 0;
}



