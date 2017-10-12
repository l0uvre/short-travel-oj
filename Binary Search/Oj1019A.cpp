/***
Description:
In CS203 class, given an integer N, you know how to calculate 1 + 2 + 3 + … + N. This time, Bo Huang wants you to compute 12 + 22 + 32 + ... + N2

Input:
The first line will be an integer T(1<T<=1000), which is the number of test cases.
For each test data, you will be given an integer N (1 <= N <= 106 ).

Output:
For each case please print the sum of 12 + 22 + 32 + ... + N2.


Input Example:
1
5

Output Example:
55

***/


#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  uint64_t b, result;
  cin >> a;

  for (size_t i = 0; i < a; i++) {
    cin >> b;
    result = b*(2*b+1)*(b+1)/6;
    cout << result << endl;
  }
  return 0;
}
