/***
Description:
After last lecture, you must know a lot of queue. Queue is a FIFO list. But do you know magic queue? Magic queue is a queue which supports four operations:

Push_frist x: push an element x from the front of the queue.

Pop_first: pop an element x from the queue.

Push_last x: push an element x at the rear of the queue.

Pop_last:pop an element x at the rear of the queue.

(See more in the samples)

Now there is a magic queue and n operations. Please write a program which can display the element in the queue after n operations.



Input:
The first line will be an integer T, which is the number of test cases. (1 <= T <= 10)

For each test case, the first line will be an integer n (1 <= n <= 105)

Then there will be n lines, each line will be one of the following cases:

1 1 x: push_first x

1 2: pop_first

2 1 x: push_last x

2 2:pop_last

(0 <= x <= 103)

The input ensures that when you pop, there always are some elements in the queue.



Output:
For each test case, print the elements in the magic queue from the front to the rear. And each element should in a single line.


Input Example:
1
8
1 1 1
1 1 2
1 1 3
2 1 1
2 1 2
2 1 3
1 2
2 2



Output Example:
2
1
1
2

***/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node* next;
  struct Node* prev;
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
  new_node->prev = NULL;
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

void push_first(queue* q, int data)
{
  queueNode *new_node = newNode(data);
  queueNode *old_first = q->front;
  q->front = new_node;
  q->front->next = old_first;

  if (old_first)
  {
    old_first->prev = new_node;
  }

  if (!(q->rear)) {
    q->rear = q->front;
  }

  q->size++;
}

void push_last(queue* q, int data)
{
  queueNode *new_node = newNode(data);
  queueNode *old_last = q->rear;
  q->rear = new_node;
  q->rear->prev = old_last;

  if (old_last)
  {
    old_last->next = q->rear;
  }

  if (!(q->front)) {
    q->front = q->rear;
  }

  q->size++;

}



int pop_first(queue* q)
{
  if (q->size == 0) {
    return 0;
  }

  queueNode* temp = q->front;
  q->front = q->front->next;
  if (q->front==NULL) {
    q->rear = NULL;
  }
  else
  {
    q->front->prev = NULL;
  }
  q->size--;
  return temp->data;

}

int pop_last(queue* q)
{
  if (q->size == 0) {
    return 0;
  }

  queueNode* temp = q->rear;
  q->rear = q->rear->prev;

  if (q->rear==NULL) {
    q->front = NULL;
  }
  else
  {
    q->rear->next = NULL;
  }
  q->size--;
  return temp->data;

}

int main() {
  int count;
  scanf("%d\n", &count);

  for (int i = 0; i < count; i++) {
    int commands;
    int opt1, opt2, dump;
    scanf("%d\n", &commands);
    queue* rQueue = newQueue();

    for (int j = 0; j < commands; j++) {
      scanf("%d %d", &opt1, &opt2);
      if (opt1 == 1) {
        if (opt2 == 1) {
          int data;
          scanf("%d\n", &data);
          push_first(rQueue, data);
        }
        else if (opt2 == 2) {
          dump = pop_first(rQueue);
        }

      }
      if (opt1 == 2) {
        if (opt2 == 1) {
          int data;
          scanf("%d\n", &data);
          push_last(rQueue, data);
        }
        else if (opt2 == 2) {
           dump = pop_last(rQueue);
        }
      }
    }

    while (rQueue->size != 0) {
      printf("%d\n", pop_first(rQueue));
    }

  }
  return 0;
}
