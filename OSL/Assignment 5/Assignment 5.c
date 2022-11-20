/*
Problem Statement - Implement C program for Deadlock Avoidance: Banker’sAlgorithm
*/

// #include <bits/stdc++.h>
// using namespace std;
#include <stdio.h>
#define NO_OF_RESOURCE_INSTANCES 3
#define NO_OF_PROCESSES 5

struct process
{
    int rank, allocation[NO_OF_RESOURCE_INSTANCES], max_need[NO_OF_RESOURCE_INSTANCES], need[NO_OF_RESOURCE_INSTANCES];
};

int available[NO_OF_RESOURCE_INSTANCES] = { 2, 1, 0 };
struct process given[NO_OF_PROCESSES] = {
    {0, {1, 1, 2}, {4, 3, 3}, {0}},
    {0, {2, 1, 2}, {3, 2, 2}, {0}},
    {0, {4, 0, 1}, {9, 0, 2}, {0}},
    {0, {0, 2, 0}, {7, 5, 3}, {0}},
    {0, {1, 1, 2}, {1, 1, 2}, {0}} };

void display_resource_instances(int instances[], int no_of_instances)
{
    for (int i = 0; i < no_of_instances; i++)
    {
        printf("%d ", instances[i]);
    }
    return;
}

void display_table(struct process given[])
{
    printf("\n------------------------------------------------");
    printf("\n| Processes | Allocation |   Max   | Available | ");
    printf("\n------------------------------------------------");
    // printf("\n|    P1     |   4 3 3    | 4 3 3 |   2 1 0   |";
    int no_of_completed_processes = 1;
    while (no_of_completed_processes <= NO_OF_PROCESSES)
    {
        int break_while = 1;
        size_t process;
        for (process = 0; process < NO_OF_PROCESSES; process++)
        {
            if (given[process].rank == no_of_completed_processes)
            {
                printf("\n|    P %d     |   ", process + 1);
                display_resource_instances(given[process].allocation, NO_OF_RESOURCE_INSTANCES);
                printf("   |  ");
                display_resource_instances(given[process].max_need, NO_OF_RESOURCE_INSTANCES);
                printf(" |   ");
                display_resource_instances(available, NO_OF_RESOURCE_INSTANCES);
                printf("  |");
                printf("\n------------------------------------------------");
                no_of_completed_processes++;
                break_while = 0;
            }
        }
        if (break_while && (process == NO_OF_PROCESSES))
            break;
    }
    printf("\n");
};

int main()
{
    for (int i = 0; i < NO_OF_PROCESSES; i++)
    {
        for (int j = 0; j < NO_OF_RESOURCE_INSTANCES; j++)
        {
            given[i].need[j] = given[i].max_need[j] - given[i].allocation[j];
        }
    }
    /**
    need[5][3] = {
       3 2 1,
       1 1 0,
       5 0 1,
       7 3 3,
       0 0 0,
    }
    */

    int isSafeState, isStarving, rank = 0;
    // printf("Process sequence: ";
    while (1)
    {
        isSafeState = 0;
        int check_process;
        for (int process = 0; process < NO_OF_PROCESSES; process++)
        {
            if (given[process].rank == 0)
            {
                check_process = 1;
                for (int resource = 0; resource < NO_OF_RESOURCE_INSTANCES; resource++)
                {
                    if (given[process].need[resource] > available[resource])
                    {
                        check_process = 0;
                        break;
                    }
                }
                if (!check_process)
                    continue;
                for (int resource = 0; resource < NO_OF_RESOURCE_INSTANCES; resource++)
                {
                    available[resource] += given[process].allocation[resource];
                    given[process].allocation[resource] += given[process].need[resource];
                    given[process].need[resource] = 0;
                }
                given[process].rank = ++rank;
                display_table(given);
                isSafeState = 1;
                // printf("P" << process + 1 << " ";
            }
        }
        isStarving = 0;
        for (int process = 0; process < NO_OF_PROCESSES; process++)
        {
            if (given[process].rank != 0)
            {
                isStarving++;
            }
            else if (!isSafeState)
            {
                printf("Deadlock condition!\n");
                return 0;
            }
        }
        if (isStarving >= NO_OF_PROCESSES)
        {
            display_table(given);
            printf("\nAll processes finished, CPU in idle state...\n");
            return 0;
        }
    }
};