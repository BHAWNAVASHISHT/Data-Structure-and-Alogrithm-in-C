/*6.Write a program to accept a matrix from user,
find out matrix is sparse or not and convert into triplex matrix.*/
#include <stdio.h>
void check_sparse(int matrix[20][20], int num_rows, int num_cols) {
    int zero_count = 0, row, col;
    for (row = 0; row < num_rows; row++) {
        for (col = 0; col < num_cols; col++) {
            if (matrix[row][col] == 0)
                zero_count++;
        }
    }
    if (zero_count > (num_rows * num_cols) / 2) {
        printf("The matrix is sparse.\n");
    } else {
        printf("The matrix is not sparse.\n");
    }
}

void convert_to_triplex(int matrix[20][20], int num_rows, int num_cols) {
    int row, col, non_zero_count = 0;
    int triplet_matrix[20][3];
    for (row = 0; row < num_rows; row++) {
        for (col = 0; col < num_cols; col++) {
            if (matrix[row][col] != 0) {
                triplet_matrix[non_zero_count][0] = row;
                triplet_matrix[non_zero_count][1] = col;
                triplet_matrix[non_zero_count][2] = matrix[row][col];
                non_zero_count++;
            }
        }
    }
    printf("\nTriplex Matrix (Row, Column, Value):\n");
    printf("Row\tColumn\tValue\n");
    for (row = 0; row < non_zero_count; row++) {
        printf("%d\t%d\t%d\n", triplet_matrix[row][0], triplet_matrix[row][1], triplet_matrix[row][2]);
    }
}

int main() {
    int num_rows, num_cols, row, col;
    int matrix[20][20];
    printf("Enter the number of rows: ");
    scanf("%d", &num_rows);
    printf("Enter the number of columns: ");
    scanf("%d", &num_cols);
    
    printf("Enter the elements of the matrix:\n");
    for (row = 0; row < num_rows; row++) {
        for (col = 0; col < num_cols; col++) {
            scanf("%d", &matrix[row][col]);
        }
    }

    check_sparse(matrix, num_rows, num_cols);
    convert_to_triplex(matrix, num_rows, num_cols);
    return 0;
}
