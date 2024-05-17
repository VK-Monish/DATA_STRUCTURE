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
void insertAfterNode(node_t*, int data, int pos);
void printList(node_t*);

int main()
{
  node_t* head=NULL;
  int i,ch,j;
  do
  {
    printf("press 1 for insert at end\n");
    printf("press 2 for insert at specfic postion\n");
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
		printf("Enter the data to insert\n");
		scanf("%d",&i);
		insertAfterNode(head,i,j);
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

void insertAfterNode(node_t* head, int data, int pos)
{
  int i=0;
  node_t* newNode = createNode(data);

  node_t* temp = head;
  node_t* ptr ;

  while(temp->next != NULL)
  {
    if (i == pos)
    {
      ptr = temp->next;
      break;
    }
    temp = temp->next;
    i++;
  }

}
void insertBeforeNode(node_t* head, int data, int pos)
{
  int i=0;
  node_t* newNode = createNode(data);

  node_t* temp = head;
  node_t* ptr ;

  while(temp->next != NULL)
  {
    if (i == pos)
    {
      ptr = temp->next;
      break;
    }
    temp = temp->next;
    i++;
  }
}

void printList(node_t* head)
{
  node_t *temp;
  temp = head;
  int i=0;
  while(temp->next != NULL)
  {
    printf("%d->",temp->data);
    temp = temp->next;
    i++;
  }
  printf("NULL\n");
}
