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
   
   printf("\nNumber of nodes=%d\n",c);
   
     temp = head;
     while (temp->next != head)
     {
         tail = temp->next;
         temp = temp->next;
     }
   
   int pos=0;
   int i=1;
   printf("\nEnter the position at which u want to insert the node\n");
   scanf("%d",&pos);
   
   if(pos>c && pos<1)
   {
       printf("Invalid position");
   }
   if(pos==1)
   {
       struct node *new;
       new = (struct node *) malloc (sizeof (struct node));
       printf ("Enter the data u want to insert in the  begining\n");
       scanf ("%d",&new->data);
       new->next = 0;
       
       if (tail == 0)
       {
           tail = new;
           tail->next = new;
       }
       else
       {
           new->next = tail->next;
           tail->next = new;
       }
       head=new;
       
       temp=head;
       printf("Printing Circular linked list after insertion\n");
       while(temp->next!=head)
       {
           printf("%d ",temp->data);
           temp=temp->next;
           
       }
       printf("%d",temp->data);
   
   }
   else
   {
       struct node *new;
       new = (struct node *) malloc (sizeof (struct node));
       printf ("Enter the data u want to insert in the  begining\n");
       scanf ("%d",&new->data);
       new->next = 0;
       
       temp=head;
       while(i<pos-1)
       {
           temp=temp->next;
           i++;
       }
       new->next=temp->next;
       temp->next=new;
       
       temp=head;
       printf("Printing Circular linked list after insertion\n");
       while(temp->next!=head)
       {
           printf("%d ",temp->data);
           temp=temp->next;
           
       }
       printf("%d",temp->data);
   }
    return 0;
}