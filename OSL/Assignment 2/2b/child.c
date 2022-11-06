//  Roll-No: 33231
//  Name: Abhijeet Ingle
//  Batch: K-10


#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main(int argc, char *argv[])
{
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("In the Child file:\n");

    // convert argv to integer array
    int n = argc - 1;
    int arr[n];
    for (int i = 1; i <= n; i++)
    {
        arr[i - 1] = atoi(argv[i]);
    }

    
    int x;
    printf("Enter element to search in array:\n");
    scanf("%d", &x);

  
    int result = binarySearch(arr, 0, n - 1, x);

    
    if (result == -1)
    {
        printf("Element is not present in array!!!\n");
    }
    else
    {
        printf("Element is present at index %d in the array\n", result);
    }

    return 0;
}