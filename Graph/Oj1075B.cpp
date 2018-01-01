/***
Description:
In a graph G, if we can find a path from node x to node y. We say x can reach y. Now give you a directed graph G with n nodes and m edges. There are Q queries. Each query will contain two integers x y. If x can reach y, print YES. Otherwise, print NO.

Note: We guarantee there is at most one edge from node i to node j.

Input:
The first line will be an integer T (1 <= T <= 50). T is the number of test case.

For each test case, the first line will be two integers n and m. (1 <= n <= 1000, 0 <= m <= min(n * n, 100000))

Then there will be m lines. Each line will have two integers x y. x y means there is an edge from x to y.

After that, there is an integer Q. (1 <= Q <= 500) Then, there will be Q lines. Each line will have two integers x y.

All nodes are labeled from 1 to n.



Output:
For each query, if x can reach y, print YES. Otherwise, print NO.

Input Example:
1
7 7
1 6
6 4
4 3
3 5
5 1
2 7
7 2
6
1 2
2 7
7 2
3 6
4 6
5 4


Output Example:
NO
YES
YES
YES
YES
YES

***/

#include<bits/stdc++.h>

//BFS or DFS
class Graph {
  int V;
  std::list<int> *adj;

public:
  Graph(int V);
  void addEdge(int v, int w);
  bool isReachable(int v, int w);
};

Graph::Graph(int V) {
  this->V = V;
  adj = new std::list<int>[V];
}

void Graph::addEdge(int v, int w) {
  adj[v].push_back(w);
}

bool Graph::isReachable(int v, int w) {
  if (v == w) {
    return true;
  }

  bool* visited = new bool[V];
  for (int i = 0; i < V; i++) {
    visited[i] = false;
  }

  std::list<int> q; //queue for the BFS;

  visited[v] = true;
  q.push_back(v);

  std::list<int>::iterator i;

  while (!q.empty()) {
    v = q.front();
    q.pop_front();

    for (i = adj[v].begin(); i != adj[v].end(); i++){
      if (*i == w)
          return true;
      if (!visited[*i]) {
          visited[*i] = true;
          q.push_back(*i);
      }
    }
  }

  return false;
}


int main(int argc, char const *argv[]) {

  int t_times;
  scanf("%d\n", &t_times);

  int nodes, edges;
  int vertex1, vertex2;

  int queries;

  for (int i = 0; i < t_times; i++) {
    scanf("%d %d\n", &nodes, &edges);

    Graph gph(nodes+1);

    for (int j = 0; j < edges; j++) {
      scanf("%d %d\n", &vertex1, &vertex2);
      gph.addEdge(vertex1, vertex2);
    }

    scanf("%d\n", &queries);

    for (int j = 0; j < queries; j++) {
      scanf("%d %d\n", &vertex1, &vertex2);
      if (gph.isReachable(vertex1, vertex2)) {
        printf("YES\n");
      } else {
        printf("NO\n");
      }
    }
  }
  return 0;
}
