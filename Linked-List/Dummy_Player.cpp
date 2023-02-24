#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string data;
    Node* prev;
    Node* next;
};

Node* START = nullptr, *NEW, *Curr = nullptr;

void trav_LL()
{
    Node* ptr = START;
    cout << "\n::Play-list::\n";
    if (START == nullptr)
        cout << "\nList is empty!\n";
    else
    {
        do
        {
            cout << "\n" << ptr->data;
            ptr = ptr->next;
        } while (ptr != START);
    }
}

void Insert_Song(string song)
{
    NEW = new Node();
    if (NEW == nullptr) // OverFlow
    {
        cout << "\nValue can't be inserted";
        return;
    }
    else if (START == nullptr)
    {
        NEW->data = song;
        NEW->next = NEW;
        NEW->prev = NEW;
        START = NEW;
        Curr = START;
        cout << "\n" << song << " Inserted successfully!\n";
    }
    else
    {
        NEW->data = song;
        NEW->next = START;
        NEW->prev = START->prev;
        START->prev->next = NEW;
        START->prev = NEW;
        START = NEW;
        Curr = START;
        cout << "\n" << song << " Inserted successfully!\n";
    }
    trav_LL();
}

int main()
{
    int ch = 0, a = 0;
    string song;
    while (ch != 4)
    {
        cout << "\n------------------------------------";
        cout << "\n:::WELCOME TO SOULFUL TRACKS.IN:::\n";
        cout << "------------------------------------\n";
        if (Curr == nullptr)
            cout << "\nSTATUS: Your Play-List is Empty, Insert some songs\n";
        else
            cout << "\nSTATUS: Now Playing: " << Curr->data << "\n";
        cout << "\n1.ADD SONGS & MAKE PLAY-LIST\n2.PLAY NEXT SONG\n3.PLAY PREVIOS SONG\n4.EXIT APP\n";
        cout << "------------------------------------\n";
        cout << "\nWhat's your Mood:- ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "How many songs you want to add?:- ";
            cin >> a;
            do
            {
                cout << "\nEnter Song:- ";
                getline(std::cin >> std::ws,song);
                Insert_Song(song);
                a--;
            } while (a != 0);
            break;
        case 2:
            if (Curr != nullptr)
                Curr = Curr->next;
            else
                cout << "\nYour Play-List is Empty, Insert some songs\n";
            break;
        case 3:
            if (Curr != nullptr)
                Curr = Curr->prev;
            else
                cout << "\nYour Play-List is Empty, Insert some songs\n";
            break;
        case 4:
            cout << "\nExited successfully, THANKS FOR LISTENING";
            break;
        default:
            cout << "\nOOPS Wrong choise! Choose again\n";
        }
    }
    return 0;
}