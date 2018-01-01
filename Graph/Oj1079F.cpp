/***
Description:
In SUSTech, if you want to select a course, you have to learn the prerequisite course first. As you know, Itakejgo wants to be a student in Department of CSE. He has to learn n course. The prerequisite information is given. Please find a way to select course. If there are multiply ways, print the one with minimum alphabet order. Besides, the information may be wrong. If you cannot find such way to select course, print “impossible” (without quotes). The courses are labeled from 1 to n.

Note: the input guarantee that no course required the same course twice.

Input:
The first line will be an integer T. (1 <= T <= 500) T is the number of test cases.

For each test cast, the first line will two integers n and m. (1 <= n <= 5000, 1 <= m <= 20000).

Then there will be m lines. Each line will contain two integers x y. Means x is the prerequisite course of y. ( you have to learn y before x)


Output:
For each test case, print a way to choose course. If there are more than one ways, print the one with minimum alphabet order.

Input Example:
3
8 6
1 2
1 3
1 4
5 6
6 7
8 7
4 3
1 2
3 2
2 4
3 3
1 2
2 3
3 1


Output Example:
1 2 3 4 5 6 8 7
1 3 2 4
impossible
***/


#include<bits/stdc++.h>
using namespace std;


int edgeCount, head[5005];
int ans[5005], in[5005];
priority_queue<int> Q;

struct Edge
{
  int v, next;
} Edges[20005];


void AddEdge(int u, int v)
{
    Edges[++edgeCount].v = v;
    Edges[edgeCount].next = head[u];
    head[u] = edgeCount;
    in[v]++;
}

int toposort(int n) {
    while (!Q.empty()) {
      Q.pop();
    }
    for (int i = 1; i <= n; i++) {
      if (in[i] == 0) {
        Q.push(i);
      }
    }
    int total = 0;
    while (!Q.empty())
    {
        int u = Q.top();
        Q.pop();
        ans[total++] = u;
        //total++;
        for (int i = head[u]; i; i = Edges[i].next)
        {
            if (in[Edges[i].v] > 0)
            {
                in[Edges[i].v]--;
                if (in[Edges[i].v] == 0) {
                  Q.push(Edges[i].v);
                }
            }
        }
    }
    return total;
}

int main()
{
    int t_times;
    int nodes, edges;
    int vertex1, vertex2;
    scanf("%d\n", &t_times);
    for (int i = 0; i < t_times; i++) {
      scanf("%d %d\n", &nodes, &edges);
      memset(head, 0, sizeof(head));
      memset(in, 0, sizeof(in));
      edgeCount = 1;

      for (int j = 0; j < edges; j++) {
        scanf("%d %d\n", &vertex1, &vertex2);
        AddEdge(vertex2, vertex1);
      }

      int count = toposort(nodes);
      if (count == nodes) {
        for (int j = count - 1; j >= 0; j--)
        {
            printf("%d ", ans[j]);
        }
        printf("\n");
      } else {
        printf("impossible\n");
      }

    }


    return 0;
}
