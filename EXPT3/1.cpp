#include <stdio.h>
int main()
{
	int i,j,n,smallest, count = 0, time; // count -> number of processes completed
	float ATAT,AWT;
	int sumWT=0, sumTAT=0;
	printf("ENTER NO. OF PROCESSES:");
	scanf("%d",&n);
	int waitingTime[n], turnaroundTime[n], completionTime[n] ,arrivalTime[n],priority[n],burstTime[n],Process_no[n];
	int temp_completionTime[n*3] = {0},temp_process_no[n*3] = {0};
	printf("\nENTER AT,BT,PRIORITY\n");
	for(i=0;i<n;i++)
	{
	    printf("\nFor P[%d]\n",(i+1));
	    printf("ENTER ARRIVAL TIME:");
	    scanf("%d",&arrivalTime[i]);
	    printf("ENTER THE BURST TIME:");
	    scanf("%d",&burstTime[i]);
	    printf("ENTER PRIORITY:");
	    scanf("%d",&priority[i]);
	    Process_no[i]=i+1;
	}
    int x[n];
    double avg = 0, tt = 0, end;
    for (i = 0; i < n; i++)
        x[i] = burstTime[i];
    priority[n] = 10000;
    j = 0;
    for (time = 0; count != n; time++)
    {
        smallest = n;
        for (i = 0; i < n; i++)
        {
            if (arrivalTime[i] <= time && priority[i] < priority[smallest] && burstTime[i] > 0)
                smallest = i;
        }
        burstTime[smallest]--;
        if (burstTime[smallest] == 0)
        {
            count++;
            end = time + 1;
            completionTime[smallest] = end;
            waitingTime[smallest] = end - arrivalTime[smallest] - x[smallest];
            turnaroundTime[smallest] = end - arrivalTime[smallest];
        }
        temp_process_no[j] = smallest+1;
        temp_completionTime[j] = j+1;
        j++;
    }
	    printf("\nGANTT CHART:\n");
	    for (i = 0; i < j; i++)
	    {
	        printf("| P%d ", temp_process_no[i]);
	    }
	    printf("|\n0");
	    for (i = 0; i < j; i++)
	    {
	        printf("%5d", i+1);
	    }
    printf("\n\nPROCESS\t\tBT\tAT\tPRIORITY\tCT\tTAT\tAWT\n");
    for (i = 0; i < n; i++)
    {
        printf("p%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1,x[i],arrivalTime[i],priority[i],completionTime[i],turnaroundTime[i], waitingTime[i]);
        avg = avg + waitingTime[i];
        tt = tt + turnaroundTime[i];
    }
    double avgwt=(avg/n);
    double avgtt=(tt/n);
    printf("\n\nAVERAGE WAITING TIME= %.2f" ,avgwt);		
    printf("\nAVERAGE TURNAROUND TIME = %.2f",avgtt);		
    return 0;
}
