#include<stdio.h>
#include<stdlib.h>
int closestToX(int *s, int n, int X){
    int i, j, k, min=60000, d, sum=0;
    for(i=0;i<n-2;i++){
        j=i+1;
        for(k=n-1;k>j;k--){
            d=s[i]+s[j]+s[k];
            d=(d-X)<0?(d-X)*-1:(d-X);
            if(d<min){
                min=d;
                sum=s[i]+s[j]+s[k];
            }
        }
    }
    return (sum<0?sum*-1:sum);
}
int main(){
    int *steps, n, X, t, i;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        steps=(int *)malloc(sizeof(int)*n);
        for(i=0;i<n;i++)
            scanf("%d",&steps[i]);
        scanf("%d",&X);
        printf("%d\n",closestToX(steps, n, X));
    }
}
