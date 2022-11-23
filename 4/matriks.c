/*
NIM             : 13521136
Nama            : Ammar Rasyad Chaeroel
Tanggal         : 22 September 2022
Topik praktikum : ADT Matrix
Deskripsi       : Praktikum soal 1 matriks.c
*/

#include <stdio.h>
#include "matrix.h"

float AvgRow(Matrix m, IdxType i) {
	float avg = 0.0f;
	int j;
	for (j = 0; j < COL_EFF(m); j++)
	{
		avg += ELMT(m, i, j);
	}
	return avg / ((float) COL_EFF(m));
}

float AvgCol(Matrix m, IdxType j) {
	float avg = 0.0f;
	int i;
	for (i = 0; i < ROW_EFF(m); i++)
	{
		avg += ELMT(m, i, j);
	}
	return avg / ((float) ROW_EFF(m));
}

void MinMaxRow(Matrix m, IdxType i, ElType *max, ElType *min) {
	*max = ELMT(m, i, 0);
	*min = ELMT(m, i, 0);
	int j;
	for (j = 0; j < ROW_EFF(m); j++)
	{
		if (ELMT(m, i, j) > *max) {
			*max = ELMT(m, i, j);
		}
		if (ELMT(m, i, j) < *min) {
			*min = ELMT(m, i, j);
		}
	}
}

void MinMaxCol(Matrix m, IdxType j, ElType *max, ElType *min) {
	*max = ELMT(m, 0, j);
	*min = ELMT(m, 0, j);
	int i;
	for (i = 0; i < COL_EFF(m); i++)
	{
		if (ELMT(m, i, j) > *max) {
			*max = ELMT(m, i, j);
		}
		if (ELMT(m, i, j) < *min) {
			*min = ELMT(m, i, j);
		}
	}
}

int CountNumRow(Matrix m, IdxType i, ElType X) {
	int j, count = 0;
	for (j = 0; j < COL_EFF(m); j++)
	{
		if (ELMT(m, i, j) == X) {
			count++;
		}
	}
	return count;
}

int CountNumCol(Matrix m, IdxType j, ElType X) {
	int i, count = 0;
	for (i = 0; i < COL_EFF(m); i++)
	{
		if (ELMT(m, i, j) == X) {
			count++;
		}
	}
	return count;
}

void RotateMat(Matrix *m) {
	int i, j, row = 0, col = 0, effX = ROW_EFF(*m), effY = COL_EFF(*m);
	boolean go = true;
	ElType temp1, temp2;
	if (ROW_EFF(*m) > 2 && COL_EFF(*m) > 2) {
		while (row < ROW_EFF(*m) && col < COL_EFF(*m) && go) {
			if (row + 1 == ROW_EFF(*m) || col + 1 == COL_EFF(*m)) {
				go = false;
			}
			temp1 = ELMT(*m, row + 1, col);
			for (i = 0; i < effX; i++)
			{
				temp2 = ELMT(*m, row, i);
				ELMT(*m, row, i) = temp1;
				temp1 = temp2;
			}
			row++;

			for (i = 0; i < effY; i++)
			{
				temp2 = ELMT(*m, i, effY - 1);
				ELMT(*m, i, effY - 1) = temp1;
				temp1 = temp2;
			}
			effY--;

			if (row < effX) {
				for (i = effY - 1; i >= col; i--)
				{
					temp2 = ELMT(*m, effX - 1, i);
					ELMT(*m, effX - 1, i) = temp1;
					temp1 = temp2;
				}
			}
			effX--;
			if (col < effY) {
				for (i = effX - 1; i >= row; i--)
				{
					temp2 = ELMT(*m, i, col);
					ELMT(*m, i, col) = temp1;
					temp1 = temp2;
				}
			}
			col++;
		}

	} else if (ROW_EFF(*m) == 2 && COL_EFF(*m) == 2)  {
		temp1 = ELMT(*m, 0, 0);
		ELMT(*m, 0, 0) = ELMT(*m, 1, 0);
		temp2 = ELMT(*m, 0, 1);
		ELMT(*m, 0, 1) = temp1;
		temp1 = ELMT(*m, 1, 1);
		ELMT(*m, 0, 1) = temp2;
		ELMT(*m, 1, 0) = temp1;
	} else {

	}
}

int main() {
	Matrix m;
	readMatrix(&m, 3, 3);
	RotateMat(&m);
	displayMatrix(m);
	return 0;
}