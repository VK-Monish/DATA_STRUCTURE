#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int data;
   struct Node* next;
};

typedef struct Node node_t;

int main()
{
   node_t* head;
   printf("%ld\n", sizeof(node_t));

   head = (node_t*)malloc(sizeof(node_t));
   printf("%ld\n", sizeof(head));
}
