// Сумма элементов столбцов с экстремальными элементами
// [The Sum of elements of columns with extreme elements]
// 
// Дана математическая прямоугольная матрица размером N на M.
// Необходимо разработать функцию (или программу), которая 
// высчитывает сумму элементов в тех столбцах заданной матрицы,
// которые содержат хотя бы один экстремальный элемент.

#include "logic.h"

int find_max_in_columns_of_matrix(int** matrix, int n, int m) {
	int max = -100;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (*(*(matrix + j) + i) > max) {
				max = *(*(matrix + j) + i);
			}
		}
	}
	return max;
}

int find_min_in_columns_of_matrix(int** matrix, int n, int m) {
	int min = 100;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (*(*(matrix + j) + i) < min) {
				min = *(*(matrix + j) + i);
			}
		}
	}
	return min;
}

bool is_column_with_extreme_value(int** matrix, int n, int m, int max, int min) {


	for (int j = 0; j < n; j++)
	{
		if (*(*(matrix + j) + m) == max || *(*(matrix + j) + m) == min) {
			return true;
		}
	}

	return false;
}

int sum_elements_of_columns_with_extreme_value(int** matrix, int n, int m) {
	if (matrix == nullptr) {
		return 0;
	}
	if (n <= 0 || m <= 0) {
		return 0;
	}

	int sum = 0;

	int max = find_max_in_columns_of_matrix(matrix, n, m);
	int min = find_min_in_columns_of_matrix(matrix, n, m);

	for (int i = 0; i < m; i++)
	{
		if (is_column_with_extreme_value(matrix, n, i, max, min)) {
			for (int j = 0; j < n; j++)
			{
				sum += *(*(matrix + j) + i);
			}
		}
	}

	return sum;
}