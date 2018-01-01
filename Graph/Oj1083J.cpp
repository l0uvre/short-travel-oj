/***
Description:
SUSTech becomes bigger and bigger. The president wants to make the campus more convenient.

He decided to set n stations in the campus. The stations are built according the DSAA first law:  for i-th station, it serves as the original station for i-th bus line.  For each station, it serves as the destination station for only one bus line.  For each bus line,  the buses in it  go to the destination station directly. Please note that the original and destination station could be the same for some bus lines.

The convenience of the station build plan is measured by the DSAA second law: we use (x, y) to denote we can go from station x and arrive at station y, please note that (1) one passenger could take different bus lines to arrive y from x; (2) (x, y) and (y, x) are different, and (3) (x, x) is allowed.  The convenience of the total plan is defined as the total number of all possible (x, y) pairs among the n stations, the larger the better.

In order to improve the convenience, now we can change the destination of some bus lines according the DSAA third law: we can change at most two destinations of distinct bus lines.

Please find the maximum convenience value we can get by following the DSAA 1st, 2nd and 3rd laws. All stations are labeled from 1 to n.


Input:
The first line will be an integer T (1 <= T <= 50). T is the number of test cases.

For each test case, the first line will be an integer n. (1 <= n <= 100000), n is the number of stations.

Then there are n integers. Each integer is the destination of the ith bus line.


Output:
For each test case, print the maximum convenience value.

Input Example:
1
3
2 3 1

Output Example:
9

***/


//https://jzqt.github.io/2015/07/21/ACM%E5%9B%BE%E8%AE%BA%E4%B9%8B%E5%AD%98%E5%9B%BE%E6%96%B9%E5%BC%8F/

#include<bits/stdc++.h>

int cycles[100005];
int arrays[100005];
int visited[100005];
int nodes, cycle_len, cycle_index;
int DFS() {
  int next;
  cycle_index = 0;

  for(int i = 1; i <= nodes; i++) {
    if (!visited[i]) {
       visited[i] = 1;
    	 cycle_len = 1;
    	 next = arrays[i];
    	 while (!visited[next]) {
    	   cycle_len++;
    	   visited[next] = 1;
    	   next = arrays[next];
    	 }
    	 cycles[cycle_index] = cycle_len;
    	 cycle_index++;
    }
  }

}

int mycomp(const void* a, const void* b) {
  return (*(int*)b - *(int*)a);
}

int main() {
  int t_times;
  scanf("%d\n", &t_times);

  for (int i = 0; i < t_times; i++) {
    long long result = 0;
    scanf("%d\n", &nodes);
    memset(cycles, 0, sizeof(cycles));
    memset(arrays, 0, sizeof(arrays));
    memset(visited, 0, sizeof(visited));

    for (int j = 0; j < nodes; j++) {
      scanf("%d ", &arrays[j+1]);
    }

    DFS();

    if (cycle_index == 1) {
      result = cycles[0] * cycles[0];
    } else {
        qsort(cycles, cycle_index, sizeof(int), mycomp);
        result += (cycles[0] + cycles[1]) * (cycles[0] + cycles[1]);
        for (int j = 2; j < cycle_index; j++) {
        result += cycles[j] * cycles[j];
        }
    }
    printf("%lld\n", result);
  }
  return 0;
}
