#include <stdio.h>

#define MAX_SIZE 100

void merge(int a[], int beg, int mid, int end)
{
    int i, j, k;
    int n1 = mid - beg + 1;
    int n2 = end - mid;

    int LeftArray[MAX_SIZE], RightArray[MAX_SIZE]; // fixed-size arrays

    // copy data to temp arrays
    for (i = 0; i < n1; i++)
        LeftArray[i] = a[beg + i];
    for (j = 0; j < n2; j++)
        RightArray[j] = a[mid + 1 + j];

    i = 0;   // initial index of first sub-array
    j = 0;   // initial index of second sub-array
    k = beg; // initial index of merged sub-array

    while (i < n1 && j < n2)
    {
        if (LeftArray[i] <= RightArray[j])
        {
            a[k] = LeftArray[i];
            i++;
        }
        else
        {
            a[k] = RightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        a[k] = LeftArray[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = RightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int beg, int end)
{
    if (beg < end)
    {
        int mid = (beg + end) / 2;
        mergeSort(a, beg, mid);
        mergeSort(a, mid + 1, end);
        merge(a, beg, mid, end);
    }
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE)
    {
        printf("Invalid array size.\n");
        return 1;
    }

    int a[MAX_SIZE];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Before sorting array elements are - \n");
    printArray(a, n);

    mergeSort(a, 0, n - 1);

    printf("After sorting array elements are - \n");
    printArray(a, n);

    return 0;
}
