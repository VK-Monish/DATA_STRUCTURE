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
void insertAtEnd(node_t** head, int data);

int main()
{
  node_t*head = NULL;
  insertAtEnd(&head,10);
  insertAtEnd(&head,20);
  insertAtEnd(&head,30);
  insertAtEnd(&head,40);
  printList(head);
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
  newNode->pre  = NULL;
  return newNode;
}

void insertAtEnd(node_t** head, int data)
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
  /*node_t* temp  = *head;
  node_t* temp1 = *head;
  while (temp->next != NULL)
  {
    temp = temp->next; 
  }
  temp->next   = newNode;
  newNode->pre = temp1;*/

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
  printf("->NULL");
  printf("\n");
  while(temp->pre != NULL)
  {
    temp = temp->pre;
    printf("%d->",temp->data);
  }
  printf("NUll\n");
}
