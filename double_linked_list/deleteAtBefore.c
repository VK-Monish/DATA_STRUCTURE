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
void deleteAtBefore(node_t**head, int pos);

int main()
{
  node_t* head = NULL;
  insertAtEnd(&head, 10);
  insertAtEnd(&head, 20);
  insertAtEnd(&head, 30);
  insertAtEnd(&head, 40);
  insertAtEnd(&head, 50);
  insertAtEnd(&head, 60);
  printList(head);
  deleteAtBefore(&head,1);
  printList(head);

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
  printf("%p\n",newNode);
  if (*head == NULL)
  {
    *head = newNode;
    return ;
  }

  node_t* temp = *head;

  while (temp->next != NULL)
  {
    temp = temp->next; 
  }

  temp->next = newNode;
  newNode->pre = temp; 
}
void deleteAtBefore(node_t** head, int pos)
{
  int i=0;
  node_t* temp = *head;
  if(pos == 1)
  {
    *head = temp->next;
    temp = temp->next;
    temp->pre = NULL;
  }
 else
 {
  while (temp->next != NULL)
  {
      if (i == pos-2)
      {
	break;
      }
      temp = temp->next;
      i++;
    }
    i=0;
    node_t* temp1 = *head;
    while (temp1->next != NULL)
    {
      if (i == pos)
      {
	temp1->pre = temp;
	temp->next = temp1;
	break;
      }
      temp1 = temp1->next;
      i++;
    }
 }
}

//Function for printlist
void printList(node_t* head)
{
  node_t *temp;
  temp = head;

  while (temp->next != NULL)
  {
    printf("%d->",temp->data);
    temp = temp->next;
  }

  printf("%d",temp->data);
  printf("->NULL\n");

  while (temp->pre != NULL)
  {
    printf("%d->",temp->data);
    temp = temp->pre; 
  }

  printf("%d->",temp->data);
  printf("NULL\n");
}
