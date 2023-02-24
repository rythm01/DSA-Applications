#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} Node;
Node *NEW, *START1 = NULL, *START2 = NULL, *START3 = NULL;
void trav_DLL(Node *HEAD)
{
    Node *ptr = HEAD;
    if (HEAD == NULL)
        printf("\nList is empty!\n");
    else
    {
        do
        {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        } while (ptr != HEAD);
    }
}
Node *Insert_First(Node *HEAD, int val) // insert at front index of Doubly Link-List
{
    NEW = (Node *)malloc(sizeof(Node));
    if (NEW == NULL) // OverFlow
    {
        printf("\nValue can't be inserted");
        return NULL;
    }
    else if (HEAD == NULL)
    {
        NEW->data = val;
        NEW->next = NEW;
        NEW->prev = NEW;
        HEAD = NEW;
    }
    else
    {
        NEW->data = val;

        NEW->next = HEAD;
        NEW->prev = HEAD->prev;
        HEAD->prev->next = NEW;
        HEAD->prev = NEW;

        HEAD = NEW;
    }
    return HEAD;
}
Node *Make_list(Node *HEAD, int num)
{
    int last = 0;
    if (num == 0)
        HEAD = Insert_First(HEAD, last);
    else
    {
        for (int i = 0; num != 0; i++)
        {
            last = num % 10;
            HEAD = Insert_First(HEAD, last);
            num /= 10;
        }
    }
    return HEAD;
}
Node *ADD_LIST(Node *HEAD1, Node *HEAD2)
{
    Node *ptr1 = HEAD1->prev;
    Node *ptr2 = HEAD2->prev;
    int val1 = 0, val2 = 0, sum = 0, carry = 0;
    while (ptr1 != HEAD1 || ptr2 != HEAD2)
    {
        val1 = ptr1->data;
        val2 = ptr2->data;
        sum = val1 + val2 + carry;
        carry = 0;
        if (sum > 9)
        {
            int last = sum % 10;
            START3 = Make_list(START3, last);
            carry = sum / 10;
        }
        else
        {
            START3 = Make_list(START3, sum);
        }
        ptr1 = ptr1->prev;
        ptr2 = ptr2->prev;
    }
    val1 = HEAD1->data;
    val2 = HEAD2->data;
    sum = val1 + val2 + carry;
    START3 = Make_list(START3, sum);
    return START3;
}
int main()
{
    int num1 = 0, num2 = 0;
    printf("\nEnter number 1:- ");
    scanf(" %d", &num1);
    printf("\nEnter number 2:- ");
    scanf(" %d", &num2);

    START1 = Make_list(START1, num1);
    printf("List1:\t\t");
    trav_DLL(START1);

    START2 = Make_list(START2, num2);
    printf("\nList2:\t\t");
    trav_DLL(START2);

    printf("\n--------------------------------------------");
    printf("\nADDITION\t");
    START3 = ADD_LIST(START1, START2);
    trav_DLL(START3);
}