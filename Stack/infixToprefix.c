#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int stack[20]; //Making stack of size=20
int top = -1;
int isEmpty()
{
  if (top == -1)
  {
    return 1;
  }
  return 0;
}
int isFull()
{
  if (top == 9)
  {
    return 1;
  }
  return 0;
}
void push(char val)
{
  if (isFull())
  {
    printf("\nSTACK is overflow::");
  }
  else
  {
    top++;
    stack[top] = val;
  }
}
char pop()
{
  if (isEmpty())
  {
    printf("\nSTACK is underflow");
  }
  else
  {
    char val = stack[top];
    top--;
    return val;
  }
}
char stack_top()
{
  return stack[top];
}
int isoperator(char val)
{
  if (val == '+' || val == '-' || val == '*' || val == '/')
  {
    return 1;
  }
  return 0;
}
int presidence(char val)
{
  if (val == '/' || val == '*')
    return 3;
  else if (val == '+' || val == '-')
    return 2;
  else
    return 0;
}
char *infix2postfix(char *infix)
{
  char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char)); //making postfix arr(string),size is +1 bcz ending element of str is '\0';
  int i = 0;                                                          //counter variable which traverse at infix string(arr);
  int j = 0;                                                          //counter variable which traverse at postfix String(arr);
  while (infix[i] != '\0')
  {
    if (isoperator(infix[i]))
    {
      if (presidence(infix[i]) > presidence(stack_top()))
      {
        push(infix[i]);
        i++;
      }
      else
      {
        postfix[j] = pop();
        j++;
      }
    }
    else
    {
      postfix[j] = infix[i];
      i++;
      j++;
    }
  }
  while (!isEmpty())
  {
    postfix[j] = pop();
    j++;
  }
  postfix[j] = '\0';
  return postfix;
}
int main()
{
  char infix[100]; //making infix array
  printf("Enter the string:- ");
  gets(infix);
  printf("INFIX TO PREFIX:- %s",strrev(infix2postfix(strrev(infix))));
  return 0;
}