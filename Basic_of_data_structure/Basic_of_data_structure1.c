#include <stdio.h>
#include <stdlib.h>
int main()
{
  int *ptr;
  ptr=(int *)malloc(sizeof(int));
  printf("%p",ptr);
}
