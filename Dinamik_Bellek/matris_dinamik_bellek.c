#include <stdio.h>
#include <stdlib.h>

int main()
{

    int a[3][4];
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            a[i][j] = i * 10 + j + 1;
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }

    int **m = (int **)malloc(3 * sizeof(int *));

    for (i = 0; i < 3; i++)
    {
        m[i] = (int *)malloc(4 * sizeof(int));
        for (j = 0; j < 4; j++)
        {
            m[i][j] = i * 10 + j + 1;
            printf("%3d", m[i][j]);
        }
        printf("\n");
    }
}
