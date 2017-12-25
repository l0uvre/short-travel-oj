/***
Description:
Please judge whether a tree is a binary search tree or not.

Input:
The first line will be an integer T, which is the number of test cases. (1 <= T <= 10). For each test case, the first line will be an integer n(1 <= n <= 105). The second line will be n integers, a1……an(1 <= ai <= 109), ai represents the value of the i-th node, then followed by n - 1 lines, each line will be two integers x and y, x is the father of y.


Output:
For each test, print the number of the test cases first, then print YES when the tree is a binary search tree, else print NO.

We guarantee that (1 <= x, y <= n) and input is a tree.


Input Example:
1
3
1 2 3
2 1
2 3

Output Example:
Case #1: YES

***/


#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
  int data;
  struct Node* left;
  struct Node* right;
  struct Node* parent;
}
tNode;

tNode* newNode(int data)
{
    tNode* node = new tNode;
    node->data = data;
    node->left = node->right = NULL;
    node->parent = NULL;
    return (node);
}

int isBST(tNode* root, int min, int max)
{
  if (root==NULL) {
    return 1;
  }

  if (root->data < min || root->data > max){
    return 0;
  }

  return isBST(root->left, min, (root->data)-1) && isBST(root->right, (root->data)+1, max);
}

int main() {

  int t_times;
  scanf("%d\n", &t_times);

  int fth, son;
  int node_num;
  long long node_v;


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

      if ( (nodes[son]->data > nodes[fth]->data) && nodes[fth]->right == NULL) {
        nodes[fth]->right = nodes[son];
      } else if ((nodes[son]->data < nodes[fth]->data) && nodes[fth]->left == NULL ) {
        nodes[fth]->left = nodes[son];
      } else if (nodes[fth]->left == NULL) {
        nodes[fth]->left = nodes[son];
      } else if (nodes[fth]->right == NULL) {
        nodes[fth]->right = nodes[son];
      }
    }
    tNode* root = NULL;
    for (int j = 1; j <= node_num; j++) {
      if (nodes[j]->parent == NULL) {
        root = nodes[j];
      }
    }

    if (isBST(root, INT_MIN, INT_MAX)) {
      printf("Case #%d: YES\n", i + 1);
    } else {
      printf("Case #%d: NO\n", i + 1);
    }

  }
  return 0;
}
