/***
Description:
After ItakEjgo wrote the problem description, Dr. Tang found out many mistakes. So he asked ItakEjgo to correct his mistakes. But ItakEjgo only has an old machine. The machine has two operations:

Insert(ch, p), insert the char ch to position p.

LookUp(p), look up the char at position p and print it to screen.

ItakEjgo wants you to help him. He will give you a description with many mistakes and several operations. Please follow the operations by using the old machine.


Input:
The first line will be an integer T (1 <= T <= 10), which is the number of test cases.

For each test case, the first line will be a string S, which is the description with mistakes. And the description is in lower case English letters. The second line will be an integer n, which is the number of operations. Then there will be n lines operations. To simplify the problem, 1 will represent Insert and 2 will represent Lookup.

(The length of a string <= 200000, the number of operations <= 10000)


Output:
For each test case, follow the operation the problem gives.


Input Example:
1
madamimadam
4
1 h 1
1 h 2
2 3
2 2

Output Example:
m
h

***/

import  java.util.ArrayList;
import  java.util.Scanner;

public class Main{




    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int count;
        count = sc.nextInt();
        for (int i = 0; i < count; i++) {
            ArrayList<Character> characters = new ArrayList<>(21000);
            sc.nextLine();
            String origin_str = sc.nextLine();
            //System.out.println(origin_str);
            for (int j = 0; j < origin_str.length(); j++) {
                characters.add(origin_str.charAt(j));
            }


            int commands;
            commands = sc.nextInt();
            for (int j = 0; j < commands; j++) {
                int cmd = sc.nextInt();
                if (cmd == 1) {
                    char ch;
                    int p;
                    ch = sc.next(".").charAt(0);
                    p = sc.nextInt();
                    characters.add(p - 1, ch);
                } else if (cmd == 2) {
                    int p;
                    p = sc.nextInt();
                    System.out.println(characters.get(p-1));
                }
            }
        }
    }
}
