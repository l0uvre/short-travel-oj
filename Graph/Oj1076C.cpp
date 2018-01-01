/***
Description:
There are C kinds of colors and n * m grids. Each grid was paint by one color. Grid u at position (x, y) and grid v at position (a,b) are connected if and only if (1) they have the same color, (2) (|x-a| = 0 and |y-b|=0) or (|x-a| = 1 and |y-b|=0) or (|x-a|=0 and |y-b|=1). In a n * m grids, it contains several connected grids. Now give you n, m, C and the color of each grid. Please print the number of connected regions in it.

Input:
The first line will be an integer T. (1 <= T <= 50) T is the number of test case.

For each test case, the first line will be three integers n, m, C. (1 <= n, m, C <= 1000). All colors are labeled from 1 to C.

Then there will be n x m integers. The number in ith line and jth column means the color of the grid.



Output:
For each test case, print the number of connected block.

Input Example:
2
3 3 2
2 2 2
2 1 2
2 2 2
5 5 5
1 2 3 4 5
1 2 3 4 5
1 3 2 4 5
1 5 4 2 3
1 5 4 2 3

Output Example:
2
11

***/

#include<bits/stdc++.h>

int matrix[1005][1005];
bool visited[1005][1005];
int rows, columns;
int colors;

int isAvailable(int row, int col, int num)
{
    return (row >= 0) && (row < rows) && (col >= 0) && (col < columns) && (matrix[row][col] == num && !visited[row][col]);
}

void DFS(int row, int col, int num)
{
    static int rowNbr[] = {-1, 0, 0, 1};
    static int colNbr[] = {0, -1, 1, 0};

    visited[row][col] = true;

    for (int k = 0; k < 4; k++)
        if (isAvailable(row + rowNbr[k], col + colNbr[k], num))
            DFS(row + rowNbr[k], col + colNbr[k], num);
}

int main(int argc, char const *argv[]) {
  int t_times;
  scanf("%d\n", &t_times);

  for (int i = 0; i < t_times; i++) {
    int count = 0;
    scanf("%d %d %d\n", &rows, &columns, &colors);

    memset(visited, 0, sizeof(visited));
    memset(matrix, 0, sizeof(matrix));

    for (int j = 0; j < rows; j++) {
      for (int k = 0; k < columns; k++) {
        scanf("%d ", &matrix[j][k]);
      }
    }

  for (int l = 1; l <= colors; l++) {
    for (int j = 0; j < rows; j++) {
      for (int k = 0; k < columns; k++) {
          if (matrix[j][k] == l && !visited[j][k]) {
            DFS(j, k, l);
            count++;
          }
      }
    }
  }

  printf("%d\n", count);
  count = 0;

  }
  return 0;
}
