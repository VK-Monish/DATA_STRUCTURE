#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node* next;
  struct Node* pre;
};

typedef struct Node node_t;

node_t* createNode(int);
void printList(node_t* head);
void insertAtBegning(node_t** head, int data);

int main()
{
  node_t*head = NULL;
  int j,l;
  while (1)
  {
    printf("press 1.for print at begining\n");
    printf("press 2.for print\n");
    printf("press 3.for exit\n");
    scanf("%d",&l);
    switch (l)
    {
      case 1:
		printf("Enter the element to insert\n");
		scanf("%d",&j);
		insertAtBegning(&head,j);
		break;
      case 2:
		printList(head);
		break;
      case 3:
		exit (-1);
    }
  }
}

node_t* createNode(int data)
{
  node_t* newNode;
  newNode = (node_t*)malloc(sizeof(node_t));

  if (newNode == NULL)
  {
    printf("error in memory allocation");
    exit (-1);
  }
  newNode->data = data;
  newNode->next = NULL;
  newNode->pre  = NULL;
  return newNode;
}

void insertAtBegning(node_t** head, int data)
{
  node_t* newNode = createNode(data);
  if (*head == NULL)
  {
    *head = newNode;
    return ;
  }
  node_t* temp = *head;
  newNode->next = *head;
  *head = newNode;
  temp->pre = newNode;
}

void printList(node_t* head)
{
  node_t* temp;
  temp = head;
  while (temp->next != NULL)
  {
    printf("%d->",temp->data);
    temp = temp->next;
  }
  printf("%d->",temp->data);
  printf("->NULL");
  printf("\n");
  while (temp->pre != NULL)
  {
    printf("%d->",temp->data);
    temp = temp->pre;
  }
  printf("%d->",temp->data);
  printf("NUll\n");
}
