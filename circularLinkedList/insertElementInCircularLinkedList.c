#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node* pre;
  struct Node* next;
};

typedef struct Node node_t;

node_t* createNode(int data);

void insertAtEnd(node_t**head, int data);
void printList(node_t* head);

int main()
{
  node_t* head = NULL;

  insertAtEnd(&head,10);
  insertAtEnd(&head,20);
  insertAtEnd(&head,30);
  insertAtEnd(&head,40);
  insertAtEnd(&head,40);
  insertAtEnd(&head,40);
  insertAtEnd(&head,40);
  printList(head);

}

node_t* createNode(int data)
{
  node_t* newNode;
  newNode = (node_t*)malloc(sizeof(node_t));
  if (newNode == NULL)
  {
    printf("Error in memory allocation");
    exit(-1);
  }

  newNode->data = data;
  newNode->next = NULL;
  newNode->pre  = NULL;

  return newNode;
}

void insertAtEnd(node_t** head, int data)
{
  node_t* newNode = createNode(data);

  if (*head == NULL)
  {
    *head = newNode;
    newNode->pre = *head;
    newNode->next = *head;
    return ;
  }
  node_t* temp = *head;

  while (temp->next != *head)
  {
    temp = temp->next;
  }
  temp->next = newNode;
  newNode->next = *head;
  (*head)->pre = newNode;
  newNode->pre = temp;
}

void printList(node_t* head)
{
  node_t* temp;
  temp = head;

  while(temp->next != head)
  {
    printf("%d->",temp->data);
    temp = temp->next;
  }
  printf("%d",temp->data);
}
