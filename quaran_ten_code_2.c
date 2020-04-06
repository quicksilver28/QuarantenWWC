#include<stdio.h>
#include<stdlib.h>
typedef struct ListNode{
    int val;
    struct ListNode *next;
}ListNode;
void insertNode(ListNode **head, int x){
    ListNode *t = (ListNode *)malloc(sizeof(ListNode));
    ListNode *p;
    t->val=x;
    t->next=NULL;
    if(*head==NULL){
        *head=t;
    }
    else{
        p=*head;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=t;
    }
}

int countNodes(ListNode *head){
    int c=0;
    while(head!=NULL){
        c++;
        head=head->next;
    }
    return c;
}
int * stonePath(ListNode *head){
    int *path, n, i, max;
    ListNode *t;
    n=countNodes(head);
    path=(int *)malloc(sizeof(int)*n);
    i=0;
    while(head!=NULL){
        max=head->val;
        t=head->next;
        while(t!=NULL){
            if(max<t->val){
                max=t->val;
            }
            t=t->next;
        }
        if(max==head->val)
            max=0;
        path[i++]=max;
        head=head->next;
    }
    return path;
}
int main(){
    int n, i, x, *path;
    ListNode *t, *head=NULL;
    scanf("%d",&n);
    path=(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        insertNode(&head, x);
    }
    path = stonePath(head);
    for(i=0;i<n;i++){
        printf("%d ",path[i]);
    }
    return 0;
}
