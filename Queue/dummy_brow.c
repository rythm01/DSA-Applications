#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 10
typedef struct Queue
{
  char arr[40];
} queue;
queue Q[size];
int front = -1, rear = -1;
void Dequeue()
{
  if (front == rear)
  {
    printf("\nPage %s is removed from history", Q[rear].arr);
    printf("\nAll data cleared\n");
    front = -1, rear = -1;
    return;
  }
  else
  {
    printf("\nPage %s is removed from history", Q[front].arr);
    front++;
  }
}
void Enqueue(char *str)
{
  if (front == -1 && rear == -1)
  {
    front = 0, rear = 0;
    strcpy(Q[rear].arr, str);
    printf("\nPage %s added successfully\n", Q[rear].arr);
  }
  else if ((rear + 1) % size == front)
  {
    Dequeue();
    rear = (rear + 1) % size;
    strcpy(Q[rear].arr, str);
    printf("\nPage %s added successfully\n", Q[rear].arr);
  }
  else
  {
    rear = (rear + 1) % size;
    strcpy(Q[rear].arr, str);
    printf("\nPage %s added successfully\n", Q[rear].arr);
  }
}
void trav()
{
  if (front == -1 && rear == -1)
    printf("\nThere's nothing to show(Empty set)\n");
  if (front < rear)
  {
    for (int i = rear; i >= front; i--)
    {
      printf("\n %s", Q[i].arr);
    }
  }
  else if (front == rear)
    printf("\n %s", Q[rear].arr);
  else
  {
    for (int i = rear; i >= 0; i--)
      printf("\n %s", Q[i].arr);
    for (int i = size - 1; i >= front; i--)
      printf("\n %s", Q[i].arr);
  }
}
int main()
{
  char source[20];
  int ch = 0;
  char a;
str:
  printf("--------------------------");
  printf("\n:::Operations:::\n");
  printf("\n1.Add page of vist\n2.Display visited pages\n");
  printf("--------------------------\n");
  printf("\nEnter Which operation you want to perform from above?:- ");
  scanf(" %d", &ch);
  switch (ch)
  {
  case 1:
    printf("\nWhich page to add for visit:- ");
    scanf(" %s", source);
    Enqueue(source);
    printf("\nYou want to continue?\n(press Y or y for continue Else press any key to terminate):- ");
    scanf(" %c", &a);
    if (a == 'Y' || a == 'y')
      goto str;
    else
      return 0;
    break;
  case 2:
    printf("\n::The pages you have visited are::\n");
    trav();
    printf("\nYou want to continue?\n(press Y or y for continue Else press any key to terminate):- ");
    scanf(" %c", &a);
    if (a == 'Y' || a == 'y')
      goto str;
    else
      return 0;
    break;
  default:
    printf("\nSyntax error!\n");
  }
}