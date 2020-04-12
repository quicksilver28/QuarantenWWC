#include<stdio.h>
#include<stdlib.h>
int game(int *stacks, int n)
{
    int i, j, sum_m, sum_r, f=1;
    sum_m=sum_r=0;
    for(i=0,j=n-1; i<=j;)
    {
        if(stacks[i]>stacks[j])
        {
            if(f)
            {
                sum_m+=stacks[i];
                f=0;
            }
            else
            {
                sum_r+=stacks[i];
                f=1;
            }
            i++;
        }
        else if(stacks[j]>stacks[i])
        {
            if(f)
            {
                sum_m+=stacks[j];
                f=0;
            }
            else
            {
                sum_r+=stacks[j];
                f=1;
            }
            j--;
        }
        else
        {
            if(i+1<j-1)
            {
                if(stacks[i+1]>stacks[j-1])
                {
                    if(f)
                    {
                        sum_m+=stacks[i];
                        f=0;
                    }
                    else
                    {
                        sum_r+=stacks[i];
                        f=1;
                    }
                    i++;
                }
                else if(stacks[j-1]>stacks[i+1])
                {
                    if(f)
                    {
                        sum_m+=stacks[j];
                        f=0;
                    }
                    else
                    {
                        sum_r+=stacks[j];
                        f=1;
                    }
                    j--;
                }
                else
                {
                    if(f)
                    {
                        sum_m+=stacks[i];
                        f=0;
                    }
                    else
                    {
                        sum_r+=stacks[i];
                        f=1;
                    }
                    i++;
                }
            }
            else
            {
                if(f)
                {
                    sum_m+=stacks[i];
                    f=0;
                }
                else
                {
                    sum_r+=stacks[i];
                    f=1;
                }
                i++;
            }
        }
    }
    return sum_m>sum_r?1:0;
}
int main()
{
    int *stacks, n, i;
    scanf("%d",&n);
    stacks=(int *)malloc(sizeof(int)*n);
    for(i=0; i<n; i++)
        scanf("%d",&stacks[i]);
    if(game(stacks, n))
        printf("True");
    else
        printf("False");
    return 0;
}
