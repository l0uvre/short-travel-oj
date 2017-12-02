/***
Description:
Give you a binary tree T. Please print the:

pre/ in/ post order Traversal of the tree.


Input:
First line is an integer T, which is the number of test cases. (1 <= T <= 50)

For each test case, there will be an integer in a single line N (1 <= N <= 1024). N is the number of nodes. The nodes are numbered from 1 to N.

Then there will be N – 1 lines with two integer x, y for each line. (1 <= x, y <= N)

x y means x is the farther of y. What’s more, we guarantee the input file is a tree. And the child appears first is the left child, the other one appears later is right child.


Output:
For each test case, you should print three lines:

The 1st/2nd/3rd line is the pre/in/post order traversal of the Tree.



Input Example:
1
8
1 4
1 3
4 2
2 7
3 5
3 6
6 8


Output Example:
1 4 2 7 3 5 6 8
7 2 4 1 5 3 8 6
7 2 4 5 8 6 3 1

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

void printPre(tNode* root) {
  if (root) {
    printf("%d ", root->data);

    if (root->left != NULL) {
      printPre(root->left);
    }

    if (root->right != NULL) {
      printPre(root->right);
    }
  }

}


void printIn(tNode* root) {
  if (root) {

    if (root->left != NULL) {
      printIn(root->left);
    }

    printf("%d ", root->data);

    if (root->right != NULL) {
      printIn(root->right);
    }
  }

}

void printPo(tNode* root) {
  if (root) {
    if (root->left != NULL) {
      printPo(root->left);
    }

    if (root->right != NULL) {
      printPo(root->right);
    }

    printf("%d ", root->data);

  }

}


int main() {

  int t_times;
  scanf("%d\n", &t_times);

  for (int i = 0; i < t_times; i++) {
    int node_num;
    scanf("%d\n", &node_num);

    int nums[node_num-1][2];

    for (int j = 0; j < node_num-1; j++) {
      scanf("%d %d\n", &nums[j][0], &nums[j][1]);
    }

    /**for (int j = 0; j < node_num-1; j++) {
      printf("%d %d\n", nums[j][0], nums[j][1]);
    }**/

    std::map<int, tNode*> nodes;

    for (int j = 0; j < node_num-1; j++) {
      if (nodes.find(nums[j][0]) == nodes.end()) {
        nodes.insert(std::pair<int, tNode*>(nums[j][0], newNode(nums[j][0])));
      }

      if (nodes.find(nums[j][1]) == nodes.end()) {
        nodes.insert(std::pair<int, tNode*>(nums[j][1], newNode(nums[j][1])));
      }

      tNode* node1 = nodes[nums[j][0]];
      tNode* node2 = nodes[nums[j][1]];

      node2->parent = node1;

      if (node1->left == NULL) {
        node1->left = node2;
      } else if (node1->right == NULL)
      {
        node1->right = node2;
      }

    }

    tNode* head = NULL;

    for (int j = 1; j <= node_num; j++) {
      //printf("%d ", nodes[j]->data);
      if (nodes[j]->parent == NULL) {
        head = nodes[j];
        break;
      }
    }

    printPre(head);
    printf("\n");

    printIn(head);
    printf("\n");

    printPo(head);
    printf("\n");

  }
  return 0;
}
