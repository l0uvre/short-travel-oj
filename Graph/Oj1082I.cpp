/***
Description:
Alice and Bob broke up finally. There are n cities, there is either a road or a railway between every two cities. There is a railway between two cities if and only if there are no road between these cities. Each road and railway will cost 1 time unit. Now Alice and Bob are in the city 1. They want to arrive at the city n. But they do not want to arrive at any cities at the same time (except city 1 and city n). And they also do not want to take the same vehicle. Alice will take the bus and Bob will take the train. Could you find the minimum time that Alice and Bob both arrive at the city n? If some of them can not arrive at n or they have to meet some cities at the same time, print -1.

All cities are labeled from 1 to n.

Note: There are no multiple roads or railways between two cities.

Input:
The first line will be an integer T. (1 <= T <= 50) T is the number of test case.

For each test case, the first line will be two integers n and m. (1 <= n <= 1000, 0 <= m <= n(n-1)/2)

n is the number of cities and m is the number of roads.

Then there will be m lines. Each line will contain two integers x y. Means there is a road between x and y.

Output:
For each test cast, print the minimum time or -1.

Input Example:
2
4 2
1 3
3 4
4 6
1 2
1 3
1 4
2 3
2 4
3 4

Output Example:
2
-1

***/


#include<bits/stdc++.h>

#define MAX_NODE 4005

int graph[MAX_NODE][MAX_NODE];
int distance[MAX_NODE];
int node_num, road_num;
bool isRoad;

void BFS(){
  std::queue<int> q;

  q.push(1);
  distance[1] = 0;

  int u, v;
  while (!q.empty()) {
    u = q.front();
    q.pop();
    for (v = 1; v <= node_num; v++) {
      if (isRoad && !graph[u][v]) {
        if (distance[v]==INT_MAX) {
            distance[v] = distance[u] + 1;
            q.push(v);
        }
      }
      else if (!isRoad && graph[u][v]) {
        if (distance[v]==INT_MAX) {
            distance[v] = distance[u] + 1;
            q.push(v);
        }
      }
    }
  }
}

int main() {
  int t_times;
  int vertex1, vertex2;
  scanf("%d\n", &t_times);

  for (int i = 0; i < t_times; i++) {
    scanf("%d %d", &node_num, &road_num);

    memset(graph, 0, sizeof(graph));

    for (int j = 1; j <= node_num; j++) {
      distance[j] = INT_MAX;
    }

    isRoad = false;

    for (int j = 0; j < road_num; j++) {
      scanf("%d %d\n", &vertex1, &vertex2);
      graph[vertex1][vertex2] = 1;
      graph[vertex2][vertex1] = 1;

      if ((vertex1 == 1 && vertex2 == node_num) || (vertex2 == 1 && vertex1 == node_num)) {
        isRoad = true;
      }
    }

    BFS();

    if (distance[node_num]==INT_MAX) {
      printf("-1\n");
    } else {
      printf("%d\n", distance[node_num]);
    }

  }
  return 0;
}
