// Последний локальный минимум
// [The last local minimum]
// 
// Дана математическая прямоугольная матрица размером N на M.
// Необходимо разработать эффективную функцию (или программу), которая 
// находит и возвращает местоположение последнего локального минимума. 

#include "logic.h"

void get_last_local_minimum(int** matrix, int n, int m, int* ii, int* jj) {
	if (n <= 0 || m <= 0 || matrix == nullptr || (n == 1 && m == 1)) {
		return;
	}

	if (n > 1 && m > 1 && (*(*(matrix + n - 1) + m - 1) < *(*(matrix + n - 1) + m - 2)
		&& *(*(matrix + n - 1) + m - 1) < *(*(matrix + n - 2) + m - 1)))
	{
		*ii = n;
		*jj = m;
		return;
	}

	if (n > 1 && m > 1) {
		for (int j = m - 2; j > 1; j--) {
			int element = *(*(matrix + n - 1) + j);
			if (element < *(*(matrix + n - 1) + j - 1)
				&& element < *(*(matrix + n - 1) + j + 1)
				&& element < *(*(matrix + n - 2) + j)){
				*ii = n;
				*jj = j + 1;
				return;
			}
		}
	}

	if (n > 1 && m > 1 && (*(*(matrix + n - 1) + 0) < *(*(matrix + n - 1) + 1)
		&& *(*(matrix + n - 1) + 0) < *(*(matrix + n - 2) + 0)))
	{
		*ii = n;
		*jj = 1;
		return;
	}

	for (int i = n - 2; i > 1; i--)
	{

		for (int j = m - 2; j > 1; j--)
		{
			/*if (i == n - 1 && j == 0
				&& *(*(matrix + i + 1) + j) > *(*(matrix + i) + j)
				&& *(*(matrix + i) + j) > *(*(matrix + i) + j + 1))
			{
				*ii = i + 1;
				*jj = j + 1;
				break;
			}
			if (i == 0 && j == m - 1
				&& *(*(matrix + i - 1) + j) > *(*(matrix + i) + j)
				&& *(*(matrix + i) + j) > *(*(matrix + i) + j - 1))
			{
				*ii = i + 1;
				*jj = j + 1;
				break;
			}

			if (i == 0 && j == 0
				&& *(*(matrix + i - 1) + j) > *(*(matrix + i) + j)
				&& *(*(matrix + i) + j) > *(*(matrix + i) + j + 1))
			{
				*ii = i + 1;
				*jj = j + 1;
				break;
			}
			if (i > 0 && j == m - 1
				&& *(*(matrix + i + 1) + j) > *(*(matrix + i) + j)
				&& *(*(matrix + i) + j) > *(*(matrix + i) + j - 1)
				&& *(*(matrix + i) + j) > *(*(matrix + i) + j + 1))
			{
				*ii = i + 1;
				*jj = j + 1;
				break;
			}
			if (i > 0 && j == 0
				&& *(*(matrix + i - 1) + j) > *(*(matrix + i) + j)
				&& *(*(matrix + i) + j) > *(*(matrix + i) + j - 1)
				&& *(*(matrix + i) + j) > *(*(matrix + i) + j + 1))
			{
				*ii = i + 1;
				*jj = j + 1;
				break;

			}

			if (i == n - 1 && j > 0
				&& *(*(matrix + i + 1) + j) > *(*(matrix + i) + j)
				&& *(*(matrix + i - 1) + j) > *(*(matrix + i) + j)
				&& *(*(matrix + i) + j) > *(*(matrix + i) + j - 1))
			{
				*ii = i + 1;
				*jj = j + 1;
				break;

			}

			if (i == 0 && j > 0
				&& *(*(matrix + i + 1) + j) > *(*(matrix + i) + j)
				&& *(*(matrix + i - 1) + j) > *(*(matrix + i) + j)
				&& *(*(matrix + i) + j) > *(*(matrix + i) + j + 1)
				)
			{
				*ii = i + 1;
				*jj = j + 1;
				break;

			}*/
			int element = *(*(matrix + i) + j);
			if (*(*(matrix + i + 1) + j) > element
				&& *(*(matrix + i - 1) + j) > element
				&& *(*(matrix + i) + j + 1) > element
				&& *(*(matrix + i) + j - 1) > element) {

				*ii = i + 1;
				*jj = j + 1;

			}
		}


	}

}