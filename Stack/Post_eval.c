#include <stdio.h>
#include <ctype.h>
char stack[20];
int top = -1;
int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}
int isfull()
{
    if (top == 19)
    {
        return 1;
    }
    return 0;
}
void push(char val)
{
    if (isfull())
    {
        printf("\nStack Is overflow!!");
    }
    top++;
    stack[top] = val;
}
char pop()
{
    if (isEmpty())
    {
        printf("\nStack is underflow!!");
    }
    int val = stack[top];
    top--;
    return val;
}
void post_eval(char *A)
{
    int i = 0; // traverse in original array
    while (A[i] != '\0')
    {
        if (isdigit(A[i]))
        {
            push(A[i] - '0'); // pushing digit only
            i++;
        }
        else
        {
            char a = pop();
            char b = pop();
            if (A[i] == '+')
            {
                push(a + b);
                i++;
            }
            else if (A[i] == '-')
            {
                push(b - a);
                i++;
            }
            else if (A[i] == '*')
            {
                push(a * b);
                i++;
            }
            else
            {
                push(b / a);
                i++;
            }
        }
    }
    printf("\nAnswer is:- %d", pop());
}
int main()
{
    char A[20];
    printf("Enter the postfix expression:- ");
    scanf(" %s", A);
    printf("\n\t:: Answer ::");
    post_eval(A);
}