/*
NIM             : 13521136
Nama            : Ammar Rasyad Chaeroel
Tanggal         : 22 September 2022
Topik praktikum : ADT Matrix
Deskripsi       : Praktikum soal 2 submatrix.c
*/
#include <stdio.h>
#include "matrix.h"

Matrix removeRowCols(Matrix m, int row, int col, int M) {
    Matrix result;
    createMatrix(M, M, &result);
    int i, j, k = row, l = col;
    for (i = 0; i < M; i++) {
        for (j = 0; j < M; j++) {
            ELMT(result, i, j) = ELMT(m, k, l);
            l++;
        }
        k++;
        l = col;
    }
    return result;
}

int count(Matrix m) {
	int i, j, count = 0;
	for (i = 0; i < ROW_EFF(m); i++)
	{
		for (j = 0; j < COL_EFF(m); j++)
		{
			if (ELMT(m, i, j)) {
				count++;
			}
		}
	}
	return count;
}

int main() {
	int i, j, N, M, now = 1, daerah = 1, k = 0;
	scanf("%d %d", &N, &M);

	Matrix m;
	readMatrix(&m, N, N);

    for (i = 0; i <= (N-M); i++) {
        for (j = 0; j <= (N-M); j++) {
            Matrix subm = removeRowCols(m, i, j, M);
            if (k < count(subm)) {
                k = count(subm);
                daerah = now;
            }
            now++;
        }
    }
	printf("%d\n", daerah);
	return 0;
}