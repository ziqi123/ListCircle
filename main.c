//
//  main.c
//  ListCircle
//
//  Created by 刘子琪 on 2017/7/25.
//  Copyright © 2017年 LinkList. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
    
}Node;

Node *get_circle_link(int length,int local)
{
    Node *temp=NULL;
    Node *head=NULL;
    Node *tail=NULL;
    
    int i=0;
    for (i=0;i<length;i++)
    {
        temp=(Node *)malloc(sizeof(Node));
        temp->next=NULL;
        temp->data=length-i;
        if(head==NULL)
        {
            tail=temp;
        }
        temp->next=head;
        head=temp;
    }
    for(temp=head,i=1;i<local;i++)
    {
        temp=temp->next;
    }
    tail->next=temp;
    return head;
}

int get_circle_local(Node *phead)
{
    Node *fast=phead;
    Node *slow=phead;
    while(fast!=NULL&&fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
        {
            //return 1;
            for (slow=phead;slow!=fast;)
            {
                slow=slow->next;
                fast=fast->next;
            }
            return slow->data;
            
        }
    }
    return 0;
}
void link_print(Node *temp)
{
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
        getchar();
    }
    printf("\n");
}
int main(int argc, const char * argv[]) {
    Node *head=NULL;
    int local=0;
    int number=0;
    printf("please input number and local:\n");
    scanf("%d",&number);
    scanf("%d",&local);
    head=get_circle_link(number, local);
    
    int ret=0;
    if(get_circle_local(head)>0)
        printf("has circle and local is %d\n",local);
    else
        printf("no circle\n");
    return 0;
}








