/***
Description:
Give you a string, you should print how many none empty substrings it has.

Input:
The first line is number of tests. T (1 <= T <= 10)

The second line is a string S. The length of S doesn’t exceed 1000, that is |S| <= 1000

S will only contain lower case English letters.


Output:
For each test, you should print an integer in a single line, which is the number of none empty substrings of S.

Input Example:
1
hello

Output Example:
15

***/

#include<bits/stdc++.h>
using namespace std;

int main() {

  int t_times;
  string str_read;

  scanf("%d\n", &t_times);

  for (int i = 0; i < t_times; i++) {
    std::cin >> str_read;
    int allLen = str_read.length();
    int result = (1 + allLen) * allLen / 2;
    printf("%d\n", result);
  }
  return 0;
}
