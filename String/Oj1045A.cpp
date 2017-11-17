#include<bits/stdc++.h>
using namespace std;

int main() {

  int t_times;
  string str_read;

  scanf("%d\n", &t_times);

  for (int i = 0; i < t_times; i++) {
    std::cin >> str_read;
    int allLen = str_read.length();
    int result = (1 + allLen) * allLen / 2;
    printf("%d\n", result);
  }
  return 0;
}
