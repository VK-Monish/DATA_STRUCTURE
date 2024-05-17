#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

typedef struct Node node_t;

node_t* createNode(int);

void insertAtEnd(node_t**, int data);
void deleteAfterNode(node_t*, int pos);
void printList(node_t*);

int main()
{
  node_t* head=NULL;
  int i,ch,j;
/*  insertAtEnd(&head,10);
  insertAtEnd(&head,20);
  insertAtEnd(&head,30);
  insertAtEnd(&head,40);
  insertAtEnd(&head,50);
  printList(head);
  printf("Enter the delete postion\n");
  scanf("%d",&j);
  deleteAfterNode(head,j);
  printList(head);*/
  do
  {
    printf("press 1 for insert at end\n");
   printf("press 2 for delete at specfic postion\n");
   printf("press 3 for print\n");
   printf("press 4 for exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
		printf("Enter the data to insert\n");
		scanf("%d",&i);
		insertAtEnd(&head,i);
		break;
      case 2:
		printf("Enter the insert postion\n");
		scanf("%d",&j);
		deleteAfterNode(head,j);
		break;
      case 3:
		printList(head);
		break;
      case 4:
		exit(0);
    }
  }while(ch != 4);
}

node_t* createNode(int data)
{
  node_t* newNode;

  newNode = (node_t*)malloc(sizeof(node_t));

  if (newNode == NULL)
  {
    printf("error in memory allocation");
    exit(-1);
  }

  newNode->data = data;
  newNode->next = NULL;
}

void insertAtEnd(node_t** head, int data)
{
  node_t* newNode = createNode(data);

  if (*head == NULL) 
  {
    *head = newNode;
    return;
  }
  node_t* temp = *head;

  while(temp->next != NULL)
  {
    temp = temp->next;
  }

  temp->next = newNode;
}

void deleteAfterNode(node_t* head, int pos)
{
  int i=0;
  node_t* temp = head;
  node_t* temp1 = head;
  node_t* ptr ;
  node_t* ptr1 ;

  while (temp->next != NULL)
  {
    if (i == pos+1)
    {
      ptr = temp->next;
      break;
    }
    temp = temp->next;
    i++;
  }

  i=0;
  while (temp1->next != NULL)
  {
    if (i == pos)
    {
      temp1->next = ptr;
      break;
    }
    temp1 = temp1->next;
    i++;
  }
}

void printList(node_t* head)
{
  node_t *temp;
  temp = head;
  int i=0;

  while (temp->next != NULL)
  {
    printf("%d->",temp->data);
    temp = temp->next;
    i++;
  }
  printf("NULL\n");
}
