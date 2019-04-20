#include <stdio.h>
#include<conio.h>
int current[5][5], maximum_claim[5][5];
int available[5]; //availabel resources
int allocation[5] = {0, 0, 0, 0, 0}; //allocated resources to processes
int max_resources[5]; //maximum resources 
int running[5]; //running process
int safe_state = 0; 
int counter = 0, i, j,exec, resources, processes, k = 1;
 
int main()
{
	printf("***********************************************************************************************************");
	printf("Enter number of processes less than or equal to 5 to get results faster and understand the working easily\n");
	printf("Enter number of processes: \n");
    	scanf("%d", &processes);
 
    	for (i = 0; i < processes; i++) 
	{
        	running[i] = 1;
        	counter++;
    	}
 
    	printf("\nEnter number of resources: "); //how many processes do you want to apply algo to
    	scanf("%d", &resources);
 
    	printf("\nEnter maximum resources:"); //enter the maximum resources
    	for (i = 0; i < resources; i++) 
	{ 
	        scanf("%d", &max_resources[i]);
    	}
 
   	printf("\nEnter Allocated Resources for all your processes:\n");
    	for (i = 0; i < processes; i++) 
	{
	        for(j = 0; j < resources; j++) 
		{
  			scanf("%d", &current[i][j]);
        	}
    	}
 
    	printf("\nEnter Maximum resources for all your processes:\n");
    	for (i = 0; i < processes; i++) 
	{
        	for(j = 0; j < resources; j++) 
		{
            		scanf("%d", &maximum_claim[i][j]);
        	}
    	}
	for (i = 0; i < resources; i++) 
	{
	        printf("\t%d", max_resources[i]);
	}
 
    	printf("\nThe Allocated Resource Table:\n");
    	for (i = 0; i < processes; i++) 
	{
	        for (j = 0; j < resources; j++) 
		{
            		printf("\t%d", current[i][j]);
        	}
		printf("\n");
    	}
 
    	printf("\nThe Maximum Claim Table:\n");
    	for (i = 0; i < processes; i++) 
	{
        	for (j = 0; j < resources; j++) 
		{
		        printf("\t%d", maximum_claim[i][j]);
        	}
        	printf("\n");
    	}
 for (i = 0; i < processes; i++) 
	{
        	for (j = 0; j < resources; j++) 
		{
            		allocation[j] += current[i][j];
        	}
    	}
 
    	printf("\nAllocated resources:");
    	for (i = 0; i < resources; i++) 
	{
        	printf("\t%d", allocation[i]);
    	}
 
    	for (i = 0; i < resources; i++) 
	{
	        available[i] = max_resources[i] - allocation[i];
	}
 
	printf("\nAvailable resources:");
    	for (i = 0; i < resources; i++) 
	{
        	printf("\t%d", available[i]);
    	}
    	printf("\n");
 
    	while (counter != 0) 
	{
        	safe_state = 0;
        	for (i = 0; i < processes; i++) 
		{
            		if (running[i]) 
			{
                		exec = 1;
                		for (j = 0; j < resources; j++) 
				{
                    			if (maximum_claim[i][j] - current[i][j] > available[j]) 
					{
                        			exec = 0;
                        			break;
                    			}
                		}
    	if (exec)                                   //if process gets executed
				{
                    			printf("\nProcess%d is executing\n", i + 1);
                    			running[i] = 0;
                    			counter--;
                    			safe_state = 1;
 
                    			for (j = 0; j < resources; j++) 
					{
                        			available[j] += current[i][j];
                    			}
			                break;
                		}
            		}
        	}
        	if (!safe_state)  //if the system is not in safe state
		{
            		printf("\nThe processes are in unsafe state.\n");
            		break;
        	} 
		else 
		{
            		printf("\nThe process is in safe state");
            		printf("\nAvailable vector:");
 
            		for (i = 0; i < resources; i++) 
			{
                		printf("\t%d", available[i]);
            		}
 
		        printf("\n");
        	}
    	}
   
}
    	return 0;
}
