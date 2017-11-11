/***
Description:
You have a queue with size n. Now there are m operations. Each operation will be one of the following cases:

Push x: If the queue is not full, push x into the queue. Otherwise print x.

Pop: If the queue has at least one element, print and pop the front element of the queue. Otherwise do nothing.

After the m operations, you should print all elements in the queue from the front.

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
1 2
1 3
1 4
1 5
1 6
2
1 7
1 8
1 9
2
1 10

Output Example:
6
1
8
9
2
3
4
5
7
10

***/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node* next;
}
queueNode;

typedef struct Queue
{
  int size;
  struct Node *front, *rear;
}
queue;

queueNode* newNode(int data)
{
  queueNode* new_node = (queueNode*)malloc(sizeof(queueNode));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

queue* newQueue()
{
  queue *q = (queue*)malloc(sizeof(queue));
  q->front = q->rear = NULL;
  q->size = 0;
  return q;
}

int isEmpty(queue* q)
{
  return (q->size == 0);
}

void push(queue* q, int data)
{
  queueNode *new_node = newNode(data);
  if (q->rear == NULL) {
    q->front = q->rear = new_node ;
    q->size++;
    return;
  }
  else
  {
    q->rear->next = new_node;
    q->rear = new_node;
    q->size++;
  }
}

int pop(queue* q)
{
  if (q->front == NULL) {
    return 0;
  }

  queueNode* temp = q->front;
  q->front = q->front->next;

  q->size--;

  if (q->front==NULL) {
    q->rear = NULL;
  }

  return temp->data;

}

int main() {
  int count;
  scanf("%d", &count);

  for (int i = 0; i < count; i++) {
    int origin_len, commands;
    int cmd;
    scanf("%d %d", &origin_len, &commands);
    queue* rQueue = newQueue();

    for (int j = 0; j < commands; j++) {
      scanf("%d", &cmd);
      if (cmd == 1) {
        int data;
        scanf("%d", &data);
        if (rQueue->size < origin_len) {
          push(rQueue, data);
        }
        else
        {
          printf("%d\n", data);
        }

      }
      if (cmd == 2) {
        if(isEmpty(rQueue)){
          continue;
        }
        else {
          printf("%d\n", pop(rQueue));
        }
      }
    }

    while (rQueue->size != 0) {
      printf("%d\n", pop(rQueue));
    }

  }
  return 0;
}
