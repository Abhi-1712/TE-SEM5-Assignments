//  Roll-No: 33231
//  Name: Abhijeet Ingle
//  Batch: K-10

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    /* create temp arrays */
    int L[n1], R[n2];
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
int partition(int array[], int low, int high) { 
  int pivot = array[high]; // select the rightmost element as pivot
  // pointer for greater element
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;   
      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }
  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high]);
  // return the partition point
  return (i + 1);
}
void quickSort(int array[], int low, int high) {
  if (low < high) {
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high);
    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);
    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}
void print_array(int arr[],int n){
	for(int i=0;i<=n;i++)
		printf("%d ",arr[i]);
	printf("\n");

}
void Normal_Execution()
{
	int size;
	printf("Enter array size\n");
	scanf("%d",&size);
	int *arr = (int *)malloc(size * sizeof(int));
	printf("Enter array elements\n");  // input array elements
	for (int i = 0; i < size; i++)
	    scanf("%d", &arr[i]);
	pid_t p=fork();
	if(p==0){
		printf("***********************************************\n");
		printf("This is child process. PID %d\n",getpid());
		printf("Parent Process ID %d\n",getppid());
		printf("Array before sorting:\n");
		print_array(arr,size-1);
		quickSort(arr,0,size-1);
		printf("Array after sorting:\n");
		print_array(arr,size-1);	
	}
	else{
		printf("***********************************************\n");
		printf("This is parent process. PID%d\n",getpid());
		printf("Array before sorting:\n");
		print_array(arr,size-1);
		mergeSort(arr,0,size-1);
		printf("Array after sorting:\n");
		print_array(arr,size-1);
	}
}
void Zombie_Process()
{	
    pid_t child_pid = fork();
    if (child_pid > 0) {
	printf("This is a parent process: %d\n", getpid());
	printf("Before sleep\n");
	system("ps -efl | grep defunct");
	sleep(1);
	printf("After sleep\n");
	system("ps -efl | grep defunct");
    }
    else {
	printf("This is a child process: %d\n", getpid());
	printf("Parent process ID: %d\n", getppid());
	exit(0);
    }
}
void Orphan_Process()
{
	pid_t p;
	p=fork();
	if(p==0)
	{
		
		printf("Child Process ID %d\n",(int)getpid());
		sleep(3);
		printf("Parent Process ID: %d\n",(int)getppid());
		
		system("ps -elf | grep Assignment2.out");
		exit(0);
	}
	else{
		printf("I am parent %d\n",(int)getpid());
	}	
	return;
}
int main()
{	
	int choice;
	do
	{
		printf("\n\n~~~~~~~Enter your choice~~~~~~~~~~\n");
		printf("1.Normal Execution\n");
		printf("2.Zombie Process\n");
		printf("3.Orphan Process\n");
		printf("0.Exit\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Normal Execution\n");
				Normal_Execution();
				break;
			case 2:
				printf("Zombie Process\n");
				Zombie_Process();
				break;
			case 3:
				printf("Orphan Process\n");
				Orphan_Process();
				break;
			case 0:
				printf("Exiting...\n");
				break;
			default:
				printf("Invalid Entry!!!\n");
		}	
	}while(choice!=0);

}