#include <stdio.h>
#define SIZE 10
#include <stdlib.h>
#include <string.h>
char queue[SIZE][100];
int front = -1, rear = -1;
void Dequeue()
{
    if (front == rear)
    {
        printf("\nPage %s is removed from history", queue[rear]);
        printf("\nAll data cleared\n");
        front = -1, rear = -1;
        return;
    }
    else
    {
        printf("\nPage %s is removed from history", queue[front]);
        front++;
    }
}
void enqueue(char *str)
{
    if ((rear + 1) % SIZE == front)
    {
        Dequeue();
        rear = (rear + 1) % SIZE;
        strcpy(queue[rear], str);
        printf("\nPage %s added successfully\n", queue[rear]);
    }
    else if (front == -1 && rear == -1)
    {
        front = 0, rear = 0;
        strcpy(queue[rear], str);
        printf("\nPage %s added successfully\n", queue[rear]);
    }
    else
    {
        rear++;
        strcpy(queue[rear], str);
        printf("\nPage %s added successfully\n", queue[rear]);
    }
}
void trav()
{
    if (front == -1 && rear == -1) // empty queue
    {
        printf("\nThere's nothing to show, EMPTY SET!");
    }
    else if (front > rear)
    {
        for (int i = rear; i >= 0; i--)
        {
            printf("\n %s", queue[i]);
        }
        for (int i = SIZE - 1; i >= front; i--)
        {
            printf("\n %s", queue[i]);
        }
    }
    else if (front == rear) // single element
    {
        printf("\n %s", queue[front]);
    }
    else
    {
        for (int i = rear; i >= front; i--)
        {
            printf("\n %s", queue[i]);
        }
    }
}
int main()
{
    int ch;
    char dis, str[50];
Ret:
    printf("Select from below:");
    printf("\n1.Add page of visit\n2.Display visited pages\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("\nWhich page to add for visit??:");
        scanf(" %s", str);
        enqueue(str);
        printf("\nDo you want to continue? ");
        scanf(" %c", &dis);
        if (dis == 'Y' || dis == 'y')
            goto Ret;
        else
            return 0;
        break;
    case 2:
        printf("\nThe pages you have visited are::\n");
        trav();
        printf("\nDo you want to continue? ");
        scanf(" %c", &dis);
        if (dis == 'Y' || dis == 'y')
            goto Ret;
        else
            return 0;
        break;
    }
}