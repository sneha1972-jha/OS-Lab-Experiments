#include <stdio.h>
int main() {
    int ref[] = {4,7,6,1,7,6,1,2,7,2,6,3,1,7,4,2,6,1,3,7};
    int f[3] = {-1,-1,-1}, last[3] = {-1,-1,-1};
    int faults=0, hits=0, i, j, pos, hit;
    printf("Ref Page F1 F2 F3 Status\n");
    for(i=0; i<20; i++) {
        hit=0;
        for(j=0; j<3; j++)
            if(f[j]==ref[i]) { hit=1; break; }
        if(hit) {
            hits++;
            last[j]=i;
        }
        else {
            faults++;
            for(j=0; j<3 && f[j]!=-1; j++);
            if(j==3) {
                pos=0;
                for(j=1; j<3; j++)
                    if(last[j]<last[pos]) pos=j;
                j=pos;
            }
            f[j]=ref[i];
            last[j]=i;
        }
        printf("%d %d ",i+1,ref[i]);
        for(j=0; j<3; j++)
            if(f[j]==-1) printf("- ");
            else printf("%d ",f[j]);
        printf("%s\n",hit?"Hit":"Fault");
    }
    printf("Total page faults = %d\n",faults);
    printf("Total page hits = %d\n",hits);
    printf("Hit ratio = %.2f%% Fault ratio = %.2f%%\n",
           hits*100.0/20,faults*100.0/20);
    return 0;
}
