#include <stdio.h>
#define P 5
#define R 3
int alloc[P][R]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
int max[P][R]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
int avail[R]={3,3,2},need[P][R];
int safe(){
    int work[R],finish[P]={0},seq[P],n=0;
    for(int j=0;j<R;j++) work[j]=avail[j];
    for(int k=0;k<P;k++)
        for(int i=0;i<P;i++) if(!finish[i]){
            int j;
            for(j=0;j<R && need[i][j]<=work[j];j++);
            if(j==R){
                for(j=0;j<R;j++) work[j]+=alloc[i][j];
                finish[i]=1; seq[n++]=i;
            }
        }
    if(n<P) return 0;
    printf("Safe Sequence: ");
    for(int i=0;i<P;i++) printf("P%d%s",seq[i],i==P-1?"\n":" -> ");
    return 1;
}
void request(int p,int req[]){
    printf("\nRequest by P%d: (%d, %d, %d)\n",p,req[0],req[1],req[2]);
    for(int j=0;j<R;j++) if(req[j]>need[p][j]){
        printf("Request exceeds maximum claim. DENIED.\n"); return;
    }
    for(int j=0;j<R;j++) if(req[j]>avail[j]){
        printf("Resources not available. P%d must WAIT.\n",p); return;
    }
    for(int j=0;j<R;j++){
        avail[j]-=req[j]; alloc[p][j]+=req[j]; need[p][j]-=req[j];
    }
    if(safe()) printf("Request GRANTED.\n");
    else{
        for(int j=0;j<R;j++){
            avail[j]+=req[j]; alloc[p][j]-=req[j]; need[p][j]+=req[j];
        }
        printf("Request would lead to an UNSAFE state. DENIED (rolled back).\n");
    }
}
int main(){
    int req[][R]={{1,0,2},{3,3,0},{0,2,0}};
    int process[]={1,4,0};
    for(int i=0;i<P;i++)
        for(int j=0;j<R;j++) need[i][j]=max[i][j]-alloc[i][j];
    printf("Need Matrix:\nA B C\n");
    for(int i=0;i<P;i++)
        printf("P%d %d %d %d\n",i,need[i][0],need[i][1],need[i][2]);
    printf("\nInitial State:\n");
    if(safe()) printf("System is in a SAFE state.\n");
    else printf("System is in an UNSAFE state.\n");
    for(int i=0;i<3;i++) request(process[i],req[i]);
    return 0;
}
