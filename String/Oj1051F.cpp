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
      std::cin >> ptnLen;
      std::cin >> pattern;

      pattern.push_back('A');

      int nt[ptnLen + 1];

      computeNextArray(pattern, nt);

      int m = ptnLen;

      int j = nt[m];

      int k = m - j;

      pattern.pop_back();
      std::cout<< k << '\n';

      //std::cout << '\n';

    }
}
