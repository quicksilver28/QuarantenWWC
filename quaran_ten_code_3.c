#include<stdio.h>
#include<stdlib.h>
int BonusPoints(int *ranks, int n)
{
    int bonus=0, *b, i, j, k;
    b=(int *)calloc(n, sizeof(int));
    for(i=0;i<n;i++){
        b[i]++;
        j=k=i;
        while(j>0&&ranks[j-1]>ranks[j]){
            b[j-1]++;
            j--;
        }
        while(k<n-1&&ranks[k+1]>ranks[k]){
            b[k+1]++;
            k++;
        }
        if(i!=0&&i!=n-1&&ranks[i]>ranks[i-1]&&ranks[i]>ranks[i+1])
            b[i]--;
    }
    for(i=0;i<n;i++)
        bonus+=b[i];
    return bonus;
}
int main()
{
    int n, *ranks, i;
    scanf("%d",&n);
    ranks=(int *)malloc(sizeof(int)*n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&ranks[i]);
    }
    printf("%d",BonusPoints(ranks, n));
}
