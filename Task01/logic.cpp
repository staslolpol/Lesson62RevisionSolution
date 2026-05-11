// Task 01 [The arithmetic mean of non-zero elements]
// Среднее арифметическое ненулевых элементов
// 
// Дана математическая прямоугольная матрица размером N на M.
// Необходимо спроектировать эффективный алгоритм и разработать функцию, 
// которая вычисляет среднее арифметическое ненулевых элементов матрицы. 
// Не забудьте про механизм "защиты от дурака".

#include "logic.h"

int find_sum_of_nonzero_elements(int** matrix, int n, int m) {
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (*(*(matrix + i) + j) != 0) {
				sum += *(*(matrix + i) + j);
			}
		}
	}

	return sum;
}

int find_count_of_nonzero_elements(int** matrix, int n, int m) {
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (*(*(matrix + i) + j) != 0) {
				count++;
			}
		}
	}

	return count;
}


double find_avg(int sum, int count) {
	return sum / double(count);
}

double calculate_arithmetical_mean_of_nonzero_elements(int** matrix, int n, int m) {
	if (matrix == nullptr) {
		return -1;
	}
	if (n <= 0 || m <= 0) {
		return -1;
	}

	int count = find_count_of_nonzero_elements(matrix, n, m);

	if (count == 0) {
		return 0;
	}

	int sum = find_sum_of_nonzero_elements(matrix, n, m);

	return find_avg(sum, count);

}