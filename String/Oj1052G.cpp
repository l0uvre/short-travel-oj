/***
Description:
As we defined in problem E. A prefix of a string S is S0,i, similarly, a suffix of a string S is Si,|s|-1.

If a substring of S is both a prefix and suffix, we defined the substring is a presuffix. Now give you a string S, please print all presuffix.

Input:
The first line will be an integer T, which is the number of test cases. (1 <= T <= 10)

For each test case, there will be a line with an integer n, which is the length of the string.

Then there is a line with a string S. |S| <= 100000.

S will only contain lower case English letters.


Output:
Several lines for each test case. All presuffix of S. And each presuffix should in a single line.

There is en empty line between each test case (Including the last test case).

Print all presuffix by their length in ascending order.


Input Example:
2
5
abaab
5
aaaaa

Output Example:
ab
abaab

a
aa
aaa
aaaa
aaaaa

***/



#include<bits/stdc++.h>
using namespace std;


void computeNextArray(string pat, int nt[])
{
    nt[0] = -1;
    int j = 0;
    int k = -1;
    int ptnLen = (int)pat.length();

    while(j < ptnLen - 1)
    {
      if( k == -1 || pat[j] == pat[k])
      {
        nt[++j] = ++k;
      }
      else
      {
        k = nt[k];
      }
    }


}

int main()
{
    int t_times;
    int ptnLen;

    string pattern;
    std::cin.tie(0);

    std::cin >> t_times;
    for (int i = 0; i < t_times; i++)
    {
      std::vector<int> v = {};
      std::cin >> ptnLen;
      std::cin >> pattern;
      pattern.push_back('A');
      int nt[ptnLen + 1];
      computeNextArray(pattern, nt);

      int j = nt[ptnLen];
      while (j != 0) {
        v.push_back(j - 1);
        j = nt[j];
      }

      for (int k = v.size()-1; k >=0 ; k--)
      {
        string result = pattern.substr(0, v[k]+1);
        std::cout << result << '\n';
      }
      pattern.pop_back();
      std::cout<<pattern << '\n';
      std::cout << '\n';

    }
}
