//  Roll-No: 33231
//  Name: Abhijeet Ingle
//  Batch: K-10

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
    	
    	for(int i=0;i<frame_size;i++)
    	{
    		frames[i]=0;
    	}
    	
    	float page_faults=0;
    	
    	printf("Enter the pages:");
    	for (int i = 0; i < pages; i++)
	{
		scanf("%d", &page_arr[i]);
        }
        
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        int z=0;
        int j=0;
        
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
		        z=x;
		        frames[z] = page_arr[i];
		    }
		
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