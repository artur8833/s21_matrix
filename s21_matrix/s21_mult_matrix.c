#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;
  if ((A == NULL) || (B == NULL) || (result == NULL) || !correct_matrix(*A) ||
      !correct_matrix(*B)) {
    res = INCORRECT_MATRIX;
  } else if (A->columns != B->rows) {
    res = CALCULATION_ERROR;
  } else {
    s21_create_matrix(A->rows, B->columns, result);

    for (int i1 = 0, i = 0; i < A->rows; i1++, i++) {
      for (int j2 = 0, j = 0; j2 < B->columns; j2++, j++) {
        for (int j1 = 0, i2 = 0; j1 < A->columns; j1++, i2++)
          result->matrix[i][j] += A->matrix[i1][j1] * B->matrix[i2][j2];
      }
    }
  }
  return res;
}