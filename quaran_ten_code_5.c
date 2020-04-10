#include<stdio.h>
#include<stdlib.h>
int * countSmaller(int *a, int n){
    int i, j;
    int *output = (int *)calloc(n,sizeof(int));
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(a[j]<a[i])
                output[i]++;
        }
    }
    return output;
}
int main(){
    int n, *a, i, *output;
    scanf("%d",&n);
    a=(int *)malloc(sizeof(int)*n);
    output=(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    output=countSmaller(a, n);
    for(i=0;i<n;i++)
        printf("%d ",output[i]);
    return 0;
}
