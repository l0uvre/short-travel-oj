/***
Description:
Lucy asked Huang Bo a question, “You have two 2-D point A and B, please calculate how many integer points in segment A, B. For example, A(1, 3), B(3, 1) only has 1 integer point (2, 2)”.

Input:
There are multiple test cases (less than 1000), for each test, there will be one line contain four integers ax, ay and bx, by, represent the point A and B
Notice that the absolute value of integer is 109.

Output:
One line for each test case, write the number of integer point.


Input Example:
1 3 3 1
1 11 5 3
1 1 9 9

Output Example:
1
3
7

***/

#include <bits/stdc++.h>
using namespace std;

unsigned gcd(unsigned a, unsigned b);

int main() {
  signed x1, y1, x2, y2;
  unsigned result;
  while(cin >> x1 >> y1 >> x2 >> y2){
    result = gcd(abs(y1 - y2), abs(x1 - x2)) - 1;
    cout << result << '\n';
  }
  return 0;
}


unsigned gcd(unsigned a, unsigned b) {
  if (b == 0) {
    return a;
  } else{
    return gcd(b, a%b);
  }
}
