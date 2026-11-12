#include <stdio.h>
int main() {
    int n,qnt,i,t=0,d=0;
    int at[20],bt[20],rem[20],ct[20],tat[20],wt[20];
    int q[1000],f=0,r=0,a[20]={0};
    float avT=0,avW=0;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d%d",&at[i],&bt[i]);
        rem[i]=bt[i];
    }
    scanf("%d",&qnt);
    while(d<n) {
        for(i=0;i<n;i++)
            if(!a[i] && at[i]<=t)
                q[r++]=i,a[i]=1;
        if(f==r) { t++; continue; }
        int p=q[f++],x=(rem[p]<qnt)?rem[p]:qnt;
        t+=x; rem[p]-=x;
        for(i=0;i<n;i++)
            if(!a[i] && at[i]<=t)
                q[r++]=i,a[i]=1;
        if(rem[p]>0) q[r++]=p;
        else {
            ct[p]=t;
            tat[p]=ct[p]-at[p];
            wt[p]=tat[p]-bt[p];
            avT+=tat[p]; avW+=wt[p]; d++;
        }
    }
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    printf("\nAv TAT = %.2f\nAv WT = %.2f\n",avT/n,avW/n);
    return 0;
}
