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
void insertAtBegining(node_t**, int data);
void deleteAtBegining(node_t** );
void Postion(node_t**, int data, int pos);
void printList(node_t*);

int main()
{
  node_t* head=NULL;
  int i,ch,j;
  do
  {
    printf("press 1 for insert at begin\n");
    printf("press 2 for insert at end\n");
    printf("press 3 for delete at begin\n");
    printf("press 4 for insert at specfic postion\n");
    printf("press 5 for print\n");
    printf("press 6 for exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
		printf("Enter the data to insert\n");
		scanf("%d",&i);
		insertAtBegining(&head,i);
		break;
      case 2:
		printf("Enter the data to insert\n");
		scanf("%d",&i);
		insertAtEnd(&head,i);
		break;
      case 3:
		printf("delete at begining\n");
		deleteAtBegining(&head);
		break;
      case 4:
		printf("Enter the insert postion\n");
		scanf("%d",&j);
		printf("Enter the data to insert\n");
		scanf("%d",&i);
		Postion(&head,i,j);
		break;
      case 5:
		printList(head);
		break;
      case 6:
		exit(0);
    }
  }while(ch != 6);
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

void Postion(node_t** head, int data, int pos)
{
  int i=0;
  node_t* newNode = createNode(data);

  node_t* temp = *head;

  while(temp->next != NULL)
  {
    temp = temp->next;

    if (i==pos)
    {
      break;
    }
    i++;
  }
  newNode->next = temp;
  temp = newNode;
}

void insertAtBegining(node_t**head, int data)
{
  node_t* newNode = createNode(data);
 if(newNode == NULL)
  {
    *head = newNode;
    return;
  }
  node_t* temp = *head;
  newNode->next = temp;
  *head = newNode;
}

void deleteAtBegining(node_t**head)
{
  node_t* temp = *head;
  temp = temp->next;
  *head = temp;
}

void printList(node_t* head)
{
  node_t *temp;
  temp = head;
  int i=0;
  while(temp->next != NULL)
  {
    printf("%d  ",i);
    printf("%d->",temp->data);
    temp = temp->next;
    printf("%p\n",temp);
    i++;
  }
  printf("NULL\n");
}
