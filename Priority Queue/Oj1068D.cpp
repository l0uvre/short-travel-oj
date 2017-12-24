/***
Description:
Cathy have some questions, and she doesn’t know how to do it, she asks you to help her, because she knows that you are clever enough. You have learned complete binary tree in the class, now, it comes to complete k-ary tree. You’re given two integer n and k, and you are asked to print the path from the root to the n-th node in complete k-ary tree from the root to leaf.

Input:
The first line will be an integer T, which is the number of test cases. (1 <= T <= 105). For each test case, the first line will be two integer n(1 <= n <= 1018) and k(1 <= k <= 1018).


Output:
For each test output the path from root to the n-th node. There is a space between two values, and there is no space in the end of a line.

Input Example:
3
8 2
7 3
15 4


Output Example:
1 2 4 8
1 2 7
1 4 15

***/


#include<bits/stdc++.h>

int main() {

  int t_times;
  scanf("%d\n", &t_times);

  long long k_ary, node_n;

  for (int i = 0; i < t_times; i++) {
    std::vector<long long> v;
    scanf("%lld %lld\n", &node_n, &k_ary);


    while (node_n != 1) {
      v.push_back(node_n);
      node_n = (node_n - 2) / k_ary + 1;
    }

    v.push_back(1);

    for (long long j = v.size()-1; j >=0 ; j--) {
      if (j != 0) {
        printf("%lld ", v[j]);
      }
      else {
        printf("%lld\n", v[j]);
      }
    }

  }
  return 0;
}
