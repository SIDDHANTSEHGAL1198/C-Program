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
   struct node *newnode;
   int choice=1;
   
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
   }
   printf("%d",temp->data);
   
   struct node *new;
   new=(struct node*)malloc(sizeof(struct node));
   printf("\nEnter the data u wnat to insert in begining\n");
   scanf("%d",&new->data);
   new->next=0;

   if(temp==0)
   {
       temp=new;
       temp->next=new;
   }
   else
   {
       new->next=temp->next;
       temp->next=new;
   }
   
    temp=head;
   
   printf("Printing Circular linked list\n");
   while(temp->next!=head)
   {
       printf("%d ",temp->data);
       temp=temp->next;
   }
   printf("%d",temp->data);

    return 0;
}