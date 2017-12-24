/***
Description:
Emma has a tree of n nodes, each node has a value, now she wants to know the biggest sum of a path from the root to a leaf node.

Input:
The first line will be an integer T, which is the number of test cases. (1 <= T <= 10). For each test case, the first line will be an integer n(1 <= n <= 105), n is the number of nodes. The second line will be n integer, a1……an(1 <= ai <= 109), ai is the value of the i-th node. Then followed by n - 1 lines, each line will be two integers x and y, it means x is the father of y, we promise that these node are numbered from 1 to n and the input is a tree.


Output:
For each test output the biggest sum.

Input Example:
1
3
1 2 3
1 2
1 3

Output Example:
4

***/


#include <iostream>

typedef struct Node
{
  long long data;
  struct Node* child;
  struct Node* parent;
}
tNode;

tNode* newNode(long long data)
{
    tNode* node = new tNode;
    node->data = data;
    node->child = node->parent = NULL;
    return (node);
}

long long findSum(tNode* leaf) {
  long long sum = 0;
  tNode *temp = leaf;

  while (temp != NULL) {
    sum += temp->data;
    temp = temp->parent;
  }
  return sum;

}


int main() {

  int t_times;
  scanf("%d\n", &t_times);

  int fth, son;
  int node_num;
  long long node_v;

  long long result = 0;
  long long temp = 0;

  for (int i = 0; i < t_times; i++) {
    scanf("%d\n", &node_num);
    tNode* nodes[node_num+1];
    nodes[0] = newNode(0);

    for (int j = 1; j <= node_num; j++) {
      scanf("%lld", &node_v);
      nodes[j] = newNode(node_v);
    }

    for (int j = 0; j < node_num-1; j++) {
      scanf("%d %d", &fth, &son);
      nodes[son]->parent = nodes[fth];
      if (nodes[fth]->child == NULL) {
        nodes[fth]->child = nodes[son];
      }
    }

    tNode* leaf = NULL;

    for (int j = 1; j <= node_num; j++) {
      if (nodes[j]->child == NULL) {
        leaf = nodes[j];
        temp = findSum(leaf);
        if (result < temp) {
          result = temp;
        }
      }
    }

    printf("%lld\n", result);
    result = 0;

  }
  return 0;
}
