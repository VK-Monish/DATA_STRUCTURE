#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node* next;
  struct Node* pre;
};

typedef struct Node node_t;

node_t* createNode(int data);

void printList(node_t* head);
void insertAtEnd(node_t** head, int data);
void deleteAtBegining(node_t** head);

int main()
{
  node_t* head = NULL;
  int l,j;
  while (1)
  {
    printf("press 1.for insert at end\n");
    printf("press 2.for delete at begning\n");
    printf("press 3.for display\n");
    scanf("%d",&l);
    switch(l)
    {
      case 1:
		printf("Enter the data\n");
		scanf("%d",&j);
		insertAtEnd(&head, j);
		break;
      case 2:
      		deleteAtBegining(&head);
		printList(head);
		break;
      case 3:
		printList(head);
		break;
      case 4:
		exit(0);
    }
  }
}

// Function for creation node 
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
  newNode->pre  = NULL;

  return newNode;
}

//function for insert at end
void insertAtEnd(node_t** head, int data)
{
  node_t* newNode = createNode(data);

  if (*head == NULL)
  {
    *head = newNode;
    return ;
  }

  node_t* temp = *head;

  while(temp->next != NULL)
  {
    temp = temp->next; 
  }

  temp->next = newNode;
  newNode->pre = temp; 
}

void deleteAtBegining(node_t** head)
{
  node_t* temp = *head;

  *head = temp->next;
  temp = temp->next;
  temp->pre = NULL;
}

//Function for printlist
void printList(node_t* head)
{
  node_t *temp;
  temp = head;

  while(temp->next != NULL)
  {
    printf("%d->",temp->data);
    temp = temp->next;
  }

  printf("%d",temp->data);
  printf("->NULL\n");

  while(temp->pre != NULL)
  {
    printf("%d->",temp->data);
    temp = temp->pre; 
  }

  printf("%d",temp->data);
  printf("->NULL\n");
}

