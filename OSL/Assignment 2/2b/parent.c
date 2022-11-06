//  Roll-No: 33231
//  Name: Abhijeet Ingle
//  Batch: K-10

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);

    printf("\n");
}


int main(int argc, char **argv)
{
    
    
    int arr_size;
    printf("Enter array size:\n");
    scanf("%d", &arr_size);

   
    int arr[arr_size];
    printf("Enter array elements:\n");
    for (int i = 0; i < arr_size; i++)
    {
        scanf("%d", &arr[i]);
    }

 

   
    mergeSort(arr, 0, arr_size - 1);

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Sorted array is \n");
    printArray(arr, arr_size);

    //int array to string array
    char strArr[arr_size][1000];
    for (int i = 0; i < arr_size; i++)
    {
        sprintf(strArr[i], "%d", arr[i]);
    }

    
    char *args[arr_size + 2];
    args[0] = "./child.out";   //argument as file name

    
    for (int i = 0; i < arr_size; i++)
    {
        args[i + 1] = strArr[i];  //storing the array
    }

    args[arr_size + 1] = NULL;

    // pass args to next program
    execvp(args[0], args);

    

    return 0;
}