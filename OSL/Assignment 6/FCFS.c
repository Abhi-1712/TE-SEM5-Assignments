//  Roll-No: 33231
//  Name: Abhijeet Ingle
//  Batch: K-10

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