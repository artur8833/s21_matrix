#include "../s21_matrix.h"

int correct_matrix(matrix_t A) {
  int res = 0;
  if (A.matrix != NULL && A.columns > 0 && A.rows > 0) {
    res = 1;
  }
  return res;
}

matrix_t create_minor(int i, int j, matrix_t *A) {
  matrix_t minor = {0};
  s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
  int k = 0, m = 0;
  for (int l = 0; l < A->rows; l++) {
    for (int n = 0; n < A->columns; n++) {
      if (n != j && l != i) {
        minor.matrix[k][m] = A->matrix[l][n];
        m++;
        if (m == A->columns - 1) {
          k++;
          m = 0;
        }
      }
    }
  }
  return minor;
}