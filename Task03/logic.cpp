// Количество строк с большим количество положительных элементов
// [The Number of rows with a large number of positive elements]
// 
// Дана математическая прямоугольная матрица размером N на M.
// Необходимо разработать функцию(или программу), которая находит
// количество строк, в которых положительных элементов больше 
// чем всех остальных (отрицательных и нулевых).

#include "logic.h"

int find_rows_with_more_positive_values(int* row, int m) {
	int pos_counter = 0;
	int other_counter = 0;

	for (int j = 0; j < m; j++) {
		if (*(row + j) > 0) {
			pos_counter++;
		}
		else {
			other_counter++;
		}
	}

	return pos_counter > other_counter ? 1 : 0;
}

int count_rows_with_more_positive_values(int** matrix, int n, int m) {
	if (n <= 0 || m <= 0 || matrix == nullptr) {
		return 0;
	}

	int total_rows = 0;
	for (int i = 0; i < n; i++) {
		total_rows += find_rows_with_more_positive_values(*(matrix + i ), m);
	}

	return total_rows;
}
