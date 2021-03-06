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
    head=0;
    struct node *tail;
    struct node *newnode;
    struct node *temp;
    int choice=1,count=0;
    
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
            head->prev=newnode;
            newnode->next=head;
            tail=newnode;
        }
        
        printf("Do u want to continue (0 or 1)\n");
        scanf("%d",&choice);
    }
    
    printf("Printing Doubly Circular linked list\n");
    temp=head;
    while(temp!=tail)
    {
        printf("%d ",temp->data);
        temp=temp->next;
        count++;
    }
    printf("%d",temp->data);
    count++;
    
    int pos;
    int i=1;
    printf("\nEnter the position at which u want to insert\n");
    scanf("%d",&pos);
    
    if(pos>count)
    {
        printf("Invalid position entered\n");
    }
    else
    {
        struct node *new;
        new=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter the data u want to insert at begining\n");
        scanf("%d",&new->data);
        new->prev=0;
        new->next=0;
        
        temp=head;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        new->prev=temp;
        new->next=temp->next;
        temp->next->prev=new;
        temp->next=new;
        
        printf("Printing Doubly Circular linked list after insertion\n");
        temp=head;
        while(temp!=tail)
        {
            printf("%d ",temp->data);
            temp=temp->next;
            
        }
        printf("%d",temp->data);
    
    }
    return 0;
}