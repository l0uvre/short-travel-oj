/***
Description:
You have a stack with size n. Now there are m operations. Each operation will be one of the following cases:

Push x: If the stack is not full, push x into the stack. Otherwise print x.

Pop: If the stack has at least one element, print and pop the top element of the stack. Otherwise do nothing.

After the m operations, you should print all elements in the stack from the top.

Please write a program to print the elements in the order problem described.


Input:
The first line will be an integer T, which is the number of test cases. (1 <= T <= 10)

For each test case, the first line will be two integers n and m. (1 <= n <= 1000, 1 <= m <= 105)

Then there will be m lines, each line will be one of the following cases:

1 x: push x (0 <= x <= 105)

2: pop


Output:
Single line for each element, in the order problem required.


Input Example:
1
5 12
1 1
2
1 2
1 3
1 4
2
1 5
1 6
1 7
2
2
1 8

Output Example:
1
4
7
6
8
5
3
2

***/


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node
{
  int data;
  struct Node* next;
}
stackNode;

stackNode* newNode(int data)
{
  stackNode* new_node = (stackNode*) malloc(sizeof(stackNode));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

int isEmpty(stackNode* root)
{
  return !root;
}

void push(stackNode** root, int data)
{
  stackNode *new_node = newNode(data);
  new_node->next = *root;
  *root = new_node;
}

int pop(stackNode** root)
{
  stackNode *temp = *root;
  *root = (*root)->next;
  int poped = temp->data;
  free(temp);
  return poped;
}

int size(stackNode** root)
{
  int size = 0;
  stackNode* temp = *root;
  while (temp)
  {
    size++;
    temp = temp->next;
  }
  return size;
}

int main() {
  int count;
  scanf("%d", &count);

  for (int i = 0; i < count; i++) {
    int origin_len, commands;
    int cmd;
    scanf("%d %d", &origin_len, &commands);
    stackNode* root = NULL;
    /*for (int j = 0; i < origin_len; i++) {
      push(&root, 0);
    }*/

    for (int j = 0; j < commands; j++) {
      scanf("%d", &cmd);
      if (cmd == 1) {
        int data;
        scanf("%d", &data);
        if (size(&root) < origin_len) {
          push(&root, data);
        }
        else
        {
          printf("%d\n", data);
        }

      }
      if (cmd == 2) {
        if(isEmpty(root)){
          continue;
        }
        else {
          printf("%d\n", pop(&root));
        }
      }
    }

    //printf("%d\n", size(&root));
    while (!isEmpty(root)) {
      printf("%d\n", pop(&root));//printf("%d\n", pop(&root));
    }

  }
  return 0;
}
