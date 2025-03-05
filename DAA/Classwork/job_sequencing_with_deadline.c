#include <stdlib.h>
#include <stdio.h>

typedef struct Job
{
    int id;
    int profit;
    int deadline;
}Job;

Job* schedule_jobs_by_profit(Job* arr, int n)
{
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].profit < arr[j + 1].profit) {
                Job temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    return arr;
}

Job* schedule_jobs_by_deadline(int d_max, Job* arr, int n)
{
    // Sort jobs by profit in descending order
    arr = schedule_jobs_by_profit(arr, n);

    // Array to keep track of free time slots
    int* slots = (int*)malloc(sizeof(int) * d_max);
    for (int i = 0; i < d_max; i++) {
        slots[i] = -1; // Initialize all slots to be free
    }

    // Array to store result (sequence of jobs)
    Job* result = (Job*)malloc(sizeof(Job) * d_max);
    for (int i = 0; i < d_max; i++) {
        result[i].id = 0;
        result[i].profit = 0;
        result[i].deadline = 0;
    }

    // Iterate through all given jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (starting from the last possible slot)
        for (int j = arr[i].deadline - 1; j >= 0; j--) {
            if (j < d_max && slots[j] == -1) {
                slots[j] = i; // Assign this slot to the job
                result[j] = arr[i]; // Add this job to the result
                break;
            }
        }
    }

    free(slots);
    return result;
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the number of jobs to schedule: ");
    scanf("%d", &n);
    printf("\n");

    Job* arr = (Job*)malloc(sizeof(Job) * n);
    
    for (int i = 0; i < n; i++)
    {
        int id, profit, deadline;
        
        printf("ENTER ID: ");
        scanf("%d", &id);
        printf("ENTER PROFIT: ");
        scanf("%d", &profit);
        printf("ENTER DEADLINE: ");
        scanf("%d", &deadline);

        // filling up the array with them jobs from the user input
        arr[i].id = id;
        arr[i].deadline = deadline;
        arr[i].profit = profit;
    }

    // Find the maximum deadline to determine the size of the schedule
    int d_max = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].deadline > d_max) {
            d_max = arr[i].deadline;
        }
    }

    // Schedule the jobs
    Job* scheduled_jobs = schedule_jobs_by_deadline(d_max, arr, n);

    // Print the scheduled jobs
    printf("Scheduled jobs:\n");
    for (int i = 0; i < d_max; i++) {
        if (scheduled_jobs[i].id != 0) {
            printf("Job ID: %d, Profit: %d, Deadline: %d\n", scheduled_jobs[i].id, scheduled_jobs[i].profit, scheduled_jobs[i].deadline);
        }
    }

    free(arr);
    free(scheduled_jobs);
    return 0;
}
