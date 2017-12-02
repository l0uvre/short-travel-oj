/***
Description:
Give you a binary tree T. Please print the level traversal of T.


Input:
First line is an integer T, which is the number of test cases. (1 <= T <= 50)

For each test case, there will be an integer in a single line N (1 <= N <= 1024). N is the number of nodes. The nodes are numbered from 1 to N.

Then there will be N – 1 lines with two integer x, y for each line. (1 <= x, y <= N)

x y means x is the farther of y. What’s more, we guarantee the input file is a tree. And the child appears first is the left child, the other one appears later is right child.



Output:
For each test case, print the level traversal of the tree in a single line.



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
1 4 3 2 5 6 7 8

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


void printLevelOrder(Node *root)
{

    if (root) {
      queue<tNode*> q;
      q.push(root);

      while (q.empty() == false)
      {
          Node *node = q.front();
          cout << node->data << " ";
          q.pop();

          if (node->left != NULL){
            q.push(node->left);
          }


          if (node->right != NULL){
            q.push(node->right);
          }

      }
    }


}




int main() {

  int t_times;
  scanf("%d\n", &t_times);

  int fth, son;

  for (int i = 0; i < t_times; i++) {
    int node_num;
    scanf("%d\n", &node_num);

    tNode* nodes[node_num+1];



    for (int j = 0; j <= node_num; j++) {
      nodes[j] = newNode(j);
    }

    //std::map<int, tNode*> nodes;

    for (int j = 0; j < node_num-1; j++) {
      scanf("%d %d", &fth, &son);
      nodes[son]->parent = nodes[fth];
      if (nodes[fth]->left == NULL) {
        nodes[fth]->left = nodes[son];
      } else if(nodes[fth]->right == NULL)
      {
        nodes[fth]->right = nodes[son];
      }
    }

    tNode* head = NULL;

    for (int j = 1; j <= node_num; j++) {
      if (nodes[j]->parent == NULL) {
        head = nodes[j];
        break;
      }
    }

    printLevelOrder(head);
    printf("\n");


  }
  return 0;
}
