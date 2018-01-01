/***
Description:
Students can be divided into two groups in CS203. One is “Xueba”, the other is “Xuezha”. In CS203 course, there are n students. Each student is either in “Xueba” group or “Xuezha” group. In this course, the students in the same group will never fight as they have the same interests. Now Dr. Tang has a group of fight log. Each record in the log has two integers x y, it means student x fight with student y. Please verify whether the group of record is legal. All students are labeled from 1 to n.

A group of record is legal if and only if no student is both in “Xueba” and “Xuezha” group.


Input:
The first line will be an integer T. (1 <= T <= 50) T is the number of test cases.

For each test case, the first line will be two integers n and m. ( 2 <= n <= 5000, 1 <= m <= 20000)

n is the number of students. And m is the number of log records.

Then there will be m lines. Each line will be a record: x y, it means student x fight with student y.


Output:
For each test case, print “legal” (without quotes) or “illegal”(without quotes)

Input Example:
2
7 4
1 2
2 3
3 4
4 5
3 3
1 2
2 3
3 1


Output Example:
legal
illegal
***/

// undirected graph
#include<bits/stdc++.h>

int colors[5002];
int color;

class Graph {
  int V;
  std::list<int> *adj;

public:
  Graph(int V);
  void addEdge(int v, int w);
  bool isllegal(int v);
};

Graph::Graph(int V) {
  this->V = V;
  adj = new std::list<int>[V];
}

void Graph::addEdge(int v, int w) {
  adj[v].push_back(w);
}

bool Graph::isllegal(int v) {

  std::list<int> q;//queue for BST

  if (colors[v] == 0) {
    colors[v] = color;
  }

  q.push_back(v);

  std::list<int>::iterator i;

  while (!q.empty()) {
    v = q.front();
    q.pop_front();

    for (i = adj[v].begin(); i != adj[v].end(); i++){
      if (colors[*i]==0) {
          colors[*i] = -colors[v];
          q.push_back(*i);
      }

      if (colors[*i]==colors[v]) {
          return false;
      }
    }
  }

  return true;
}


int main(int argc, char const *argv[]) {

  int t_times;
  scanf("%d\n", &t_times);

  int nodes, edges;
  int vertex1, vertex2;

  for (int i = 0; i < t_times; i++) {
    scanf("%d %d\n", &nodes, &edges);
    int k;

    Graph gph(nodes+1);
    memset(colors, 0, sizeof(colors));
    color = 1;

    for (int j = 0; j < edges; j++) {
      scanf("%d %d\n", &vertex1, &vertex2);
      gph.addEdge(vertex1, vertex2);
      gph.addEdge(vertex2, vertex1);
    }

    for (k = 1; k <= nodes; k++) {
      if (gph.isllegal(k)) {
        color = -color;
        continue;
      } else {
        printf("illegal\n");
        break;
      }
    }

    if (k == nodes+1) {
      printf("legal\n");
    }

  }
  return 0;
}
