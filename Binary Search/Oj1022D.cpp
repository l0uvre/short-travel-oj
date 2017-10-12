/***
Description:
Do you remember Index Twin? This time, Cuperman defines (i, j, k) as index triple if A[i]+A[j]+A[k] = m. Given a sorted array A and specific target m, could you help Bo Huang to determine whether there is an index triple in the array A with specific target m?

Input:
The first line contains an integer T(10<T<=100), which is the number of test cases.

For each case contain two lines. The first line contains two numbers n(1<=n<=5000) and m(1<=m<=108), n is the size of array A. m is the specified target.

The second line contains n integers: a1, a2, ... an (1<=ai <= 106 , 1 <= i <= n).

Output:
For each case prints YES or NO

Input Example:
2
5 9
1 2 3 6 7
5 8
1 2 3 6 7

Output Example:
YES
NO

***/

#include <bits/stdc++.h>
using namespace std;

bool find_triple(int nums[], int array_len, int target);

int main() {
  int count, array_len, target;
  cin >> count;

  for (size_t i = 0; i < count; i++) {
    cin >> array_len >> target;
    int nums[array_len];
    for (size_t i = 0; i < array_len; i++) {
      cin >> nums[i];
    }

    if (find_triple(nums, array_len, target)) {
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }

    }
  return 0;
}

bool find_triple(int nums[], int array_len, int target){
  for (int i = 0; i < array_len - 2; i++) {
    int j = i + 1; int k = array_len - 1;
    while (j < k) {
      if (nums[i] + nums[k] + nums[j] < target) {
        j++;
      } else if (nums[i] + nums[k] + nums[j] > target) {
        k--;
      } else{
        return true;
      }
    }
  }

  return false;
}
