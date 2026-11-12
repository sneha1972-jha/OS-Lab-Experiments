#include <stdio.h>
int main() {
    int n,i,t=0,d=0,m;
    int at[20],bt[20],pr[20],rem[20];
    int ct[20],tat[20],wt[20],rt[20],f[20]={0};
    float avT=0,avW=0;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d%d%d",&pr[i],&at[i],&bt[i]);
        rem[i]=bt[i];
    }
    while(d<n) {
        m=-1;
        for(i=0;i<n;i++)
            if(rem[i]>0 && at[i]<=t)
                if(m==-1 || pr[i]>pr[m]) m=i;
        if(m==-1) { t++; continue; }
        if(!f[m]) rt[m]=t-at[m],f[m]=1;
        rem[m]--; t++;
        if(rem[m]==0) {
            ct[m]=t;
            tat[m]=ct[m]-at[m];
            wt[m]=tat[m]-bt[m];
            avT+=tat[m]; avW+=wt[m]; d++;
        }
    }
    printf("\nP\tPR\tAT\tBT\tCT\tWT\tRT\tTAT\n");
    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1,pr[i],at[i],bt[i],ct[i],wt[i],rt[i],tat[i]);
    printf("\nAv TAT = %.2f\nAv WT = %.2f\n",avT/n,avW/n);
    return 0;
}
