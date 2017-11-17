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

// Driver program to test above function
int main()
{
    int t_times;
    //int strLen;
    int ptnLen;
    //string str;
    string pattern;
    //std::vector<int> v = {};
    //std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

    std::cin >> t_times;
    for (int i = 0; i < t_times; i++)
    {
      std::vector<int> v = {};
      //std::cin >> strLen;
      //std::cin >> str;
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
        //std::cout << v[k] << '\n';
          string result = pattern.substr(0, v[k]+1);
          std::cout << result << '\n';
      }
      pattern.pop_back();
      std::cout<<pattern << '\n';

      std::cout << '\n';

    }
}
