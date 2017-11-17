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
