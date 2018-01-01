#include<bits/stdc++.h>

int visited[205];
int level[205]; //对应visited 数组，当DFS搜索到节点两次时，存下的即环的长度
int node_num;

class Graph {
  int V;
  std::list<int> *adj;

public:
  Graph(int V);
  void addEdge(int v, int w);
  void cycleLen(int v);
};

Graph::Graph(int V) {
  this->V = V;
  adj = new std::list<int>[V];
}

void Graph::addEdge(int v, int w) {
  adj[v].push_back(w);
}

void Graph::cycleLen(int v) {
  memset(visited, 0, sizeof(visited));
  memset(level, 0, sizeof(level));

  std::list<int> q; //queue for the BFS;
  int times = 0;
  int cycle_len;
  int u;

  visited[v] = 1;
  times++;
  q.push_back(v);

  std::list<int>::iterator i;

  while (!q.empty()) {
    u = q.front();
    q.pop_front();

    for (i = adj[u].begin(); i != adj[u].end(); i++) {
      if ((*i) == v) {
        times++;
        if (i != adj[u].begin()) {
          i--;
          cycle_len = level[*i];
        } else {
          cycle_len = level[u] + 1;
        }
        break;
      }
      if (!visited[*i]) {
          visited[*i] = 1;
          level[*i] = level[u] + 1;
          q.push_back(*i);
      }
    }

    if (times == 2) {
      break;
    }
  }

  if (times == 1) {
    printf("-1\n");
  } else {
    printf("%d\n", cycle_len);
  }

}

int main() {
  int t_times;
  scanf("%d\n", &t_times);

  int seq_num, query_num;
  int seq_len, query;

  for (int i = 0; i < t_times; i++) {
    scanf("%d %d %d\n", &node_num, &seq_num, &query_num);

    Graph gph(node_num + 1);

    for (int j = 0; j < seq_num; j++) {
      scanf("%d ", &seq_len);
      int nums[seq_len];
      for (int k = 0; k < seq_len; k++) {
        scanf("%d ", &nums[k]);
      }

      for (int k = 0; k < seq_len - 1; k++) {
        gph.addEdge(nums[k], nums[k + 1]);
      }
    }

    for (int j = 0; j < query_num; j++) {
      scanf("%d\n", &query);
      gph.cycleLen(query);
    }
  }
  return 0;
}
