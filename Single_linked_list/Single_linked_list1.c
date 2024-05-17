#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node* next;
};

typedef struct Node node_t;

node_t* createNode(int);
void insertAtEnd(node_t**, int data);
void printList(node_t*);

int main()
{
  node_t* head =NULL;
  int ch;
  int i;
  do
  {
  	printf("For insert press 1\n");
  	printf("To print press 2\n");
  	printf("For exit press 3\n");
  	scanf("%d",&ch);
  	switch(ch)
  	{
    	case 1:
	  	printf("Enter the data to insert\n");
		scanf("%d",&i);
      		insertAtEnd(&head,i);
		break;
   	case 2:
		printList(head);
		break;
  	}
	
  }while(ch!=3);
}

node_t* createNode(int data)
{
  node_t* newNode;
  newNode = (node_t*)malloc(sizeof(node_t));
  if (newNode == NULL)
  {
    printf("memory allocation failed");
    exit(-1);
  }

  newNode->data = data;
  newNode->next = NULL;

  return newNode;
}

void insertAtEnd(node_t** head,int data)
{
  node_t* newNode = createNode(data);
  if(*head == NULL)
  {
    *head = newNode;
    return;
  }

  node_t* temp = *head;

  while(temp->next!=NULL)
  {
    temp = temp->next;
  }
  temp->next = newNode;
}

void printList(node_t* head)
{
  node_t* temp;
  temp = head;
  while(temp->next != NULL)
  {
    printf("%d->",temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}
