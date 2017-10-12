/***
Description:
Doudizhu is a very popular poker card game. It has three players, two of them are Farmers, Farmer has 17 cards and the third player is Dizhu, Dizhu has 20 cards. Cuperman likes Doudizhu, but he is lazy, he does not want to sort cards in his hand. One day, when he is playing Doudizhu with Lucy and Lily, he asked Huang Bo to sort his cards by the following order: Red joker is the left most one, and White joker will be the second one. Then sort the cards by the number of cards Cuperman has. If the number of cards are the same, sort them as the follow order: Red joker > White joker > 2 > A > K > Q > J > 10 > 9 > 8 > 7 > 6 > 5 > 4 >3. For example, if he not a Dizhu, he has Red joker, four K, three 2, four 9, one A, two 6, two 5, the order will be

                         Red joker K K K K 9 9 9 9 2 2 2 6 6 5 5 A

As we all know, Huang Bo is TA of CS203, he asks the students in his course to help him.

Input:
There are multiple test cases (less than 20), for each case, you will be given a string in the first line show whether Cuperman is a Farmer or Dizhu.
Next line contains either 17 or 20 cards, i.e., the cards in Cuperman’s hand.(Red joker will be RJ, and White joker will be WJ).

Output:
One line for each test case, give the cards in order according to the problem.
Please notice that there are no space in the end of line.


Input Example:
Farmer
RJ K 2 2 K K K 2 9 9 A 6 6 5 5 9 9
Dizhu
WJ RJ 9 8 K Q Q 4 3 8 5 4 3 8 K 6 J J 7 A

Output Example:
RJ K K K K 9 9 9 9 2 2 2 6 6 5 5 A
RJ WJ 8 8 8 K K Q Q J J 4 4 3 3 A 9 7 6 5

***/


import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Oj1015C {
  public static void main(String[] args) {
  Scanner scanner = new Scanner(System.in);


  while (scanner.hasNext()) {
  String a = scanner.nextLine();
  List<String> result = new ArrayList<>();
  if (a.equals("Farmer")) {
    for (int i = 0; i < 17; i++) {
      result.add(scanner.next());
    }
  } else if (a.equals("Dizhu")) {
    for (int i = 0; i < 20; i++) {
      result.add(scanner.next());

    }
  }

  result = sortCard(result);
  for (int i = 0; i < result.size(); i++) {
    if (i < result.size() - 1) {
      System.out.printf("%s ", result.get(i));
    }
    else {
      System.out.printf("%s\n", result.get(i));
    }
  }
  }

}

private static List<String> sortCard(List<String> cards) {
  List<String> result = new ArrayList<>();
  List<Integer> frequency = new ArrayList<Integer>();
  String[] unique = {"2","A","K","Q","J","10","9","8","7","6","5","4","3"};
  if (cards.contains("RJ")) {
    result.add("RJ");
  }

  if (cards.contains("WJ")) {
    result.add("WJ");
  }
  for (String s : cards) {

      if (!frequency.contains(Collections.frequency(cards, s))) {
        frequency.add(Collections.frequency(cards, s));
      }

  }
  Collections.sort(frequency);

  for (int i = frequency.size() - 1; i >= 0; i--) {
    for (String s : unique) {
      if (Collections.frequency(cards, s) == frequency.get(i)) {
          for (int j = 0; j < frequency.get(i); j++) {
            result.add(s);
          }
        }
      }
  }

  return result;

  }
}
