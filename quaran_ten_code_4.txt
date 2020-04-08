#include<stdio.h>
#include<stdlib.h>
int * signalRanges(int *h, int n){
    int i, j, *range;
    range=(int *)malloc(sizeof(int)*n);
    for(i=n-1;i>=0;i--){
        for(j=i-1;j>=0;j--){
            if(h[j]>h[i])
                break;
        }
        range[i]=i-j;
    }
    return range;
}
int main(){
    int n, *h, i, *range;
    scanf("%d",&n);
    h=(int *)malloc(sizeof(int)*n);
    range=(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        scanf("%d",&h[i]);
    range=signalRanges(h, n);
    for(i=0;i<n;i++){
        printf("%d ",range[i]);
    }
    return 0;
}
