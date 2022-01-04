#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <time.h>
void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
}
double FCFS(int task) {
	printf("\n\t\t\t\tFirst Come First Serve for %d Task\n",task);
	delay(1);
    srand(time(NULL));
    int i,j,n=task;
    int etime[n],wt[n];
    double avwt=0;
    for(i=0; i<n; i++) {
        etime[i]=rand()%100;
    }
    wt[0]=0;
    for(i=1; i<n; i++)
    {
        wt[i]=wt[i-1]+etime[i-1];
        avwt+=wt[i];
    }
    avwt=avwt/n;
    printf("\nTASK\tWaiting Time\tExecute Time\n\n");
    for(i=0; i<n; i++) {
        printf("T%d\t\t%d\t\t%d\n",i,wt[i],etime[i]);
    }
    return avwt;
}
double SJF(int task) {
	printf("\n\t\t\t\tShort Job First for %d Task\n",task);
	delay(1);
    int n=task;
    int bt[n],p[n],wt[n],i,j,total=0,pos,temp;
    float avg_wt;
    srand(time(NULL));
    for(i=0; i<n; i++) {
        bt[i]=rand()%100;
        p[i]=i+1;
    }
    for(i=0; i<n; i++)
        for(i=0; i<n; i++)
        {
            pos=i;
            for(j=i+1; j<n; j++)
            {
                if(bt[j]<bt[pos])
                    pos=j;
            }
            temp=bt[i];
            bt[i]=bt[pos];
            bt[pos]=temp;
            temp=p[i];
            p[i]=p[pos];
            p[pos]=temp;
        }
    wt[0]=0;
    for(i=1; i<n; i++)
    {
        wt[i]=0;
        for(j=0; j<i; j++)
            wt[i]+=bt[j];
        total+=wt[i];
    }
    avg_wt=(float)total/n;
    total=0;
    printf("\nTASK\tWaiting time\tExecute time");
    for(i=0; i<n; i++)
    {
        printf("\nT%d\t\t %d\t\t %d",p[i],wt[i],bt[i]);
    }
    return avg_wt;
}
double PS(int task){
	printf("\n\t\t\t\tPriority Scheduling for %d Task\n",task);
	delay(1);
	srand(time(NULL));
	int n=task;
	int bt[n],p[n],wt[n],pr[n],i,j,pos,temp;
	unsigned long total=0;
	long double avg_wt;
	for(i=0; i<n; i++) {
        bt[i]=rand()%100;
        p[i]=i+1;
        pr[i]=rand()%6;
    }
for(i=0; i<n; i++)
{
    pos=i;
    for(j=i+1; j<n; j++)
    {
        if(pr[j]>pr[pos])
            pos=j;
    }
    temp=pr[i];
    pr[i]=pr[pos];
    pr[pos]=temp;
    temp=bt[i];
    bt[i]=bt[pos];
    bt[pos]=temp;
    temp=p[i];
    p[i]=p[pos];
    p[pos]=temp;
}
wt[0]=0;
for(i=1; i<n; i++)
{
    wt[i]=0;
    for(j=0; j<i; j++)
        wt[i]+=bt[j];
    total+=wt[i];
}
avg_wt=total/n;
printf("\nTask\tExecute Time\tWaiting Time\tPriority");
for(i=0; i<n; i++)
{
    printf("\nT%d\t\t %d\t\t %d\t\t%d",p[i],bt[i],wt[i],pr[i]);
}
//printf("\n%l\n",total);
return avg_wt;
}

double rr(int a)
{
	
	printf("\n\t\t\t\tRound Robin for %d Task\n",a);
	delay(1);
    long et[a], wt[a], count, rt, i, j, totwt = 0, m;
    int pt[a], time_quantum = (rand() % 10)+1;
    float avgwt;
    for (i = 0; i < a; i++) {

        pt[i] = rand() % 100;
    }
    m = a;
    wt[0] = 0;
    i = 0;
    do {
        if (pt[i] > time_quantum) {
            rt = pt[i] - time_quantum;

            pt[a] = rt;
            et[i] = time_quantum;
        } else {
            et[i] = pt[i];
        }
        i++;
        wt[i] = wt[i - 1] + et[i - 1];
    } while (i < a);

    count = 0;
	printf("\nTask\tExecute Time\tWaiting Time\n");
    for (i = 0; i < m; i++) {
    	printf("T%d\t|\t%d\t|\t%d\n",i,pt[i],wt[i]);
        totwt += wt[i];
    }
    avgwt = (float) totwt / m;
    return avgwt;
}

int main()
	

{
	double fcfs10=FCFS(10);
    double sjf10=SJF(10);
    double ps10=PS(10);
    double rr10=rr(10);
    printf("\nFirst Come First Serve Average waiting time: %.2f",fcfs10);
    printf("\nShort Job First Average Waiting Time=%.2f",sjf10);
    printf("\nPriority Scheduling Average Waiting Time=%.2f",ps10);
	printf("\nRound Robin Average Waiting Time=%.2f",rr10);
	
	//LOOP
	while(1){
	int x;
	printf("\n\n\nTask size(Example 10,100,1000,10000) Input=");
	scanf("%d",&x);
    double fcfs=FCFS(x);
    double sjf=SJF(x);
    double ps=PS(x);
    double a=rr(x);
    printf("\nFirst Come First Serve Average waiting time: %.2f",fcfs);
    printf("\nShort Job First Average Waiting Time=%.2f",sjf);
    printf("\nPriority Scheduling Average Waiting Time=%.2f",ps);
	printf("\nRound Robin Average Waiting Time=%.2f",a);
    }
    return 0;
}
