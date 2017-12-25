/***
Description:
There are a lot of sequences, and each sequence can represent a binary search, please judge whether two sequences can form the same binary search tree.
The first value is the root of the tree, and then you can add the value into the tree following the rules of binary search tree.

Input:
The first line will be an integer T, which is the number of test cases. (1 <= T <= 100). For each test case, the first line will be two integers n(1 <= n <= 100) and m(1 <= m <= 63), n is the number of judgement, m is the length of the sequences. The second line will be m integer, a1……am(1 <= ai <= 109), it is the standard sequences. Then followed by n lines, each line will be another arrangement of the standard sequences.

Output:
For each judgement, print YES when a arrangement of the standard sequences can form the same binary search tree with the standard sequences, else print NO.

Input Example:
1
2 6
5 6 7 4 3 2
5 4 3 2 6 7
5 7 6 3 4 2

Output Example:
YES
NO

***/



#include<bits/stdc++.h>

//http://www.geeksforgeeks.org/check-for-identical-bsts-without-building-the-trees/

bool isSameBST(int a[], int b[], int array_len, int index1, int index2, int min, int max);


int main(int argc, char const *argv[]) {
  int t_times;
  scanf("%d\n", &t_times);

  int judge_times, tree_len;

  for (int i = 0; i < t_times; i++) {
    scanf("%d %d\n", &judge_times, &tree_len);

    int origin_tree[tree_len];

    for (int j = 0; j < tree_len; j++) {
      scanf("%d ", &origin_tree[j]);
    }


    for (int j = 0; j < judge_times; j++) {
      int judge_tree[tree_len];

      for (int k = 0; k < tree_len; k++) {
        scanf("%d ", &judge_tree[k]);
      }

      if (isSameBST(origin_tree, judge_tree, tree_len, 0, 0, INT_MIN, INT_MAX)) {
        printf("YES\n");
      } else {
        printf("NO\n");
      }
    }
  }
  return 0;
}


bool isSameBST(int a[], int b[], int array_len, int index1, int index2, int min, int max) {
  int i;
  int j;

  for (i = index1; i < array_len; i++) {
    if (a[i] > min && a[i] < max) {
      break;
    }
  }

  for (j = index2; j < array_len; j++) {
    if (b[j] > min && b[j] < max) {
      break;
    }
  }

  if (i == array_len && j == array_len) {
    return true;
  }

  if (((i==array_len)^(j==array_len)) || a[i] != b[j]) {
    return false;
  }

  return isSameBST(a, b, array_len, i + 1, j + 1, a[i], max) && isSameBST(a, b, array_len, i + 1, j + 1, min, a[i]);
}
