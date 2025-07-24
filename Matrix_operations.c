/*5.Write a program which has menu showing Transpose, Addition, Subtraction and Product of
 Matrices and perform the corresponding operation on choosing
(implement the program using functions).*/
#include <stdio.h>
void transpose(int arr[20][20], int rows, int cols) {
    int temp[20][20], i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            temp[j][i] = arr[i][j];
        }
    }

    printf("\nTransposed Matrix:\n");
    for (i = 0; i < cols; i++) {
        for (j = 0; j < rows; j++) {
            printf("%d ", temp[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(int arr1[20][20], int arr2[20][20], int rows, int cols) {
    int sum[20][20], i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            sum[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    printf("\nSum of Matrices:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
}

void subtract_matrices(int arr1[20][20], int arr2[20][20], int rows, int cols) {
    int diff[20][20], i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            diff[i][j] = arr1[i][j] - arr2[i][j];
        }
    }

    printf("\nDifference of Matrices:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", diff[i][j]);
        }
        printf("\n");
    }
}

void multiply_matrices(int arr1[20][20], int arr2[20][20], int rows1, int cols1, int rows2, int cols2) {
    if (cols1 != rows2) {
        printf("\nMatrix multiplication not possible! Columns of first matrix must equal rows of second matrix.\n");
        return;
    }

    int product[20][20], i, j, k;

    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            product[i][j] = 0;
            for (k = 0; k < cols1; k++) {
                product[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    printf("\nProduct of Matrices:\n");
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int choice;

    do {
        printf("\nMENU:\n");
        printf("1. Transpose of a Matrix\n");
        printf("2. Add two Matrices\n");
        printf("3. Subtract two Matrices\n");
        printf("4. Multiply two Matrices\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int rows, cols, i, j;
                int arr[20][20];
                printf("Enter the number of rows: ");
                scanf("%d", &rows);
                printf("Enter the number of columns: ");
                scanf("%d", &cols);
                printf("Enter the elements of the matrix:\n");
                for (i = 0; i < rows; i++) {
                    for (j = 0; j < cols; j++) {
                        scanf("%d", &arr[i][j]);
                    }
                }
                transpose(arr, rows, cols);
                break;
            }

            case 2: {
                int rows, cols, i, j;
                int arr1[20][20], arr2[20][20];
                printf("Enter the number of rows: ");
                scanf("%d", &rows);
                printf("Enter the number of columns: ");
                scanf("%d", &cols);
                printf("Enter the elements of the first matrix:\n");
                for (i = 0; i < rows; i++) {
                    for (j = 0; j < cols; j++) {
                        scanf("%d", &arr1[i][j]);
                    }
                }
                printf("Enter the elements of the second matrix:\n");
                for (i = 0; i < rows; i++) {
                    for (j = 0; j < cols; j++) {
                        scanf("%d", &arr2[i][j]);
                    }
                }
                add_matrices(arr1, arr2, rows, cols);
                break;
            }

            case 3: {
                int rows, cols, i, j;
                int arr1[20][20], arr2[20][20];
                printf("Enter the number of rows: ");
                scanf("%d", &rows);
                printf("Enter the number of columns: ");
                scanf("%d", &cols);
                printf("Enter the elements of the first matrix:\n");
                for (i = 0; i < rows; i++) {
                    for (j = 0; j < cols; j++) {
                        scanf("%d", &arr1[i][j]);
                    }
                }
                printf("Enter the elements of the second matrix:\n");
                for (i = 0; i < rows; i++) {
                    for (j = 0; j < cols; j++) {
                        scanf("%d", &arr2[i][j]);
                    }
                }
                subtract_matrices(arr1, arr2, rows, cols);
                break;
            }

            case 4: {
                int rows1, cols1, rows2, cols2, i, j;
                int arr1[20][20], arr2[20][20];
                printf("Enter the number of rows and columns for the first matrix: ");
                scanf("%d%d", &rows1, &cols1);
                printf("Enter the number of rows and columns for the second matrix: ");
                scanf("%d%d", &rows2, &cols2);
                printf("Enter the elements of the first matrix:\n");
                for (i = 0; i < rows1; i++) {
                    for (j = 0; j < cols1; j++) {
                        scanf("%d", &arr1[i][j]);
                    }
                }
                printf("Enter the elements of the second matrix:\n");
                for (i = 0; i < rows2; i++) {
                    for (j = 0; j < cols2; j++) {
                        scanf("%d", &arr2[i][j]);
                    }
                }
                multiply_matrices(arr1, arr2, rows1, cols1, rows2, cols2);
                break;
            }

            case 5:
                printf("Exiting the program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}
