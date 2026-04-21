#include <stdio.h>
void main() {
    int n, i, time = 0, completed = 0, min, idx;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int at[n], bt[n], rt[n], pr[n];
    int wt[n], tat[n], done[n];
    for(i = 0; i < n; i++) {
        printf("AT BT PR for P%d: ", i+1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        rt[i] = bt[i];   // remaining time
        done[i] = 0;
    }
    while(completed < n) {
        min = 9999;
        idx = -1;
        for(i = 0; i < n; i++) {
            if(at[i] <= time && !done[i]) {
                if(pr[i] < min && rt[i] > 0) {
                    min = pr[i];
                    idx = i;
                }
            }
        }
        if(idx != -1) {
            rt[idx]--;   // execute for 1 unit
            time++;
            if(rt[idx] == 0) {
                done[idx] = 1;
                completed++;
                tat[idx] = time - at[idx];
                wt[idx] = tat[idx] - bt[idx];
            }
        } else {
            time++; // idle CPU
        }
    }
    float aw = 0, atat = 0;
    printf("\nP\tAT\tBT\tPR\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], pr[i], wt[i], tat[i]);
        aw += wt[i];
        atat += tat[i];
    }
    printf("Avg WT=%.2f Avg TAT=%.2f\n", aw/n, atat/n);
}
