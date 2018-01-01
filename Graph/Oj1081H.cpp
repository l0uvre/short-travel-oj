/***
Description:
We have k integers from 1 to k. Now give you n sequences. The ith element of the sequence can change to the (i+1)th element (the last one cannot be changed). The element can change from one sequence to another sequence. There are q queries. Each query will give you an integer x. Please find the minimum change steps for changing x to itself.

Note: The change steps should be positive. If an integer cannot change to itself, print -1.

Input:
The first line will be an integer T. (1 <= T <= 50) T is the number of test cases.

For each test case, the first line will be three integers k, n and q. (1 <= k, n <= 200, q <= 10000)

Then there will be n lines. Each line begins with an integer t (1 <= t <= 200). t is the length of this sequence. Then t integers in the line is the elements in this sequence.

Then there is an integer q. q is the number of queries.

For each query, there will be an integer x.


Output:
For each query, print the step problem required.

Input Example:
1
7 3 5
4 1 3 5 7
3 2 4 6
5 7 5 4 3 1
1
2
3
4
5

Output Example:
2
-1
2
3
2

***/


#include <stdio.h>
#include <string.h>
#include <limits.h>

//floyd_Warshall algorithm

int matrix[205][205];
int node_num;

void initial() {
  for (int j = 0; j < 205; j++) {
    for (int k = 0; k < 205; k++) {
      matrix[j][k] = INT_MAX / 2;
    }
  }
}

void floyd_Warshall() {
  for (int k = 1; k <= node_num; k++) {
    for (int i = 1; i <= node_num; i++) {
      for (int j = 1; j <= node_num; j++) {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j]) {
          matrix[i][j] = matrix[i][k] + matrix[k][j];
        }
      }
    }
  }
}


int main(void) {
  int t_times;
  scanf("%d\n", &t_times);

  int seq_num, query_num;
  int seq_len, query;

  for (int i = 0; i < t_times; i++) {
    scanf("%d %d %d\n", &node_num, &seq_num, &query_num);

    initial();

    for (int j = 0; j < seq_num; j++) {
      scanf("%d ", &seq_len);
      int nums[seq_len];
      for (int k = 0; k < seq_len; k++) {
        scanf("%d ", &nums[k]);
      }

      for (int k = 0; k < seq_len - 1; k++) {
        matrix[nums[k]][nums[k+1]] = 1;
      }
    }

    floyd_Warshall();

    for (int j = 0; j < query_num; j++) {
      scanf("%d\n", &query);
      if (matrix[query][query] == INT_MAX / 2) {
        printf("-1\n");
      }
      else {
        printf("%d\n", matrix[query][query]);
      }
    }
  }
  return 0;
}
