#include <stdio.h>
#include <malloc.h>
int
main ()
{
  struct node
  {
    int data;
    struct node *prev;
    struct node *next;
  };
  struct node *head;
  head = 0;
  struct node *tail;
  struct node *temp;
  struct node *newnode;
  int choice = 1;
  int len=0;

  while (choice)
    {
      newnode = (struct node *) malloc (sizeof (struct node));
      printf ("Enter data\n");
      scanf ("%d", &newnode->data);
      newnode->prev = 0;
      newnode->next = 0;

      if (head == 0)
	{
	  head = tail = newnode;
	  head->prev = head;
	  head->next = head;
	}
      else
	{
	  tail->next = newnode;
	  newnode->prev = tail;
	  newnode->next = head;
	  head->prev = newnode;
	  tail = newnode;
	}
      printf ("Do u want to continue (0 or 1)\n");
      scanf ("%d", &choice);
    }


  printf ("\nPrinting Doubly Circular list\n");
  temp = head;
  while (temp != tail)
    {
      printf ("%d ", temp->data);
      temp = temp->next;
      len++;
    }
  printf ("%d", temp->data);
  len++;

  //Delete at given position
  
  int pos,i=1;
  printf("\nEnter the position from which u want to delete a node\n");
  scanf("%d",&pos);
  
  if(pos>len)
  {
      printf("Invalid position entered");
  }
  else
  {
      temp=head;
      while(i<pos)
      {
          temp=temp->next;
          i++;
      }
      temp->prev->next=temp->next;
      temp->next->prev=temp->prev;
      if(temp->next==head)
      {
          tail=temp->prev;
          free(temp);
      }
      else
      {
          free(temp);
      }
      
      printf ("\nPrinting Doubly Circular list\n");
      temp = head;
      while (temp != tail)
      {
          printf ("%d ", temp->data);
          temp = temp->next;
          len++;
      }
      printf ("%d", temp->data);
      
  }

  return 0;
}
