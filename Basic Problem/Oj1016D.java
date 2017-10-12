/***
Description:
Cuperman defines CS203 Lucky number as that if you rotate the number 180 degrees the number will not change. For example, 69, 96, 111, 181 are lucky numbers. 87, 76 are not.(0, 1, 8 will not change in this way, 6 will change into 9, 9 will change into 6. 2 and 5 can't change to each other) Now Cuperman wants to know the number of CS203 lucky number between range L and R, so she asked Huang Bo, as you know, Huang Bo is lazy, he wants you to solve this problem!

Input:
There are multiple test cases(less than 10), each test will contain two integers L and R.
Notice the range of L and R is 0 <= L <= R <= 10^12

Output:
A single line for each test case, represent the number of lucky number in [L, R].


Input Example:
50 100

Output Example:
3

***/


public class Oj1016D {

  public static void main(String[] args) {

    Scanner scanner = new Scanner(System.in);
    int count = 0;
    long begin, end;

    while (scanner.hasNext()) {
      begin = scanner.nextLong();
      end = scanner.nextLong();

      for (int i = 1; i < 13; i++) {
        List<Long> lucks = luckyNum(i);
        for (Long num : lucks) {
          if (num <= end && num >= begin) {
            count++;
          }
        }
      }

      System.out.println(count);
      count = 0;
    }

    // System.out.println(count);
    // System.out.println(i);
  }

  private static List<Long> luckyNum(int n) {
    List<Long> lucks = new ArrayList<>();
    if (n == 1) {
      lucks.add(0L);
      lucks.add(1L);
      lucks.add(8L);
      return lucks;
    } else if (n == 2) {
      lucks.add(11L);
      lucks.add(69L);
      lucks.add(88L);
      lucks.add(96L);
      return lucks;
    } else {
      int i = n - 2;
      while (i > 0) {
        List<Long> alList = luckyNum(i);
        for (long num : alList) {
          lucks.add((long) (9 * Math.pow(10, n - 1) + num * Math.pow(10, (n - i) / 2) + 6));
          lucks.add((long) (6 * Math.pow(10, n - 1) + num * Math.pow(10, (n - i) / 2) + 9));
          lucks.add((long) (8 * Math.pow(10, n - 1) + num * Math.pow(10, (n - i) / 2) + 8));
          lucks.add((long) (1 * Math.pow(10, n - 1) + num * Math.pow(10, (n - i) / 2) + 1));
        }

        i = i - 2;
      }

      if (i == 0) {
        lucks.add((long) (9 * Math.pow(10, n - 1) + 6));
        lucks.add((long) (6 * Math.pow(10, n - 1) + 9));
        lucks.add((long) (8 * Math.pow(10, n - 1) + 8));
        lucks.add((long) (1 * Math.pow(10, n - 1) + 1));
      }

      return lucks;
    }

  }
}
