#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res = 0;
  if ((A == NULL) || !correct_matrix(*A)) {
    res = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    res = CALCULATION_ERROR;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    if (A->rows == 1) {
      result->matrix[0][0] = 1;
    } else {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          matrix_t minor_matrix = create_minor(i, j, A);
          double temp = 0;
          s21_determinant(&minor_matrix, &temp);
          result->matrix[i][j] = pow(-1, (j + i) + 2) * temp;
          s21_remove_matrix(&minor_matrix);
        }
      }
    }
  }
  return res;
}
