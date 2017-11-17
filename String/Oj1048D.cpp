#include<bits/stdc++.h>


//C/cpp: never declare a local variable and return it, as it only stands for address.



bool skip[1000010] = {false};
int count = 0;

int KMPSearch(std::string pat, std::string txt, int nt[])
{
    int M = pat.length();
    int N = txt.length();

    //int count = 0;   Very Wrong way. Maybe in Java is okay.

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
        count++;
        skip[i-j] = true;
        //v.push_back(i-j);
        j = 0;
        //i = 0;
      }
    }

    return count;

}



void computeNextArray(std::string pat, int nt[])
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
  char str1[1000010];
  char pattern1[1000010];
  //bool skip[1000010] = {false};

  //string pattern;

  //std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  scanf("%d\n", &t_times);
  //std::cin >> t_times;

  for (int i = 0; i < t_times; i++)
  {
    scanf("%d\n", &strLen);
    //std::cin >> strLen;
    scanf("%s\n", str1);

    //std::cin >> ptnLen;

    scanf("%d\n", &ptnLen);

    scanf("%s\n", pattern1);
    //std::cin >> pattern;

    std::string str(str1), pattern(pattern1);

    //std::cout << str << '\n';
    //std::cout << pattern << '\n';

    int nt[ptnLen];

    computeNextArray(pattern, nt);

    int searched = KMPSearch(pattern, str, nt);

    //std::cout << searched << '\n';


    while (searched != 0)
    {

      for (int k = strLen - 1; k >= 0; k--)
      {
        if (skip[k]) {
          str.erase((size_t)k, ptnLen);
          count--;
          skip[k] = false;
        }
      }

      searched = KMPSearch(pattern, str, nt);

    }



    std::cout << str << '\n';

  }
  return 0;
}
