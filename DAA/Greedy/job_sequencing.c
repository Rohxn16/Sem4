#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct job
{
    int days;
    int profit;
    char* jobname;
}job;

int main(){
    int n;
    scanf("%d",&n);
    int *arr = (int *)malloc(sizeof(int)*n);
    printf("Enter the elements of the job, days and profit");
    job *arr = (job*)malloc(n*sizeof(job));
    for(int i = 0; i < n; i++){
        char* name;
        scanf("%s", &name);
        
    }
}