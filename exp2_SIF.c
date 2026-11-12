#include <stdio.h>
int main() {
    int n, i, time = 0, completed = 0;
    int at[20], bt[20], ct[20];
    int tat[20], wt[20], p[20], done[20] = {0};
    float avgTat = 0, avgWt = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Enter arrival and burst time of P%d: ", p[i]);
        scanf("%d%d", &at[i], &bt[i]);
    }
    while(completed < n) {
        int min = -1;
        for(i = 0; i < n; i++) {
            if(!done[i] && at[i] <= time) {
                if(min == -1 || bt[i] < bt[min])
                    min = i;
            }
        }
        if(min == -1) {
            time++;
            continue;
        }
        time += bt[min];
        ct[min] = time;
        tat[min] = ct[min] - at[min];
        wt[min] = tat[min] - bt[min];
        avgTat += tat[min];
        avgWt += wt[min];
        done[min] = 1;
        completed++;
    }
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("\nAverage Turnaround Time = %.2f", avgTat/n);
    printf("\nAverage Waiting Time = %.2f\n", avgWt/n);
    return 0;
}
