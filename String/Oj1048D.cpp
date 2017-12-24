/***
Description:
Do you believe in Magic? There is a magic abracadabra which can let you get AC to all problems in CS203 Lab5. But the abracadabra has some useless word. Give you the abracadabra S and a useless word T. Please print the abracadabra after delete all useless word. And pay attention to that you should remove the word from left to the right. That is, if we remove bab from babab , the result is ab.


Input:
The first line is the number of test cases T. (1 <= T <= 10)

The second line is the length of abracadabra, n.

Then there is a line with a string S, which is the abracadabra. |S| <= 1000000

The third line will be an integer m, the length of the useless word.

Then there is a line with a string T, which is the useless word T. |T| <= |S|

S and T will only contain lower case English letters.


Output:
Print a string in a single line. The result problem required.


Input Example:
1
29
yourshahawehaatwillhanotlieha
2
ha


Output Example:
yoursweatwillnotlie

***/



#include<bits/stdc++.h>

bool skip[1000010] = {false};
int count = 0;

int KMPSearch(std::string pat, std::string txt, int nt[])
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
        count++;
        skip[i-j] = true;
        j = 0;
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

  std::cin.tie(0);
  scanf("%d\n", &t_times);
  for (int i = 0; i < t_times; i++)
  {
    scanf("%d\n", &strLen);
    scanf("%s\n", str1);
    scanf("%d\n", &ptnLen);
    scanf("%s\n", pattern1);

    std::string str(str1), pattern(pattern1);

    int nt[ptnLen];

    computeNextArray(pattern, nt);
    int searched = KMPSearch(pattern, str, nt);

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
