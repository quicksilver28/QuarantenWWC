#include<stdio.h>
#include<stdlib.h>
int amusementPark(int **r, int n){
    int i, j, *c_p, c=0;
    c_p=(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        c_p[i]=-1;
    c_p[0]=0;
    for(i=0;i<n;i++){
        for(j=0;r[i][j]!=-1;j++){
            if(r[i][j]!=i&&c_p[r[i][j]]==-1){
                    c_p[r[i][j]]++;
            }
        }
    }
    for(i=0;i<n;i++)
        printf("%d ",c_p[i]);
    for(i=0;i<=n;i++){
        if(c_p[i]==-1)
            return 0;
    }
    return 1;
}
int main(){
    int n, **r_p, i, j, p;
    scanf("%d",&n);
    r_p=(int **)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        r_p[i]=(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&r_p[i][j]);
            if(r_p[i][j]==-1){        //denotes end of list of passes
                break;
            }
        }
    }
    if(amusementPark(r_p, n)){
        printf("True");
    }
    else{
        printf("False");
    }
    return 0;
}
