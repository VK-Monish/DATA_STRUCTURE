#include <stdio.h>
#include <stdlib.h>
struct Node
{
  int data;
  struct Node* next;
};


int main()
{
  struct Node* head;
  printf("%ld\n",sizeof(head));
  head = (struct node*)malloc(sizeof(struct Node));
  printf("%ld\n",sizeof(head));
}
