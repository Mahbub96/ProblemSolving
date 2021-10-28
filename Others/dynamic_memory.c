#include <stdio.h>
#include <malloc.h>

int main()
{
    int n, q, **arr;
    scanf("%d %d", &n, &q);

    arr = (int **)malloc(n * sizeof(int *)); //allocated first index size

    for (int i = 0; i < n; i++)
    {
        int s;
        scanf("%d", &s);
        arr[i] = (int *)malloc(s * sizeof(int *));
        for (int j = 0; j < s; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < q; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d\n", arr[x][y]);
    }
    return 0;
}
