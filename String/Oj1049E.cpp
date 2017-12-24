/***
Description:
Do you know how to hash a string? Normally we represent a string in an integer. Then we can transfer from dealing with strings to dealing with integers, which is more convenient. A popular way of hashing a string is:Shash=∑|S0,i|*cnt(S0,i). where Shash is an integer, which is the hash value. S0,i is the substring of S from position 0 to position i. cnt(S0,i) is how many times S0,i appears in S. Now give you a string S, please calculate the hashed value Shash.


Input:
The first line will be an integer T, which is the number of test case. (1 <= T <= 10)

The first line for each test case will be an integer n, which is the length of string S.

Then there is a line with string S. |S| <= 1000000

S will only contain lower case English letters.


Output:
Print an integer for each test case, the hashed value.

Input Example:
1
3
aaa

Output Example:
10

***/


#include<bits/stdc++.h>
using namespace std;


//https://www.cnblogs.com/yjiyjige/p/3263858.html
//https://www.cnblogs.com/tangzhengyue/p/4315393.html

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
    string str;
    int strLen;
    std::cin.tie(0);

    std::cin >> t_times;
    for (int i = 0; i < t_times; i++)
    {
      std::cin >> strLen;
      int nt[strLen+1];
      int count[strLen+1];
      long long result = 0;
      std::cin >> str;
      str.push_back('A');

      computeNextArray(str, nt);

      count[0] = 0;

      for (int j = 1; j <= strLen; j++) {
        count[j] = 1;
      }
      for (int j = strLen; j > 0; j--) {
        count[nt[j]] += count[j];
      }
      for (int j = 1; j <= strLen; j++) {
        result += count[j] * j;
      }
      std::cout << result << '\n';
    }

    return 0;
}
