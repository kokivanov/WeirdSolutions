#include "headers/Header.h"

#define INVALID "Invalid size"
#define CORRECT "Correct size"

struct Matrix { 
    int rows;
    int columns;
    char status[20];
    int **values;
};
struct Matrix setValues(int m, int n, const char status[20]) {
  printf("Label 2\n"); struct Matrix newMatrix;
  newMatrix.rows = m; newMatrix.columns = n;
  strcpy_s(newMatrix.status, status);
  return newMatrix;
}
struct Matrix enterMatrixSize() {
  printf("Label 1\n"); int m = -1; int n = -1;
  if (scanf_s("%d %d", &m, &n) != 2)  {
    printf("Invalid size of matrix\n");
    return setValues(m, n, INVALID);
  }
  return setValues(m, n, CORRECT);
}
void initMatrix(struct Matrix *matrix) {
    printf("Label 3\n"); srand(time(NULL));
    printf("Size of pointer = %d\n", sizeof(int*));
    printf("Size of int = %d\n", sizeof(int));
    int** values = (int**)calloc(matrix->rows, sizeof(int*));
    for (int i = 0; i < matrix->rows; ++i) { //Init rows
        values[i] = (int*)calloc(matrix->columns, sizeof(int));//Init cols
        for (int j = 0; j < matrix->columns; ++j) {
            values[i][j] = rand() % 100 - 50;
        }
    }
    matrix->values = values;
}
void printArray(struct Matrix matrix) {
    printf("Dynamic MAtrix: \n");
    printf("Rows = %d\n", matrix.rows);
    printf("Cols = %d\n", matrix.columns);
    for (int i = 0; i < matrix.rows; ++i) {
      for (int j = 0; j < matrix.columns; ++j) {
          printf("%4d%c", matrix.values[i][j],
              (j < matrix.columns - 1) ? '\t' : '\n');
      }
    }
    printf("\n");
}
void free_M(struct Matrix *arr) {
  for (int i = 0; i < arr->rows; ++i) {
    free(arr->values[i]);
  }
  free(arr->values);
}
void exMatrix() {
    printf("Please enter the size of matrix\n");
    struct Matrix mainMatrix = enterMatrixSize();
    printf("Test matrix rows %4d\n", mainMatrix.rows);
    printf("Test matrix cols %4d\n", mainMatrix.columns);
    printf("Test matrix status %4s\n", mainMatrix.status);

    if (strcmp(mainMatrix.status, INVALID) == 0) {
      printf("Label 0\n");
    }

    auto start = std::chrono::steady_clock::now(); // get time of start program

    int counter = 100000;
    while(counter > 0) {
        initMatrix(&mainMatrix);
        printArray(mainMatrix);
        free_M(&mainMatrix);
        // Task: implement freeMatrix(mainMatrix);
        counter--;  
    }

    auto end = std::chrono::steady_clock::now(); // get time of end program 

    double elasped_time = double(std::chrono::duration_cast <std::chrono::nanoseconds> (end - start).count()); // count time elapsed since program start

    printf("\nElapsed time (ms): %.3f \n", elasped_time / 1e6);

}

