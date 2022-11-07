<h1 align="center">Assignment 6</h1>

#### **_6a - FCFS_**

###### **Code**

`6a.c`

```c
/*
Problem Statement - Implement the C program for Page Replacement Algorithms: FCFS for frame size as minimum three.
*/

#include <stdio.h>

int main()
{
	int pages;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Enter the number of pages\n");
	scanf("%d", &pages);
	int page_arr[pages];

	int frame_size;
	printf("Enter the frame size\n");
    	scanf("%d", &frame_size);
    	int frames[frame_size];

    	for(int i=0;i<frame_size;i++)
    	{
    		frames[i]=0;
    	}

    	float page_faults=0;

    	printf("Enter the pages");
    	for (int i = 0; i < pages; i++)
	{
		scanf("%d", &page_arr[i]);
        }
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	int x=0;
	for(int i=0;i<pages;i++)
	{
		int flag=0;
		for (int j=0;j<frame_size;j++)
		{
			if(page_arr[i]==frames[j])
			{
				flag=1;
			}
		}

		if(flag==0)
		{
			page_faults++;
			frames[x]=page_arr[i];
			x=(x+1)%frame_size;
		}

		printf("Page:%d\n",page_arr[i]);

		printf("Sequence:\n");
		for (int i = 0; i < frame_size; i++)
		{
			printf("%d ", frames[i]);
		}
		printf("\n");
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Total page faults : %f\n", page_faults);
        printf("Page Fault ratio : %f\n", page_faults / pages);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
```

###### **Output**

```text
abhishek-jadhav@abhishek-jadhav-ubuntu:~/Codes/OS Assignments/33232$ ./a.out
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Enter the number of pages
5
Enter the frame size
3
Enter the pages2
3
5
2
3
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Page:2
Sequence:
2 0 0
Page:3
Sequence:
2 3 0
Page:5
Sequence:
2 3 5
Page:2
Sequence:
2 3 5
Page:3
Sequence:
2 3 5
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Total page faults : 3.000000
Page Fault ratio : 0.600000
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
abhishek-jadhav@abhishek-jadhav-ubuntu:~/Codes/OS Assignments/33232$
```

---

#### **_6b - LRU_**

###### **Code**

`6b.c`

```c
/*
Problem Statement - Implement the C program for Page Replacement Algorithms: LRU for frame size as minimum three.
*/

#include <stdio.h>

int main()
{
	int pages;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Enter the number of pages:");
	scanf("%d", &pages);
	int page_arr[pages];

	int frame_size;
	printf("Enter the frame size:");
	scanf("%d", &frame_size);
	int frames[frame_size];

	for (int i = 0; i < frame_size; i++)
	{
		frames[i] = 0;
	}

	float page_faults = 0;

	printf("Enter the pages:");
	for (int i = 0; i < pages; i++)
	{
		scanf("%d", &page_arr[i]);
	}

	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	int z = 0;
	int j = 0;

	for (int i = 0; i < pages; i++)
	{
		int flag = 0;
		for (int j = 0; j < frame_size; j++)
		{

			if (page_arr[i] == frames[j])
			{
				flag = 1;
			}
		}

		if (flag == 0)
		{

			page_faults++;
			if (j < frame_size)
			{
				frames[j] = page_arr[i];
				j++;
			}
			else
			{
				int min = i - 1;
				int x = -1;
				for (int k = 0; k < frame_size; k++)
				{
					for (int j = i - 1; j >= 0; j--)
					{
						if (page_arr[j] == frames[k])
						{
							if (min > j)
							{
								min = j;
								x = k;
							}
							break;
						}
					}
				}
				z = x;
				frames[z] = page_arr[i];
			}
		}

		printf("Page:%d\n", page_arr[i]);

		printf("Sequence:\n");
		for (int i = 0; i < frame_size; i++)
		{
			printf("%d ", frames[i]);
		}
		printf("\n");
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Total page faults : %f\n", page_faults);
	printf("Page Fault ratio : %f\n", page_faults / pages);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
```

###### **Output**

```text
abhishek-jadhav@abhishek-jadhav-ubuntu:~/Codes/OS Assignments/33232$ ./a.out
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Enter the number of pages:5
Enter the frame size:3
Enter the pages:2
3
5
2
3
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Page:2
Sequence:
2 0 0
Page:3
Sequence:
2 3 0
Page:5
Sequence:
2 3 5
Page:2
Sequence:
2 3 5
Page:3
Sequence:
2 3 5
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Total page faults : 3.000000
Page Fault ratio : 0.600000
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
abhishek-jadhav@abhishek-jadhav-ubuntu:~/Codes/OS Assignments/33232$
```

---

#### **_6c - Optimal_**

###### **Code**

`6c.c`

```c
/*
Problem Statement - Implement the C program for Page Replacement Algorithms: Optimal frame size for frame size as minimum three.
*/

#include <stdio.h>

int main()
{
	int pages;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Enter the number of pages\n");
	scanf("%d", &pages);
	int page_arr[pages];

	int frame_size;
	printf("Enter the frame size\n");
	scanf("%d", &frame_size);
	int frames[frame_size];

	for (int i = 0; i < frame_size; i++)
	{
		frames[i] = 0;
	}

	float page_faults = 0;

	printf("Enter the pages");
	for (int i = 0; i < pages; i++)
	{
		scanf("%d", &page_arr[i]);
	}

	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	int z = 0;
	int j = 0;

	for (int i = 0; i < pages; i++)
	{
		int flag = 0;
		for (int j = 0; j < frame_size; j++)
		{

			if (page_arr[i] == frames[j])
			{
				flag = 1;
			}
		}

		if (flag == 0)
		{
			page_faults++;
			int flag1 = 0;
			if (j < frame_size)
			{
				frames[j] = page_arr[i];
				j++;
			}
			else
			{
				int max = i + 1;
				int x = -1;

				for (int k = 0; k < frame_size; k++)
				{
					int j;
					for (j = i + 1; j < pages; j++)
					{
						if (page_arr[j] == frames[k])
						{
							if (max < j)
							{
								max = j;
								x = k;
							}
							break;
						}
					}
					if (j == pages)
					{
						flag1 = 1;
						z = k;
						break;
					}
				}
				if (flag1 != 1)
				{
					z = x;
				}
				frames[z] = page_arr[i];
			}

			printf("Page:%d\n", page_arr[i]);

			printf("Sequence:\n");
			for (int i = 0; i < frame_size; i++)
			{
				printf("%d ", frames[i]);
			}
			printf("\n");
		}
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Total page faults : %f\n", page_faults);
	printf("Page Fault ratio : %f\n", page_faults / pages);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
```

###### **Output**

```text
abhishek-jadhav@abhishek-jadhav-ubuntu:~/Codes/OS Assignments/33232$ ./a.out
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Enter the number of pages
5
Enter the frame size
3
Enter the pages2
3
5
2
3
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Page:2
Sequence:
2 0 0
Page:3
Sequence:
2 3 0
Page:5
Sequence:
2 3 5
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Total page faults : 3.000000
Page Fault ratio : 0.600000
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
abhishek-jadhav@abhishek-jadhav-ubuntu:~/Codes/OS Assignments/33232$
```
