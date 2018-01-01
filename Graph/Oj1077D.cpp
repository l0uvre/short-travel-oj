/***
Description:
There are n buildings in SUSTech. The president wants to make all these buildings are connected by making some bridges among them. Huang Bo made m bridges (with cost) in these buildings. However, he has to go to Shanghai for ACM EC final contest in next week, so he asks you help him to finish this task with the left K available bridges (with cost).

Huang Bo is not always smart than you, so you can remove some of bridges in his work, and insert some of bridges in the K available bridges to make (1) all buildings are connected, (ii) the total cost is minimized. If you cannot make all buildings are connected by these m+K bridges, print -1, otherwise, print the minimized total cost.

Note: The total cost is the cost of the remaining bridges after you remove and insert.


Input:
The first line will be an integer T. (1 <= T <= 50) T is the number of test case.

For each test case, the first line will be three integers n, m and K.(n <= 5000, m, K <= 10000) Then there will be m + K lines. Each line will be three integers x y w. Means we can build a bridge between island x and island y. The cost is w. (1 <= x, y <= n, w <= 104)

The islands are labeled from 1 to n.



Output:
For each test cast, print the minimum cost or -1.

Input Example:
1
5 5 2
1 2 1
1 3 6
3 4 1
1 4 5
2 4 4
2 5 3
4 5 2


Output Example:
7

***/


// Minimum spanning tree Kruskal's algorithm

//http://www.geeksforgeeks.org/greedy-algorithms-set-2-kruskals-minimum-spanning-tree-mst/
#include<bits/stdc++.h>

struct Edge
{
    int src, dest, weight;
};

struct unionset {
  int parent;
  int rank;
};

struct Graph {
  int V, E;
  struct Edge* edge;
};

struct Graph* createGraph(int V, int E) {
  struct Graph* graph = new Graph;
  graph->V = V;
  graph->E = E;

  graph->edge = new Edge[E];

  return graph;
}

int find(struct unionset unionsets[], int i)
{
    if (unionsets[i].parent != i) {
      unionsets[i].parent = find(unionsets, unionsets[i].parent);
    }
    return unionsets[i].parent;
}

void Union(struct unionset unionsets[], int x, int y)
{
    int xroot = find(unionsets, x);
    int yroot = find(unionsets, y);

    if (unionsets[xroot].rank < unionsets[yroot].rank)
        unionsets[xroot].parent = yroot;
    else if (unionsets[xroot].rank > unionsets[yroot].rank)
        unionsets[yroot].parent = xroot;
    else
    {
        unionsets[yroot].parent = xroot;
        unionsets[xroot].rank++;
    }
}

int comp(const void* a, const void* b)
{
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}

int KruskalMST(struct Graph* graph)
{
    int V = graph->V;
    int weights = 0;
    int e = 0;
    int i = 0;

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), comp);

    struct unionset *unionsets = (struct unionset*) malloc((V+1) * sizeof(struct unionset));

    for (int v = 0; v <= V; v++)
    {
        unionsets[v].parent = v;
        unionsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph->E)
    {
        struct Edge next_edge = graph->edge[i++];

        int x = find(unionsets, next_edge.src);
        int y = find(unionsets, next_edge.dest);

        if (x != y)
        {
            weights += next_edge.weight;
            e++;
            Union(unionsets, x, y);
        }
    }

    if (e == V-1) {
      return weights;
    } else {
      return -1;
    }

}

int main() {
  int t_times;
  scanf("%d\n", &t_times);

  int nodes, edges1, edges2, edges;
  int vertex1, vertex2;
  int weight;

  for (int i = 0; i < t_times; i++) {
    scanf("%d %d %d\n", &nodes, &edges1, &edges2);
    edges = edges1 + edges2;

    struct Graph* graph = createGraph(nodes, edges);

    for (int j = 0; j < edges; j++) {
      scanf("%d %d %d\n", &graph->edge[j].src, &graph->edge[j].dest, &graph->edge[j].weight);
    }

    printf("%d\n", KruskalMST(graph));

  }
  return 0;
}
