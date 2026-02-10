#include <stdio.h>

struct Process {
    int pid;
    int at;
    int bt;
    int rt;
    int ct;
    int tat;
    int wt;
    int started;
};

int main() {
    // Process data: PID, Arrival Time, Burst Time
    struct Process p[3] = {
        {1, 0, 10},
        {2, 2, 20},
        {3, 6, 30}
    };
    
    int n = 3;
    int time = 0;
    int completed = 0;
    int context_switch = 0;
    int prev = -1;
    int total_wt = 0, total_tat = 0;
    
    printf("=========================================\n");
    printf("   SJF PREEMPTIVE SCHEDULING ALGORITHM  \n");
    printf("=========================================\n\n");
    
    // Initialize remaining time = burst time
    int i=0;
	for(i=0; i<n; i++) {
        p[i].rt = p[i].bt;
        p[i].started = 0;
    }
    
    // Display input processes
    printf("INPUT PROCESSES:\n");
    printf("PID\tArrival\tBurst\n");
    printf("-------------------\n");
	for(i=0; i<n; i++) {
        printf("P%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt);
    }
    
    printf("\nEXECUTION SEQUENCE (Gantt Chart):\n");
    printf("Time\tProcess\tRemaining\tComparison Log\n");
    printf("----\t-------\t---------\t---------------\n");
    
    // SJF Preemptive Algorithm
    while(completed < n) {
        int idx = -1;
        int min_rt = 1000;
        
        // Find process with shortest remaining time
        int i=0;
		for(i=0; i<n; i++) {
            if(p[i].at <= time && p[i].rt > 0) {
                if(p[i].rt < min_rt) {
                    min_rt = p[i].rt;
                    idx = i;
                }
            }
        }
        
        // Check for arrivals and show comparison
        char comparison_log[100] = "";
        for(i=0; i<n; i++) {
            if(p[i].at == time && idx != -1 && i != idx && p[idx].rt > 0) {
                if(p[i].rt < p[idx].rt) {
                    sprintf(comparison_log, "P%d (RT=%d) < P%d (RT=%d) : Preempt!", 
                            p[i].pid, p[i].rt, p[idx].pid, p[idx].rt);
                } else {
                    sprintf(comparison_log, "P%d (RT=%d) : P%d (RT=%d) : Continue P%d", 
                            p[i].pid, p[i].rt, p[idx].pid, p[idx].rt, p[idx].pid);
                }
            }
        }
        
        if(idx != -1) {
            // Count context switch
            if(prev != idx && prev != -1) {
                context_switch++;
            }
            prev = idx;
            
            printf("%d\tP%d\t%d\t\t%s\n", time, p[idx].pid, p[idx].rt, comparison_log);
            
            // Execute for 1 time unit
            p[idx].rt--;
            time++;
            
            // If process completed
            if(p[idx].rt == 0) {
                p[idx].ct = time;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
                completed++;
                
                total_wt += p[idx].wt;
                total_tat += p[idx].tat;
            }
        } else {
            printf("%d\tIdle\t-\t\t%s\n", time, comparison_log);
            time++;
        }
    }
    
    printf("\n=========================================\n");
    printf("           RESULTS & CALCULATIONS       \n");
    printf("=========================================\n\n");
    
    printf("PROCESS EXECUTION DETAILS:\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    printf("-------------------------------------------\n");
    
    for(i=0; i<n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt,
               p[i].ct, p[i].tat, p[i].wt);
    }
    
    printf("\nPERFORMANCE METRICS:\n");
    printf("-------------------------------------------\n");
    printf("Total Context Switches: %d\n", context_switch);
    printf("Total Waiting Time: %d ns\n", total_wt);
    printf("Total Turnaround Time: %d ns\n", total_tat);
    printf("Average Waiting Time: %.2f ns\n", (float)total_wt / n);
    printf("Average Turnaround Time: %.2f ns\n", (float)total_tat / n);
    
    printf("\n=========================================\n");
    printf("       VERIFICATION CALCULATIONS        \n");
    printf("=========================================\n\n");
    
    printf("Manual Calculations:\n");
    printf("P1: CT = 10, TAT = 10-0 = 10, WT = 10-10 = 0\n");
    printf("P2: CT = 30, TAT = 30-2 = 28, WT = 28-20 = 8\n");
    printf("P3: CT = 60, TAT = 60-6 = 54, WT = 54-30 = 24\n");
    printf("Avg WT = (0+8+24)/3 = 32/3 = 10.67 ns\n");
    
    return 0;
}

