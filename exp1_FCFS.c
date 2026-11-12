#include <stdio.h>
int main() {
    int n, i, j;
    int at[20], bt[20], ct[20];
    int tat[20], wt[20], p[20];
    float avgTat = 0, avgWt = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Enter arrival and burst time of P%d: ", p[i]);
        scanf("%d%d", &at[i], &bt[i]);
    }
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(at[i] > at[j]) {
                int temp;
                temp = at[i]; at[i] = at[j]; at[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = p[i]; p[i] = p[j]; p[j] = temp;
            }
        }
    }
    for(i = 0; i < n; i++) {
        if(i == 0)
            ct[i] = at[i] + bt[i];
        else
            ct[i] = (ct[i-1] > at[i] ? ct[i-1] : at[i]) + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avgTat += tat[i];
        avgWt += wt[i];
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
