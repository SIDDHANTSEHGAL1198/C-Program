#include <stdio.h>
#include <malloc.h>
int main()
{
    struct node
    {
        int data;
        struct node *next;
        struct node *prev;
    };
    struct node *head;
    struct node *tail;
    struct node *newnode;
    head=0;
    int choice=1;
    
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data\n");
        scanf("%d",&newnode->data);
        newnode->prev=0;
        newnode->next=0;
        
        if(head==0)
        {
            head=tail=newnode;
            head->prev=head;
            head->next=head;
        }
        else
        {
            tail->next=newnode;
            newnode->prev=tail;
            newnode->next=head;
            head->prev=newnode;
            tail=newnode;
        }
        printf("Do u want to continue (0 or 1)\n");
        scanf("%d",&choice);
    }
    
    struct node *temp;
    temp=head;
    printf("Printing Doubly Circular list\n");
    while(temp!=tail)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
    
    return 0;
}