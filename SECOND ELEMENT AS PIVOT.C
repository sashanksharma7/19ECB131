#include <stdio.h>

int main()
{
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if(n <= 0)
    {
        printf("Invalid input");
        return 0;
    }

    int A[n];
    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &A[i]);

    int max = A[0];
    int min = A[0];

    for(i = 1; i < n; i++)
    {
        if(A[i] > max)
            max = A[i];
        if(A[i] < min)
            min = A[i];
    }

    printf("Maximum = %d\n", max);
    printf("Minimum = %d", min);

    return 0;
}
