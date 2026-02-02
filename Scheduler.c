#include <stdio.h>
#include <stdlib.h>

//Priority Scheduling Algorithm (Non-Preemptive).
// Lower priority number means higher priority.

typedef struct
{
int pid;
int burst;
int waiting;
int turnaround;
int priority;
} process;

void sort ( process processes[] ,int z)
{
process temp;
    for ( int i = 0; i < z-1 ;i++)
    {
      for ( int j = 0; j < z - i - 1 ; j++)
      {
        if (processes[j].priority > processes[j+1].priority)
        {
           temp = processes[j];
           processes[j] = processes[j+1];
           processes[j+1] = temp;
        }


      }


    }


}

int main()
{
    int n , i ;
    int sum1 = 0;
    float sum2 = 0 , sum3 = 0;

    printf("Enter The Number Of Processes: ");
    scanf("%d",&n);

    process processes[n];

    for (i = 0 ; i < n ; i++)
    {
    printf("Enter the ID Of Process %d: ",i+1);
    scanf("%d",&processes[i].pid);
    printf("Enter The Burst Time Of Process %d: ",i+1);
    scanf("%d",&processes[i].burst);
    printf("Enter The Priority Of Process %d: ",i+1);
    scanf("%d",&processes[i].priority);
    }

    sort (processes , n);

    for (i = 0 ; i < n ; i++)
    {
    processes[i].waiting = sum1;
    sum1 += processes[i].burst;
    processes[i].turnaround = processes[i].burst + processes[i].waiting;
    sum2 += processes[i].waiting;
    sum3 += processes[i].turnaround;
    }

    printf("\n\t\t---------------------------------------------------------------\n");
    printf("\t\t %-5s | %-7s | %-8s | %-8s | %-10s\n","PID", "Burst", "Priority", "Waiting", "Turnaround");
    printf("\t\t---------------------------------------------------------------\n");
    for ( int i = 0 ; i < n ; i++)
    {
    printf("\t\t %-5d | %-7d | %-8d | %-8d | %-10d\n",
       processes[i].pid,
       processes[i].burst,
       processes[i].priority,
       processes[i].waiting,
       processes[i].turnaround);
    }
    printf("\t\t--------------------------------------------------------------\n");
    printf("\t\tAverage Waiting Time = %.2f\n",sum2/n);
    printf("\t\tAverage Turnaround Time = %.2f\n",sum3/n);
    return 0;
}
