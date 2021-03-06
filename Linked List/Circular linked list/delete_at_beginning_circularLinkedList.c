#include <stdio.h>
#include <malloc.h>
int main()
{
    struct node
    {
        int data;
        struct node *next;
    };
    struct node *head;
    head=0;
    struct node *temp;
    struct node *tail;
    struct node *newnode;
    int choice=1;
    int c=0;
    
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data\n");
        scanf("%d",&newnode->data);
        newnode->next=0;
        
        if(head==0)
        {
            temp=head=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        temp->next=head;
        
        printf("Do u want to continue (0 or 1)\n");
        scanf("%d",&choice);
    }
    
    
    temp=head;
    printf("Printing Circular linked list\n");
    while(temp->next!=head)
    {
        printf("%d ",temp->data);
        temp=temp->next;
        c++;
    }
    printf("%d",temp->data);
    c++;
    
    temp=head;
    while(temp->next!=head)
    {
        tail=temp->next;
        temp=temp->next;
    }
    
    
    
    //Delete at begining
    c=0;
    temp=tail->next;
    tail->next=temp->next;
    head=temp->next;
    free(temp);
    
    temp=head;
    printf("\nPrinting Circular linked list after delete at begining\n");
    while(temp->next!=head)
    {
        printf("%d ",temp->data);
        temp=temp->next;
        c++;
    }
    printf("%d",temp->data);
    c++;
    
    
    
    printf("\nNumber of nodes in linked list after delete operation = %d",c);
    return 0;
}
