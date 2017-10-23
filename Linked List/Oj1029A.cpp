/***
Description:
Cuperman has a machine which can travel among different planets. ItakEjgo used this machine and arrived the Linked List Planet. Linked List Planet was controlled by an evil guy “Huang Bo”, who raises hard problems to the island citizens, and forces them to write programs to solve. The planet citizens want to fight against Huang Bo. However, do that is not so easy, so they asked help from ItakeEjgo. The exact request is:

They have two branches of soldiers. In each branch, the soldiers are in an ordered (i.e., non-decreasing) list by their combat values. However, it only has one way to reach Huang Bo’s castle. Then, they need combine two soldier lists to one army list. They hope the army list is still ordered.

However, ItakEjgo do not know how to solve it by linked list. Fortunately, ItakEjgo knows that you are learning linked list in CS203. So ItakEjgo asks you for help!!! Each time, ItakEjgo will give you two ordered soldiers list, and you must return the army list to him after combination.


Input:
First line will be a positive integer T (T<=10), which is the number of messages.

For each message, the first line will be two integer n and m, which is the number of soldiers in the two branches. The second line will be the combat values of one branch. The third line will be the combat values of the other branch.

(1 <= n, m <= 100000, the combat values will in the range [0, 10^9])


Output:
For each message, prints the combat value of each solider in army list after combination.

Input Example:
2
3 5
1 2 3
1 2 3 4 5
4 7
1 1 2 2
1 1 2 2 3 3 4

Output Example:
1 1 2 2 3 3 4 5
1 1 1 1 2 2 2 2 3 3 4

***/


#include <bits/stdc++.h>
using namespace std;

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
  new_node->next = (*head);

  (*head) = new_node;

}

void print_list(node *head)
{
  while (head != NULL) {
    printf("%d ", head->value);
    head = head->next;
  }
}

node* merge_list(node* list1, node* list2)
{
  node* result = NULL;
  if (list1 == NULL) {
    return list2;
  }
  if (list2 == NULL) {
    return list1;
  }

  if (list1->value <= list2->value) {
    result = list1;
    result->next = merge_list(list1->next, list2);
  }
  else
  {
    result = list2;
    result->next = merge_list(list2->next, list1);
  }
  return result;

}


int main()
{
  int count, len1, len2;
  cin >> count;

  for (int i = 0; i < count; i++)
  {
    cin >> len1 >> len2;
    node *first_list = NULL;
    node *second_list = NULL;
    node *result = NULL;
    int nums1[len1]; int nums2[len2];
    for (size_t i = 0; i < len1; i++)
    {
      cin >> nums1[i];
    }
    for (size_t i = 0; i < len2; i++)
    {
      cin >> nums2[i];
    }
    for (int i = len1 - 1; i >= 0 ; i--) {
      push(&first_list, nums1[i]);
    }
    for (int i = len2 - 1; i >= 0 ; i--) {
      push(&second_list, nums2[i]);
    }
    result = merge_list(first_list, second_list);

    print_list(result);
    std::cout << '\n';
  }


  return 0;
}
