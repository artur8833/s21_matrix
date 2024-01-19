#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int res = OK;
  if ((A == NULL) || (result == NULL) || !correct_matrix(*A)) {
    res = INCORRECT_MATRIX;
  } else {
    s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < A->columns; i++) {
      for (int j = 0; j < A->rows; j++) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
  }
  return res;
}