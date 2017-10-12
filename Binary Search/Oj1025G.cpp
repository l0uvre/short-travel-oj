/***
Description:
In CS203 lab 1, OJ sorted the scores of Group 3 students in ascending order in array S.

Cuperman wants to know the first position of a given score X, could you help him?

Input:
Standard input will contain multiple test cases. The first line of the input is a single integer T (1 <= T <= 10) which is the number of test cases.

T test cases follow, for each test case:

The first line contains an integer N( 1 <= N <= 104 )

The second line contains N integers, which are sorted scores {S[1], S[2], S[3], …, S[n]}. where 0 <= S[i] <= 109 .

Then a single line with an integer Q (0 <= Q <= 104)

Then there will be Q lines. Each line will give an integer x.

Output:
For each query, output the first position i in array S such that S[i] = X, if X is not in the array S, output -1.

Input Example:
1
6
1 2 2 4 5 6
2
2
7

Output Example:
2
-1

***/

#include <bits/stdc++.h>
using namespace std;

int main() {
  int count, array_len, query;
  cin >> count;

  for (int i = 0; i < count; i++) {
    cin >> array_len;
    int nums[array_len];
    for (int i = 0; i < array_len; i++) {
      cin >> nums[i];
    }
    std::cin >> query;
    for (size_t i = 0; i < query; i++) {
      int score;
      std::cin >> score;
      int start, end, pos;
      start = 0; end = array_len - 1; pos = -1;
      while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] < score) {
          start = mid + 1;
        } else if (nums[mid] > score) {
          end = mid - 1;
        } else{
          pos = mid + 1;
          end = mid - 1;
        }
      }
      std::cout << pos << endl;
    }

  }
}
