/***
Description:
Cuperman has two cups A and B. There are x balls in A, y balls in B. You can move balls between these two cups. The number of balls can be moved from A to B (or from B to A) is equal to the number of balls in B (or in A). For example, if A has 3 balls and B has 2 balls, you only can move 2 balls from A to B, but cannot move 2 balls from B to A. Now Cuperman wants to know, how many move steps he need to obtain one empty cup.

Input:
The first line will be an integer T (T <= 105), which is the number of test cases.

For each test case, you will be given two integers x and y. (0 <= x, y <= 100000)

Output:
For each test case, output the number problem required. If you can't make any cup empty, output -1.

Input Example:
2
5 5
3 5

Output Example:
1
3

***/

#include <bits/stdc++.h>
using namespace std;

int big(int x, int y);

int small(int x, int y);


int main() {
  int count, x, y;
  cin >> count;

  for (int i = 0; i < count; i++) {
    std::cin >> x >> y;
    int large, little;
    int counter = 0;
    large = big(x, y);
    little = small(x, y);
    while (large != 0 && little != 0 && counter < (x + y)) {
      large = large - little;
      little = little * 2;
      counter++;

      int temp = large;
      large = big(large, little);
      little = small(temp, little);
      if (large == 0 || little == 0) {
        std::cout << counter << '\n';
        break;
      }


    }

  if (counter >= (x + y)) {
      cout << -1 << '\n';
    }
  }
}

int big(int x, int y) {
  if (x >= y) {
    return x;
  }
  return y;
}

int small(int x, int y) {
  if (x < y) {
    return x;
  }
  return y;
}
