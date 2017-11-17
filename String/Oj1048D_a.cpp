#include<bits/stdc++.h>
using namespace std;

std::vector<int> v = {};

vector<int> KMPSearch(string pat, string txt, int nt[])
{

    int M = pat.length();
    int N = txt.length();

    int i = 0; //pos for txt
    int j = 0; // pos for pattern

    while (i < N && j < M)
    {
      if( j == -1 || txt[i] == pat[j])
      {
        i++;
        j++;
      }
      else
      {
        j = nt[j];
      }

      if (j == M)
      {
        //printf("Found pattern at index %d\n", i-j);
        v.push_back(i-j);
        j = 0;
        //i = 0;
      }
    }

    return v;

}



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


int main() {

  int t_times;
  int strLen;
  int ptnLen;
  string str;
  string pattern;

  //std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);


  std::cin >> t_times;

  for (int i = 0; i < t_times; i++)
  {
    std::cin >> strLen;
    std::cin >> str;

    std::cin >> ptnLen;

    std::cin >> pattern;

    int nt[ptnLen];

    computeNextArray(pattern, nt);
    std::vector<int> index = KMPSearch(pattern, str, nt);

    while (!index.empty())
    {

      int k = index.size() - 1;
      while (k >= 0)
      {
        str.erase((size_t)index[k], ptnLen);
        v.pop_back();
        k--;
      }
      index = KMPSearch(pattern, str, nt);

    }



    std::cout << str << '\n';

  }
  return 0;
}
