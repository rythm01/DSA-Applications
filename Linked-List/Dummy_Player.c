#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char data[30];
    struct node *prev;
    struct node *next;
} Node;
Node *START = NULL, *NEW, *Curr = NULL;
void trav_LL()
{
    Node *ptr = START;
    printf("\n::Play-list::\n");
    if (START == NULL)
        printf("\nList is empty!\n");
    else
    {
        do
        {
            printf("\n%s", ptr->data);
            ptr = ptr->next;
        } while (ptr != START);
    }
}
void Insert_Song(char *song)
{
    NEW = (Node *)malloc(sizeof(Node));
    if (NEW == NULL) // OverFlow
    {
        printf("\nValue can't be inserted");
        return;
    }
    else if (START == NULL)
    {
        strcpy(NEW->data, song);
        NEW->next = NEW;
        NEW->prev = NEW;
        START = NEW;
        Curr = START;
        printf("\n%s Inserted successfully!\n", song);
    }
    else
    {
        strcpy(NEW->data, song);

        NEW->next = START;
        NEW->prev = START->prev;
        START->prev->next = NEW;
        START->prev = NEW;

        START = NEW;
        Curr = START;
        printf("\n%s Inserted successfully!\n", song);
    }
    trav_LL();
}
int main()
{
    int ch = 0, a = 0;
    char *song = (char *)malloc(sizeof(char));
    while (ch != 4)
    {
        printf("\n------------------------------------");
        printf("\n:::WELCOME TO SOULFUL TRACKS.IN:::\n");
        printf("------------------------------------\n");
        if (Curr->data == NULL)
            printf("\nSTATUS: Your List is Empty, Insert some songs\n");
        else
            printf("\nSTATUS: Now Playing: %s\n", Curr->data);

        printf("\n1.ADD SONG IN PLAY-LIST\n2.PLAY NEXT SONG\n3.PLAY PREVIOS SONG\n4.EXIT APP\n");
        printf("------------------------------------\n");
        printf("\nWhat's your Mood:- ");
        scanf(" %d", &ch);
        switch (ch)
        {
        case 1:
            printf("How many songs you want to add?:- ");
            scanf(" %d", &a);
            do
            {
                printf("\n\nEnter Song:- ");
                scanf(" %[^\n]s",song);
                Insert_Song(song);
                a--;
            } while (a != 0);
            break;
        case 2:
            if (Curr->data != NULL)
                Curr = Curr->next;
            else
                printf("\nYour List is Empty, Insert some songs\n");
            break;
        case 3:
            if (Curr->data != NULL)
                Curr = Curr->prev;
            else
                printf("\nYour List is Empty, Insert some songs\n");
            break;
        case 4:
            printf("\nExited successfully , THANKS FOR LISTENING");
            break;
        default:
            printf("\nOOps Wrong choise! Choose again\n");
        }
    }
}