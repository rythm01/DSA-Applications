import java.util.Scanner;
import java.util.Stack;

public class isDome {

    public static String CheckDome(String st) {
        if (st == "")
            return new String("false");

        Stack<String> stack = new Stack<>();
        String ans = "true";
        int life = 1;

        for (int i = 0; i < st.length(); i++) {
            if (st.charAt(i) == '<') {
                if (st.charAt(++i) == '/') {
                    if (stack.isEmpty())
                        return new String("false");
                    String prev = stack.pop();
                    String curr = "";
                    int j = i + 1;
                    while (st.charAt(j) != '>') {
                        curr += st.charAt(j);
                        j++;
                    }
                    if (!prev.equals(curr)) {
                        if (life == 1) {
                            life--;
                            ans = prev;
                        } else
                            ans = "false";
                    }
                } else if(st.charAt(++i) != '/') {
                    String tag = "";
                    int j = i-1;
                    while (st.charAt(j) != '>' && st.charAt(j) != ' ') {
                        tag += st.charAt(j);
                        j++;
                    }
                    stack.push(tag);
                }
            }
        }
        if (!stack.isEmpty())
            return new String("false");
        else
            return ans;
    }

    public static void main(String[] args) {
        String st;
        Scanner sc = new Scanner(System.in);
        st = sc.nextLine();

        System.out.println(CheckDome(st));
    }
}
