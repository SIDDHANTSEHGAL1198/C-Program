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
    }
  printf ("%d", temp->data);

  //Delete from end

  tail->prev->next=head;
  head->prev=tail->prev;
  temp=tail;
  tail=temp->prev;
  free(temp);
  
  printf("\nPrinting Doubly Circular list after deletion\n");
  temp=head;
  while(temp!=tail)
  {
      printf("%d ",temp->data);
      temp=temp->next;
  }
  printf("%d",temp->data);

  return 0;
}
