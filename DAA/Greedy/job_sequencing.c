// Greedy problem solving technique

#include <stdlib.h>
#include <stdio.h>

// Given three arrays id[], deadline[], profit[], where each job i is associated with id[i], deadline[i], and profit[i]. Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. You will earn the profit associated with a job only if it is completed by its deadline. The task is to find the maximum profit that can be gained by completing the jobs and the count of jobs completed to earn the maximum profit.

typedef struct Job
{
    int id;
    int profit;
    int deadline;
}Job;

// sequencing the job according to profit only (naive approach)
void sequence_by_profit(Job* arr, int n)
{
    // using literally any standard sorting algo it can be done, gonna be using bubble sort here cuz it is the simpliest

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j].profit < arr[j+1].profit)
            {
                Job temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    // new order

    printf("NEW SEQUENCE OF JOBS\n---------------------------------------");
    for (int i = 0; i < n; i++)
    {
        printf("ID: %d\n",arr[i].id);
        printf("PROFIT: %d\n",arr[i].profit);
        printf("DEADLINE: %d\n\n",arr[i].deadline);
    }
}

// GREEDY approach to scheduling by profit to deadline ratio, the one the that produces the best ratio goes first
void schedule_by_profit_greedy(Job* arr, int n)
{
    
}

int main(int argc, const char* argv[])
{
    int n;
    scanf("%d",&n);

    Job* arr = (Job*)malloc(sizeof(Job) * n); // reserve space for n jobs
    
    for(int i = 0; i < n; i++)
    {
        int id;
        int profit;
        int deadline;

        printf("ENTER ID: ");
        scanf("%d",&id);
        printf("ENTER PROFIT: ");
        scanf("%d",&profit);
        printf("ENTER DEADLINE: ");
        scanf("%d",&deadline);

        arr[i].deadline = deadline;
        arr[i].id = id;
        arr[i].profit = profit;

    }

    printf("ORIGINAL SEQUENCE OF JOBS\n---------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("ID: %d\n",arr[i].id);
        printf("PROFIT: %d\n",arr[i].profit);
        printf("DEADLINE: %d\n\n",arr[i].deadline);
        
    }

    sequence_by_profit(arr,n);
    
}