/***
Description:
With the help of you, ItakEjgo finally find out the spy, and reach the castle where Huang Bo lives with the army list and special group.

Huang Bo: How can you arrive here? Why my spy didn’t send any message to me?

ItakEjgo: It’s not important. Today you will die here, and the people in the Linked List Planet don’t need to program anymore!

Huang Bo: Too young too naive! Do you know why I can dominate the Planet? Because I have a special weapon, Zangetsu!

Since the Zangetsu is very powerful, ItakEjgo and the soldier are going to lose. But suddenly, Cuperman comes out and gives ItakEjgo a new weapon. Cuperman tells ItakEjgo that: ” This weapon must be used by two armies at the same time. With this new weapon, the total combat value of the army list will be the multiplication of the combat value of the two armies. By using this, you can defeat Huang Bo and save all planet citizens!”

Finally, Huang Bo lost the war. The people in the Linked List Planet live a happy life! Cuperman and ItakEjgo go back to earth by taking the machine. After they arrived at the earth, ItakEjgo still wants to know what the total combat value of two soldier list is. Since ItakEjgo is not good at math, so he asked your help again.

Input:
First line will be a positive integer T (T<=10), which is the number of messages.

The first line will be an integer n, which is the number of terms of the first polynomial. Then n lines will be the (coefficient, exponent) pairs.

After n + 1 lines, there will be an integer m for the number of terms of the second polynomial. And m lines of the (coefficient, exponent) pairs.

(1 <= n, m <= 100, all coefficients are in the range [1, 10000], all exponents are in the range [0,10^9])

Output:
For each message, print the polynomial with the same syntax as the sample shows.

Input Example:
1
2
1 1
1 2
2
1 1
1 2

Output Example:
x^2+2x^3+x^4

***/



import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    private static class Node{
        long coe;
        long pwr;
        Node next;
        public Node(){

        }
        public Node(long coe, long pwr) {
            this.coe = coe;
            this.pwr = pwr;
            this.next = null;
        }
    }

    public static Node push(Node head, long coe, long pwr) {
        Node oldHead = head;
        head = new Node(coe, pwr);
        head.next = oldHead;
        return head;
    }

    public static Node push_or_add(Node head, long coe, long pwr) {
        Node temp = head;
        //Node pNode = head;
        Node qNode = head;

        if (head.pwr < pwr) {
            Node oldHead = head;
            head = new Node(coe, pwr);
            head.next = oldHead;
            return head;
        }

        while (temp != null) {
            if (temp.pwr == pwr) {
                temp.coe += coe;
                return head;
            }
            temp = temp.next;

        }


        Node newNode = new Node(coe, pwr);


        while(qNode != null) {
            if (qNode.next == null) {
                qNode.next = newNode;
                break;
            }

            if (pwr > qNode.next.pwr && pwr < qNode.pwr) {
                newNode.next = qNode.next;
                qNode.next = newNode;
                return head;
            }
            qNode = qNode.next;

        }


        return head;
    }

    public static Node multiply_poly(Node first, Node second) {
        long coe, pwr;
        Node temp1 = first; Node temp2 = second;
        Node temp2_2 = second;
        Node result = new Node(0, 0);
        if (first == null || second == null) {
            return null;
        }

        while (temp1 != null) {
            while (temp2 != null) {
                coe = temp1.coe * temp2.coe;
                pwr = temp1.pwr + temp2.pwr;
                result = push_or_add(result, coe, pwr);
                temp2 = temp2.next;
            }
            temp2 = temp2_2;
            temp1 = temp1.next;
        }

        return result;
    }

    public static void print_poly(Node poly) {
        List<Long> coes = new ArrayList<>();
        List<Long> pwrs = new ArrayList<>();
        while (poly != null) {
            if (poly.coe != 0) {
                coes.add(poly.coe);
                pwrs.add(poly.pwr);
            }
            poly = poly.next;
        }
        if (coes.size() == 0) {
            System.out.printf("0\n");
            return;
        }
        for (int i = coes.size()-1; i >= 0; i--) {
            if (pwrs.get(i) == 0) {
                if (coes.get(i) != 0) {
                    System.out.printf("%d", coes.get(i));
                }
            } else if (pwrs.get(i) == 1) {
                if (coes.get(i) != 0) {
                    if (i != coes.size() - 1) {
                        if (coes.get(i) > 0) {
                            System.out.printf("+");
                        }

                    }
                    if (coes.get(i) == 1) {
                        System.out.printf("x");
                    } else if (coes.get(i) == -1) {
                        System.out.printf("-x");
                    } else {
                        System.out.printf("%dx", coes.get(i));
                    }
                }
            }
            else {
                if (coes.get(i) != 0) {
                    if (i != coes.size() - 1) {
                        if (coes.get(i) > 0) {
                            System.out.printf("+");
                        }
                    }
                    if (coes.get(i) == 1) {
                        System.out.printf("x^%d", pwrs.get(i));
                    } else if (coes.get(i) == -1) {
                        System.out.printf("x^%d", pwrs.get(i));
                    } else {
                        System.out.printf("%dx^%d", coes.get(i), pwrs.get(i));
                    }
                }
            }
        }
        System.out.println();
    }

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        int count;
        count = scanner.nextInt();

        for (int i = 0; i < count; i++){
            Node first_poly = new Node(0, 0);
            Node second_poly = new Node(0, 0);
            Node result;
            int term1, term2;
            long coe, pwr;
            term1 = scanner.nextInt();
            for (int j = 0; j < term1; j++) {

                coe = scanner.nextLong();
                pwr = scanner.nextLong();
                first_poly = push(first_poly, coe, pwr);
            }

            term2 = scanner.nextInt();
            for (int j = 0; j < term2; j++) {
                coe = scanner.nextLong();
                pwr = scanner.nextLong();
                second_poly = push(second_poly, coe, pwr);
            }
            //print_poly(first_poly);
            result = multiply_poly(first_poly,second_poly);
            print_poly(result);
        }

    }


}
