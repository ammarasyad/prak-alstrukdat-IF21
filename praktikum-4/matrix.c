/*
NIM             : 1352136
Nama            : Ammar Rasyad Chaeroel
Tanggal         : 21 September 2022
Topik praktikum : ADT Matrix
Deskripsi       : Implementasi matrix.h
*/

#include <stdio.h>
#include <math.h>
#include "matrix.h"

Matrix removeRowCols(Matrix m, int row, int col);

void createMatrix(int nRows, int nCols, Matrix *m) {
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
}

boolean isMatrixIdxValid(int i, int j) {
    return (i >= 0 && i < ROW_CAP && j >= 0 && j < COL_CAP);
}

IdxType getLastIdxRow(Matrix m) {
    return ROW_EFF(m) - 1;
}

IdxType getLastIdxCol(Matrix m) {
    return COL_EFF(m) - 1;
}

boolean isIdxEff(Matrix m, IdxType i, IdxType j) {
    return (i >= 0 && i <= getLastIdxRow(m) && j >= 0 && j <= getLastIdxCol(m));
}

ElType getElmtDiagonal(Matrix m, IdxType i) {
    return ELMT(m, i, i);
}

void copyMatrix(Matrix mIn, Matrix *mOut) {
    *mOut = mIn;
}

void readMatrix(Matrix *m, int nRow, int nCol) {
    createMatrix(nRow, nCol, m);
    int i, j;
    for (i = 0; i < nRow; i++) {
        for (j = 0; j < nCol; j++) {
            scanf("%d", &ELMT(*m, i, j));
        }
    }
}

void displayMatrix(Matrix m) {
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            if (j < COL_EFF(m) - 1) {
                printf("%d ", ELMT(m, i, j));
            } else {
                printf("%d", ELMT(m, i, j));
            }
        }
        printf("\n");
    }
}

Matrix addMatrix(Matrix m1, Matrix m2) {
    int i, j;
    for (i = 0; i < ROW_EFF(m1); i++) {
        for (j = 0; j < COL_EFF(m1); j++) {
            ELMT(m1, i, j) += ELMT(m2, i, j);
        }
    }
    return m1;
}

Matrix subtractMatrix(Matrix m1, Matrix m2) {
    int i, j;
    for (i = 0; i < ROW_EFF(m1); i++) {
        for (j = 0; j < COL_EFF(m1); j++) {
            ELMT(m1, i, j) -= ELMT(m2, i, j);
        }
    }
    return m1;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2) {
    Matrix m;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &m);
    int i, j, k;
    for (i = 0; i < ROW_EFF(m1); i++) {
        for (j = 0; j < COL_EFF(m2); j++) {
            ELMT(m, i, j) = 0;
            for (k = 0; k < COL_EFF(m1); k++) {
                ELMT(m, i, j) += ELMT(m1, i, k) * ELMT(m2, k, j);
            }
        }
    }
    return m;
}

Matrix multiplyByConst(Matrix m, ElType x) {
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            ELMT(m, i, j) *= x;
        }
    }
    return m;
}

void pMultiplyByConst(Matrix *m, ElType k) {
    int i, j;
    for (i = 0; i < ROW_EFF(*m); i++) {
        for (j = 0; j < COL_EFF(*m); j++) {
            ELMT(*m, i, j) *= k;
        }
    }
}

boolean isMatrixEqual(Matrix m1, Matrix m2) {
    if (!isMatrixSizeEqual(m1, m2)) {
        return false;
    }
    int i, j;
    for (i = 0; i < ROW_EFF(m1); i++) {
        for (j = 0; j < COL_EFF(m1); j++) {
            if (ELMT(m1, i, j) != ELMT(m2, i, j)) {
                return false;
            }
        }
    }
    return true;
}

boolean isMatrixNotEqual(Matrix m1, Matrix m2) {
    return !isMatrixEqual(m1, m2);
}

boolean isMatrixSizeEqual(Matrix m1, Matrix m2) {
    return (ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2));
}

int countElmt(Matrix m) {
    return ROW_EFF(m) * COL_EFF(m);
}

boolean isSquare(Matrix m) {
    return (ROW_EFF(m) == COL_EFF(m));
}

boolean isSymmetric(Matrix m) {
    if (!isSquare(m)) {
        return false;
    }
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            if (ELMT(m, i, j) != ELMT(m, j, i)) {
                return false;
            }
        }
    }
    return true;
}

