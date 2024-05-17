#include <stdio.h>
#include <stdlib.h>
int main()
{
  int *arr;
  int i;
  arr=(int *)malloc(sizeof(int)*100);
  if(arr==NULL)
   {
     printf("the memory is not intialized!");
     exit(-1);
   }
  for(i=0; i<100; i++)
  {
    arr[i]=i*10;
  }
  for(i=0; i<100; i++)
  {
    printf("%d\n",arr[i]);
  }
}
