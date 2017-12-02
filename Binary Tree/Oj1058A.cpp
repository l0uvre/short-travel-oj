#include<bits/stdc++.h>
using namespace std;

/***
Description:
Give you the number of nodes of a complete binary tree T. Please calculate the height of T.

Input:
First line is an integer T, which is the number of test cases. (1 <= T <= 1024)

For each test case, there will be an integer in a single line N (1 <= N <= 1024). N is the number of nodes in the Tree.


Output:
Print the height of the tree for each test case.


Input Example:
2
3
5


Output Example:
1
2

***/


int main(int argc, char const *argv[]) {

  int t_times;
  scanf("%d\n", &t_times);
  int node_num;

  for (int i = 0; i < t_times; i++) {
    scanf("%d\n", &node_num);
    printf("%d\n", (int)log2((float)node_num));
  }
  return 0;
}
