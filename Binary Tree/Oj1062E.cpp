/***
Description:
There are N cities in a country. The roads between the cities form a binary Tree with the cities. Two tourists A and B start at the same city (which can be any city). They want to arrive at two cities such that the distance of the cities is as large as possible. Please find the distance.

Note that all the length of the road is always 1. And when you calculate the distance, one road can be calculated at most once.


Input:
First line is an integer T, which is the number of test cases. (1 <= T <= 50)

For each test case, there will be an integer in a single line N (1 <= N <= 10000). N is the number of nodes. The nodes are numbered from 1 to N.

Then there will be N – 1 lines with two integer x, y for each line. (1 <= x, y <= N)

x y means x is the farther of y. What’s more, we guarantee the input file is a tree. And the children are labeled from left to right by the order they appear.


Output:
For each test case, print the largest distance problem required.

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
6

***/

#include <iostream>
//using namespace std;

//http://www.geeksforgeeks.org/?p=5687


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

int max(int a, int b){
  return (a > b)?a : b;
}

int widthTr(tNode* root, int* height) {
  int l_height = 0, r_height = 0;

  int l_width = 0, r_width = 0;

  if (root == NULL) {
    *height = 0;
    return 0;
  }

  l_width = widthTr(root->left, &l_height);
  r_width = widthTr(root->right, &r_height);

  *height = max(l_height, r_height) + 1;

  return max(l_height+r_height+1, max(l_width, r_width));


}

int main() {

  int t_times;
  scanf("%d\n", &t_times);

  int fth, son;

  int result;
  int height = 0;

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


    result = widthTr(head, &height) - 1;
    printf("%d\n", result);


  }
  return 0;
}