boolean isIdentity(Matrix m) {
    if (!isSquare(m)) {
        return false;
    }
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            if (i == j) {
                if (ELMT(m, i, j) != 1) {
                    return false;
                }
            } else {
                if (ELMT(m, i, j) != 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

boolean isSparse(Matrix m) {
    int i, j;
    float count = 0;
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            if (ELMT(m, i, j) != 0) {
                count++;
            }
        }
    }
    return (count / (float) countElmt(m) <= 0.05f);
}

Matrix negation(Matrix m) {
    return multiplyByConst(m, -1);
}

void pNegation(Matrix *m) {
    pMultiplyByConst(m, -1);
}

float determinant(Matrix m) {
    if (ROW_EFF(m) == 1) {
        return ELMT(m, 0, 0);
    }
    if (ROW_EFF(m) == 2) {
        return ELMT(m, 0, 0) * ELMT(m, 1, 1) - ELMT(m, 0, 1) * ELMT(m, 1, 0);
    }
    int i;
    float det = 0;
    for (i = 0; i < ROW_EFF(m); i++) {
        det += (float) pow(-1, i) * ELMT(m, 0, i) * determinant(removeRowCols(m, 0, i));
    }
    return det;
}

Matrix transpose(Matrix m) {
    Matrix mOut;
    createMatrix(COL_EFF(m), ROW_EFF(m), &mOut);
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            ELMT(mOut, i, j) = ELMT(m, j, i);
        }
    }
    return mOut;
}

void pTranspose(Matrix *m) {
    int i, j;
    Matrix mOut;
    copyMatrix(*m, &mOut);
    for (i = 0; i < ROW_EFF(*m); i++) {
        for (j = 0; j < COL_EFF(*m); j++) {
            ELMT(*m, i, j) = ELMT(mOut, j, i);
        }
    }
}


Matrix removeRowCols(Matrix m, int row, int col) {
    Matrix result;
    createMatrix(ROW_EFF(m) - 1, COL_EFF(m) - 1, &result);
    int i, j, k = 0, l = 0;
    for (i = 0; i < ROW_EFF(m); i++) {
        if (i != row) {
            for (j = 0; j < COL_EFF(m); j++) {
                if (j != col) {
                    ELMT(result, k, l) = ELMT(m, i, j);
                    k = (k + 1) % (ROW_EFF(m) - 1);
                    if (k == 0) {
                        l++;
                    }
                }
            }
        }
    }
    return result;
}

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
    for (j = 0; j < COL_EFF(m); j++)
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
    for (i = 0; i < ROW_EFF(m); i++)
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
    for (i = 0; i < ROW_EFF(m); i++)
    {
        if (ELMT(m, i, j) == X) {
            count++;
        }
    }
    return count;
}

void RotateMat(Matrix *m) {
    int i, row = 0, col = 0, effX = ROW_EFF(*m), effY = COL_EFF(*m);
    ElType temp1, temp2;
    if (ROW_EFF(*m) > 3 && COL_EFF(*m) > 3) {
        while (row < ROW_EFF(*m) - 1 && col < COL_EFF(*m) - 1) {
            temp1 = ELMT(*m, row + 1, col);
            for (i = col; i < effY; i++) {
                temp2 = ELMT(*m, row, i);
                ELMT(*m, row, i) = temp1;
                temp1 = temp2;
            }
            row++;

            for (i = row; i < effX; i++) {
                temp2 = ELMT(*m, i, effY - 1);
                ELMT(*m, i, effY - 1) = temp1;
                temp1 = temp2;
            }
            effY--;

            if (row < effX) {
                for (i = effY - 1; i >= col; i--) {
                    temp2 = ELMT(*m, effX - 1, i);
                    ELMT(*m, effX - 1, i) = temp1;
                    temp1 = temp2;
                }
            }
            effX--;

            if (col < effY) {
                for (i = effX - 1; i >= row; i--) {
                    temp2 = ELMT(*m, i, col);
                    ELMT(*m, i, col) = temp1;
                    temp1 = temp2;
                }
            }
            col++;
        }
    } else if (ROW_EFF(*m) == 3 && COL_EFF(*m) == 3) {
        temp1 = ELMT(*m, 0, 0);
        temp2 = ELMT(*m, 0, 1);
        ELMT(*m, 0, 0) = ELMT(*m, 1, 0);
        ELMT(*m, 1, 0) = ELMT(*m, 2, 0);
        ELMT(*m, 2, 0) = ELMT(*m, 2, 1);
        ELMT(*m, 0, 1) = temp1;

        temp1 = ELMT(*m, 0, 2);
        ELMT(*m, 2, 1) = ELMT(*m, 2, 2);
        ELMT(*m, 2, 2) = ELMT(*m, 1, 2);
        ELMT(*m, 1, 2) = ELMT(*m, 0, 2);
        ELMT(*m, 0, 2) = temp2;
    } else if (ROW_EFF(*m) == 2 && COL_EFF(*m) == 2) {
        temp1 = ELMT(*m, 0, 0);
        ELMT(*m, 0, 0) = ELMT(*m, 1, 0);
        ELMT(*m, 1, 0) = ELMT(*m, 1, 1);
        ELMT(*m, 1, 1) = ELMT(*m, 0, 1);
        ELMT(*m, 0, 1) = temp1;
    }
}