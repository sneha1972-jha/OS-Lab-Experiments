#include <stdio.h>
int main(){
    int b[]={100,500,200,300,600},p[]={212,417,112,426,150};
    int used[5]={0},total=0;
    printf("Process Size Block BlockSize Fragment\n");
    for(int i=0;i<5;i++){
        int j;
        for(j=0;j<5;j++) if(!used[j] && b[j]>=p[i]) break;
        if(j==5) printf("P%d %d Not Allocated\n",i+1,p[i]);
        else{
            used[j]=1;
            int f=b[j]-p[i]; total+=f;
            printf("P%d %d B%d %d %d\n",i+1,p[i],j+1,b[j],f);
        }
    }
    printf("Total internal fragmentation = %d KB\n",total);
    printf("Unused blocks: ");
    for(int i=0;i<5;i++) if(!used[i]) printf("B%d (%d KB) ",i+1,b[i]);
    printf("\n");
    return 0;
}
