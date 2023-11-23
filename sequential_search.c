
#include <stdio.h>

/* Function for sequential search  */
void sequential_search(int array[], int size, int n)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (array[i] == n)
        {
            printf("%d found at location %d.\n", n, i + 1);
            break;
        }
    }
    if (i == size)
        printf("Not found! %d is not present in the list.\n", n);
}
/*  End of sequential_search()  */

/*  The main() begins  */
int main()
{
    int a[200], i, j, n, size;
    printf("Enter the size of the list:");
    scanf("%d", &size);
    printf("Enter %d Integers in ascending order\n", size);
    for (i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter value to find\n");
    scanf("%d", &n);
    printf("Sequential search\n");
    sequential_search(a, size, n);
    return 0;
}
