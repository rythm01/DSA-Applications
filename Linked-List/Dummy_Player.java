import java.util.Scanner;

class Node {
    String data;
    Node prev;
    Node next;

    Node(String data) {
        this.data = data;
        prev = null;
        next = null;
    }
}

public class Dummy_Player {
    private static Node START = null;
    private static Node NEW, Curr = null;

    private static void travLL() {
        Node ptr = START;
        System.out.println("\n::Play-list::");
        if (START == null) {
            System.out.println("\nList is empty!");
        } else {
            do {
                System.out.println("\n" + ptr.data);
                ptr = ptr.next;
            } while (ptr != START);
        }
    }

    private static void insertSong(String song) {
        NEW = new Node(song);
        if (NEW == null) {
            System.out.println("\nValue can't be inserted");
            return;
        } else if (START == null) {
            NEW.next = NEW;
            NEW.prev = NEW;
            START = NEW;
            Curr = START;
            System.out.println("\n" + song + " Inserted successfully!\n");
        } else {
            NEW.next = START;
            NEW.prev = START.prev;
            START.prev.next = NEW;
            START.prev = NEW;
            START = NEW;
            Curr = START;
            System.out.println("\n" + song + " Inserted successfully!\n");
        }
        travLL();
    }

    public static void main(String[] args) {
        int ch = 0, a = 0;
        String song;
        Scanner sc = new Scanner(System.in);
        while (ch != 4) {
            System.out.println("\n------------------------------------");
            System.out.println(":::WELCOME TO SOULFUL TRACKS.IN:::");
            System.out.println("------------------------------------");
            if (Curr == null)
                System.out.println("\nSTATUS: Your Play-List is Empty, Insert some songs\n");
            else
                System.out.println("\nSTATUS: Now Playing: " + Curr.data + "\n");

            System.out.println("1.ADD SONGS & MAKE PLAY-LIST");
            System.out.println("2.PLAY NEXT SONG");
            System.out.println("3.PLAY PREVIOS SONG");
            System.out.println("4.EXIT APP");
            System.out.println("------------------------------------");
            System.out.print("\nWhat's your Mood:- ");
            ch = sc.nextInt();
            switch (ch) {
                case 1:
                    System.out.print("How many songs you want to add?:- ");
                    a = sc.nextInt();
                    do {
                        System.out.print("\nEnter Song:- ");
                        song = sc.nextLine();
                        if (song.isEmpty()) {
                            song = sc.nextLine();
                        }
                        insertSong(song);
                        a--;
                    } while (a != 0);
                    break;
                case 2:
                    if (Curr != null)
                        Curr = Curr.next;
                    else
                        System.out.println("\nYour Play-List is Empty, Insert some songs\n");
                    break;
                case 3:
                    if (Curr != null)
                        Curr = Curr.prev;
                    else
                        System.out.println("\nYour Play-List is Empty, Insert some songs\n");
                    break;
                case 4:
                    System.out.println("\nExited successfully , THANKS FOR LISTENING");
                    break;
                default:
                    System.out.println("\nOOPS Wrong choise! Choose again\n");
            }
        }
        sc.close();
    }
}