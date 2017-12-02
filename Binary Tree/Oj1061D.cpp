/***
Description:
Give you the in-order and post-order traversal of a binary tree T. Please find the preorder traversal of T.

Input:
First line is an integer T, which is the number of test cases. (1 <= T <= 50)

For each test case, there will be an integer in a single line N (1 <= N <= 1024). N is the number of nodes. The nodes are numbered from 1 to N.

Then there will be two lines.

The 1st/2nd line will be the in/post order traversal of the Tree



Output:
For each test case, please print the pre-order traversal of the tree.


Input Example:
1
8
7 2 4 1 5 3 8 6
7 2 4 5 8 6 3 1

Output Example:
1 4 2 7 3 5 6 8

***/


#include <iostream>
using namespace std;


//http://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/

int search(int arr[], int len, int target) {
  for (int i = 0; i < len; i++) {
    if (arr[i] == target) {
      return i;
    }
  }

  return -1;
}

void printPre(int inOr[], int posOr[], int len) {
  //cout << posOr[len-1] << " ";
  printf("%d ", posOr[len-1]);
  int root_index = search(inOr, len, posOr[len-1]);

  if (root_index != 0) {
    printPre(inOr, posOr, root_index);
  }

  if (root_index != len-1) {
    printPre(inOr+root_index+1, posOr+root_index, len - root_index-1);
  }
}

int main(void) {
  int t_times;
  int len;
  scanf("%d\n", &t_times);

  for (int i = 0; i < t_times; i++) {
  scanf("%d\n", &len);

  int inOr[len];
  int posOr[len];
    for (int j = 0; j < len; j++) {
      if (j == len-1) {
        scanf("%d\n", &inOr[j]);
        break;
      }
      scanf("%d ", &inOr[j]);
    }

    for (int j = 0; j < len; j++) {
      if (j == len-1) {
        scanf("%d\n", &posOr[j]);
        break;
      }
      scanf("%d ", &posOr[j]);
    }

	//printf("OK\n");

    printPre(inOr, posOr, len);
    printf("\n");

  }

  return 0;
}
