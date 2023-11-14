#include <stdio.h>

int main()
{
    int matrix[5][5], row, col;

    printf("input the order of matrix. max 5 x 5 \n");
    scanf("%d %d", &row, &col);

    printf("enter the elements of matrix: \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("the 3-tuple representation of matrix is: \n");

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] != 0)
                printf("%d %d %d \n", i + 1, j + 1, matrix[i][j]);
        }
    }
    return 0;
}