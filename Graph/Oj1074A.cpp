/***
Description:
Give you a directed graph G with n nodes and m edges. Please print the adjacency matrix A of G. Hints: adjacency matrix is a way to represent a graph. Suppose we have a directed graph G, if there is an edge from node i to node j in G, we have A[i][j] = 1 in G’s corresponding adjacency matrix A, otherwise, A[i][j] = 0.

Input:
The first line will be an integer T (1 <= T <= 50). T is the number of test case.

For each test case, the first line will be two integers n and m. ( 1 <= n <= 500, 0 <= m <= n*n)

Then there will be m lines. Each line will have two integers x y. x y means there is an edge from x to y. All nodes are labeled from 1 to n.


Output:
For each test case, print the adjacency matrix.

Input Example:
2
3 5
1 2
2 1
1 3
3 2
2 3
1 0

Output Example:
0 1 1
1 0 1
0 1 0
0

***/

#include<bits/stdc++.h>

int main(int argc, char const *argv[]) {

  int t_times;
  scanf("%d\n", &t_times);

  int nodes, edges;
  int vertex1, vertex2;

  for (int i = 0; i < t_times; i++) {
    scanf("%d %d\n", &nodes, &edges);

    int adj_matrix[nodes][nodes];

    for (int j = 0; j < nodes; j++) {
      for (int k = 0; k < nodes; k++) {
        adj_matrix[j][k] = 0;
      }
    }

    for (int j = 0; j < edges; j++) {
      scanf("%d %d\n", &vertex1, &vertex2);
      adj_matrix[vertex1-1][vertex2-1] = 1;
    }

    for (int j = 0; j < nodes; j++) {
      for (int k = 0; k < nodes; k++) {
        printf("%d ", adj_matrix[j][k]);
      }
      printf("\n");
    }
  }
  return 0;
}
