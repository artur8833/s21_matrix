#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;
  if ((A == NULL) || (B == NULL) || (result == NULL) || !correct_matrix(*A) ||
      !correct_matrix(*B)) {
    res = INCORRECT_MATRIX;
  } else if ((A->rows != B->rows) || (A->columns != B->columns)) {
    res = CALCULATION_ERROR;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < (A->rows); i++) {
      for (int j = 0; j < (A->columns); j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }
  return res;
}