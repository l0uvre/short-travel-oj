/***
Description:
The idea of binary search is extremely beautiful! However, write a bug-free binary search program is not so easy. Bo Huang wants you to code a bug-free binary search program for him.

Given an ascending sorted array A with n integers, and if integer m is in the array, returns “YES”, otherwise “NO”

Input:
The first line will be an integer T(100<=T<=1000), which is the number of test cases.

For each case have two lines. The first line of the input contains two number n and m, n is the length of the array(1<=n<=106). You should determine whether m (1<=m<=108) is in the array or not. The second line contains the values in the array.


Output:
For each case, output only one line print YES or NO.


Input Example:
2
3 2
1 2 3
3 4
1 2 3

Output Example:
YES
NO

***/

#include <iostream>
using namespace std;

int main() {
  int count, array_len, target;
  cin >> count;

  for (size_t i = 0; i < count; i++) {
    cin >> array_len >> target;
    int nums[array_len];
    for (size_t i = 0; i < array_len; i++) {
      cin >> nums[i];
    }

    int start = 0; int end = array_len - 1;
    int mid;
    while (start <= end) {
      mid = start + (end - start) / 2;
      if (nums[mid] < target) {
        start = mid + 1;
      } else if (nums[mid] > target) {
        end = mid - 1;
      } else {
        cout << "YES" << endl;
        break;
      }
    }
    if (start > end) {
      cout << "NO" << endl;
    }
  }
  return 0;
}
