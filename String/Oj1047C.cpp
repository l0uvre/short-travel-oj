/***
Description:
Give you a text S and a pattern P. You should print how many times P appears in S.

Input:
The first line will be an integer T, which is the number of test cases. (1 <= T <= 10)

For each test case, the first line will be an integer n, which is the length of the text string.

Then a line contains a text string S. |S| <= 1000000

The third line will be an integer m, which is the length of the pattern string.

Then a line contains a pattern string P. |P| <= |S|

S and will only contain lower case English letters.


Output:
Print a number in a single line for each test case, which means how many times P appears in S.


Input Example:
2
15
chenljnbwowowoo
2
wo
14
touristrealgod
7
tourist


Output Example:
3
1

***/


#include<bits/stdc++.h>
using namespace std;

int main() {

  int t_times;
  string str;
  int strLen;
  string pattern;
  int ptnLen;

  scanf("%d\n", &t_times);

  for (int i = 0; i < t_times; i++) {
    scanf("%d\n", &strLen);
    std::cin >> str;

    scanf("%d\n", &ptnLen);
    std::cin >> pattern;
    //std::cout << str + " " << pattern<< '\n';
    int maTimes;

    size_t found = str.find(pattern);

    while (found != std::string::npos) {
      maTimes++;
      found = str.find(pattern, found+1);
    }

    printf("%d\n", maTimes);
    maTimes = 0;

  }
  return 0;
}
