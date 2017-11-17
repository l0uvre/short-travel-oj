#include<bits/stdc++.h>
using namespace std;


//http://www.jianshu.com/p/8b21a1d6af8b
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

// Driver program to test above function
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
