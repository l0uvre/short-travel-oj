/***
Description:
Given an sorted integer array A and a specific target m. Cuperman defines (i,j) is index twin if A[i] + A[j] = m. Could you help Cuperman to find how many index twins are in the given array A with a specific target m.

Input:
The first line will be an integer T(1<T<=10), which is the number of test cases.

For each case contain two lines.The first line contains two numbers n(1<=n<=5000) and m(1<=m<=108), n is the size of array A. m is the specified target.

The second line contains n integers: a1, a2, ... an (1<=ai <= 106, 1 <= i <= n).

Output:
For each case print a number, the number of index twins.


Input Example:
3
4 5
1 2 3 4
4 9
2 7 11 15
3 6
1 2 3

Output Example:
2
1
0

***/

#include <bits/stdc++.h>
using namespace std;

int main() {
  int count, array_len, target;
  cin >> count;

  for (size_t i = 0; i < count; i++) {
    cin >> array_len >> target;
    int nums[array_len]; int target_num;
    for (size_t i = 0; i < array_len; i++) {
      cin >> nums[i];
    }

    for (size_t i = 0; i < array_len; i++) {
      for (size_t j = i + 1; j < array_len; j++) {
        if ((nums[i] + nums[j]) == target) {
          target_num++;
        }
      }
    }
    cout << target_num << endl;
    target_num = 0;
  }
  return 0;
}
