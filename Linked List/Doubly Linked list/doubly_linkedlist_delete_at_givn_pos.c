#include <stdio.h>
#include <malloc.h>

int main()
{
    struct node
    {
        int data;
        struct node *prev;
        struct node *next;
    };
    struct node *head;
    head=0;
    struct node *newnode;
    struct node *temp;
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
            temp=head=newnode;
        }
        else
        {
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
        
        printf("Do u want to continue (0 or 1)\n");
        scanf("%d",&choice);
    }
    
    temp=head;
    printf("Printing Doubly linked list\n");
    while(temp!=0)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    
    int pos;
    int i=1;
    printf("\nEnter the position after which u want to delete a node\n");
    scanf("%d",&pos);
    
    temp=head;
    while(i<pos)
    {
        temp=temp->next;
        i++;
    }
    
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
    
    temp=head;
    printf("Printing Doubly linked list after deletion at given position\n");
    while(temp!=0)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    
    return 0;
}