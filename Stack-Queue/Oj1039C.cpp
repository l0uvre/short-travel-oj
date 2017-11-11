/***
Description:
There are n brackets. And you want to know whether they are match to each other. The brackets will only contain {, }, (, ), [, ]. The matching rules are the same as in Math. For example, {{[}]} is not matching, and [{{}}()] is matching. Please write a program to check whether the given brackets string is matching or not.


Input:
The first line will be an integer T, which is the number of test cases. (1 <= T <= 10)

For each test case, the first line will be an integer n ( 1 <= n <= 30000)

Then there is a line with n brackets.


Output:
For each test case, print YES if the test case is a matching case. Otherwise, print NO.


Input Example:
7
1
(
2
()
2
{]
6
[(){}]
4
(])[
8
[[{{}}]]
6
[][{]]



Output Example:
NO
YES
NO
YES
NO
YES
NO

***/


#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  char data;
  struct Node* next;
}
stackNode;

stackNode* newNode(char data)
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

void push(stackNode** root, char data)
{
  stackNode *new_node = newNode(data);
  if (new_node == NULL) {
    exit(0);
  }
  new_node->next = *root;
  *root = new_node;
}

char pop(stackNode** root)
{
  if (*root == NULL) {
    exit(0);
  }
  stackNode *temp = *root;
  *root = (*root)->next;
  char poped = temp->data;
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

int isMatched(char character1 , char character2)
{
   if (character1 == '(' && character2 == ')'){
     return 1;
   }
   else if (character1 == '{' && character2 == '}')
   {
     return 1;
   }
   else if (character1 == '[' && character2 == ']')
   {
     return 1;
   }
   else{
     return 0;
   }

}

int main() {
  int count;
  scanf("%d\n", &count);
  //printf("%d ", count);

  for (int i = 0; i < count; i++) {
    int origin_len;

    scanf("%d\n", &origin_len);
    //printf("%d", origin_len);

    char parens[origin_len];
    char paren;
    char toMatch;
    int matched = 1;
    stackNode* root = NULL;

    scanf("%s\n", parens);
    //printf("%s ", parens);

    if (origin_len%2 == 1) {
      printf("NO\n");
      continue;
    }



    for (int j = 0; j < origin_len; j++)
    {
      paren = parens[j];
      if ((paren=='(')||(paren=='[')||(paren=='{'))
      {
        push(&root, paren);
      }
      else if ((paren==')')||(paren==']')||(paren=='}'))
      {
        if (root == NULL) {
          matched = 0;
          break;
        }
        toMatch = pop(&root);
        if (isMatched(toMatch, paren))
        {
          continue;
        }
        else
        {
          matched = 0;
          break;
        }
      }

    }

    if (matched) {
      printf("YES\n");
      continue;
    }
    else{
      printf("NO\n");
    }

    while (!isEmpty(root)) {
      toMatch = pop(&root);//printf("%d\n", pop(&root));
    }


  }
  return 0;
}
