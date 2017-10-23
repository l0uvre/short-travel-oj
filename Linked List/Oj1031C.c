/***
Description:
Before attack Huang Bo again, the army master created a special group. The combat value of soldiers in the special group list are random. The army master has four basic instructions in the special group: 1) Insert (x, y), 2) Delete(x), 3) Update(x,y), and 4) Reverse. The means of these instructions are:

Insert(x,y): insert soldier with combat value y at position x.

Delete(x): remove soldier at position x

Update(x,y): set combat value of soldier at position x as y.

Reverse: reverse the soldiers’ combat value in the special group list.

For example, suppose we have special group list {1,3,2,4}, position is starting from 0.

Insert (0,5) will change the special group list to {5,1,3,2,4}

Delete(3) will change the special group list to {5,1,3,4}

Update(1,7) will change the special group list to {5,7,3,4}

Reverse will change the special group list to {4,3,7,5}

Given a special group list, and a set of instructions, could you print the special group list to ItakEjgo after each instruction? For simplicity, Insert is 1, Delete is 2, Update is 3 and Reverse is 4 in the input.


Input:
First line will be a positive integer T (T<=50), which is the number of messages.

For each message, the first line will be an integer n, n is the number of soldiers at first. Then there will be n integers which are the combat value of soldiers.

Then an integer m, m is the number of operations. Then will be m lines, each is a command:

1 x y : insert soldier with combat value y at position x.

2 x: remove the soldiers at position x

3 x y: set combat value of soldier at position x as y.

4: reverse the army

The input guarantee that the army will not be empty during the operation.

(1 <= n, m <= 100, all labels will be in range [0, 1233])




Output:
For each test case, output the special group after each instruction.

Input Example:
1
4
1 3 2 4
4
1 0 5
2 3
3 1 7
4

Output Example:
5 1 3 2 4
5 1 3 4
5 7 3 4
4 3 7 5



***/


#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int value;
  struct Node* next;
}
node;

void push(node** head, int value)
{
  node *new_node = (node*)malloc(sizeof(node));
  new_node->value = value;
  new_node->next = *head;
  (*head) = new_node;
}

void insertAfter(node** head, int pos, int num)
{
  node *new_node = (node*)malloc(sizeof(node));
  node *temp = *head;
  new_node->value = num;

  if (pos == 0)
  {
    new_node->next = *head;
    (*head) = new_node;
  }
  else if (pos == 1)
  {
    new_node->next = temp->next;
    temp->next = new_node;
  }
  else
  {
    for (size_t i = 1; i < pos; i++)
    {
      temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
  }
}

void removeNode(node** head, int pos)
{
  node *temp = *head;
  if (pos == 0) {
    temp = temp->next;
    (*head) = temp;
  }
  else
  {
    for (size_t i = 1; i < pos; i++)
    {
      if (temp->next != NULL) {
        temp = temp->next;
      }
    }
    temp->next = temp->next->next;
  }
}

void updateNode(node** head, int pos, int num)
{
  node* temp = *head;
  for (size_t i = 0; i < pos; i++) {
    if (temp != NULL)
    {
      temp = temp->next;
    }
  }

    temp->value = num;


}

void reverseA(node** head)
{
  node* prev = NULL;
  node* current = *head;
  node* next;
  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  (*head) = prev;
}

void print_list(node* head)
{
  node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->value);
    temp = temp->next;
  }
  printf("\n");
}

int main()
{
  int circle;
  scanf("%d", &circle);
  for (size_t i = 0; i < circle; i++)
  {
    int oLen; node *oNode = NULL;
    scanf("%d", &oLen);
    int oNums[oLen];
    for (size_t i = 0; i < oLen; i++)
    {
      scanf("%d", &oNums[i]);
    }

    for (int i = oLen-1; i >= 0; i--)
    {
      push(&oNode, oNums[i]);
    }

    int options;
    scanf("%d", &options);
    for (size_t i = 0; i < options; i++)
    {
      int cmd;
      scanf("%d", &cmd);
      if (cmd == 1)
      {
        int pos, num;
        scanf("%d %d", &pos, &num);
        insertAfter(&oNode, pos, num);
        print_list(oNode);
      }
      else if(cmd == 2)
      {
        int pos;
        scanf("%d", &pos);
        removeNode(&oNode, pos);
        print_list(oNode);
      }
      else if(cmd == 3)
      {
        int pos, num;
        scanf("%d %d", &pos, &num);
        updateNode(&oNode, pos, num);
        print_list(oNode);
      }
      else if (cmd == 4)
      {
        reverseA(&oNode);
        print_list(oNode);
      }
    }
  }
  return 0;
}
