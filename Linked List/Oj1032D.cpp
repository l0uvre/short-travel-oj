/***
Description:
The army master found that Huang Bo seem know all his strategies before the wars.  The army master suspects there is a spy in the special group. Who is spy? He asked ItakEjgo.

ItakEjgo told him “Counting-out game” can help him find the spy, the descprition of “counting-out gram” is:

The soldiers in special group are standing in a circle waiting to be executed. The soldiers are numbered from 0. At first, the soldier numbered 0 is the leader. For each round of the game, counting begins at the next solider after the leader in the circle and proceeds around the circle in clock-wise direction. After k-1 soldiers are counted, the next person is removed from that circle. And the next person after the removed soldier becomes the new leader. The procedure is repeated with the remaining soldiers, starting with the next leader, until only one soldier remains. The remained soldier is spy.

The army master asks you for help. Please, if and only if the army master find out the spy, ItakEjgo can defeat the evil Huang Bo!


Input:
First line will be a positive integer T (T<=10), which is the number of messages.

For each message, the line will be n and k, the number of soldiers and the counting number.

 (1 <= n <= 100, 1 <= k <= 100)


Output:
For each message, print the number of the last soldier.

Input Example:
2
2 3
2 56


Output Example:
0
1



***/

#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
  int value;
  struct Node* next;
}
node;

node *create_node(int value){
  node *temp = (node*)malloc(sizeof(node));
  temp->next = NULL;
  temp->value = value;
}

void get_spy(int n, int k){
  node *head = create_node(0);
  node *temp = head;
  for (size_t i = 1; i < n; i++) {
    temp->next = create_node(i);
    temp = temp->next;
  }
  temp->next = head;

  node *ptr1 = head;
  node *ptr2 = head;
  while (ptr1->next != ptr1)
  {
    int counter = 0;
    while (counter != k) {
      ptr2 = ptr1;
      ptr1 = ptr1->next;
      counter++;
    }


    ptr1 = ptr1->next;
    ptr2->next = ptr1;
    //ptr1 = ptr2->next;



  }

  printf("%d\n", ptr1->value);
}

int main()
{
    int count;
    int n, k;
    scanf("%d",&count);
    for (size_t i = 0; i < count; i++) {
      scanf("%d %d", &n, &k);
      get_spy(n, k);
    }
return 0;
}
