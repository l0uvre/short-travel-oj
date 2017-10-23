
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
