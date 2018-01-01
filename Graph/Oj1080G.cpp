/***
Description:
Bob find a girlfriend yesterday. Her name is Alice. Today, Bob wants to have a date with Alice. But they are in different cities. There are n cities and m roads. Each road is bidirectional. Go through each road will cost some time. Bob wants to meet Alice at one of the cities as fast as possible. Could you help him to find the minimum time cost?

All cities are labeled from 1 to n.

Note: There may be multiple roads between some cities. Alice can also move.

Input:
The first line will be an integer T. (1 <= T <= 50) T is the number of test cases.

For each test case, the first line will be two integers n and m. (1 <= n <= 6000, 1 <= m <= 100000)

Then there will be m lines. Each line will contain three integers u, v, w. Means there is a road between city u and city v. And the time cost it w.  (1 <= u, v <= n, u!=v, 1 <= w <= 105)

The last line of each test case is two integer s and t. (1 <= s, t <= n). Means the location of Bob and Alice.

The input guarantee Bob can always meet Alice.

Output:
For each test case, print the minimum time cost.

Input Example:
2
4 3
1 2 3
3 2 1
2 4 4
1 4
8 7
1 2 1
1 3 7
1 4 6
4 6 2
6 5 4
6 7 3
7 8 5
4 7

Output Example:
4
3

***/

#include<bits/stdc++.h>

///dijkstra algorithm

#define MAX_NODE 6005
#define MAX_EDGE 100005

int node_num, edge_num, edgeCount, source, dest;
int head[MAX_NODE];
int distance[MAX_NODE][2];
bool visited[MAX_NODE];

struct Edge{
   int to; // the node that the current points to.
   int weight;
   int next; // the index for the next edge
};

Edge edges[MAX_EDGE];


int Max(int x, int y) {
  if (x > y) {
    return x;
  } else {
    return y;
  }
}

int Min(int x, int y) {
  if (x < y) {
    return x;
  } else {
    return y;
  }
}
void add_edge(int u, int v, int weight) {
     edges[edgeCount].to = v;
     edges[edgeCount].weight = weight;
     edges[edgeCount].next = head[u];
     head[u] = edgeCount;
     edgeCount++;
}

struct Point{
   int d, u;
   bool operator < (const Point &A) const {
       return d > A.d;
   }
};

void dijkstra(int s, int direction) {

  memset(visited, 0, sizeof(visited));

  for (int i = 0; i <= node_num; i++) {
    distance[i][direction] = INT_MAX;
  }
  distance[s][direction] = 0;

  std::priority_queue<Point> q;
  q.push((Point){0, s});

  Point x;
  int u,v;
  while (!q.empty()) {
    x = q.top();
    q.pop();
    u = x.u; // vertex

    if (!visited[u]) {
      visited[u] = true;
      for (int i = head[u]; i != -1; i = edges[i].next) {
        v = edges[i].to;
        if (distance[v][direction] > distance[u][direction] + edges[i].weight) {
            distance[v][direction] = distance[u][direction] + edges[i].weight;
            q.push((Point){distance[v][direction], v});
        }
      }
    }

  }

}

int main() {
  int t_times;
  int result, helper;
  int vertex1, vertex2, weight;

  scanf("%d\n", &t_times);

  for (int i = 0; i < t_times; i++) {
    edgeCount = 0;
    memset(head, -1, sizeof(head));
    scanf("%d %d\n", &node_num, &edge_num);
    int vertex1, vertex2,val;
    for (int i = 0; i < edge_num; i++) {
        scanf("%d %d %d",&vertex1, &vertex2, &weight);
        add_edge(vertex1, vertex2, weight);
        add_edge(vertex2, vertex1, weight);
    }
    scanf("%d %d\n", &source, &dest);
    //printf("%d %d\n", source, dest);

    dijkstra(source, 0);
    dijkstra(dest, 1);
    result = INT_MAX;
    for (int j = 1; j <= node_num; j++) {
      helper = Max(distance[j][0], distance[j][1]);
      result = Min(result, helper);
    }
    printf("%d\n", result);

  }
  return 0;
}
