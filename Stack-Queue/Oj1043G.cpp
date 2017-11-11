/***
Description:
You are asking to write a calculator which can do the following operations:+, -, *, /, ^ and ().

All input numbers are integers and no floating numbers appeared during the calculation.

Input:
The first line is the number of test cases, T (1 <= T <= 10)

For each test case, there is only one line with the expression. The input is always legal.

The length of expression will not exceed 50. And all median results don’t exceed 1000.

All input numbers are positive. All input expressions follow the rules in Math.

Output:
Print one integer in a single line for each test case, the result after calculation.

Input Example:
1
99+8

Output Example:
107

***/

#include<bits/stdc++.h>

typedef struct Node
{
  int data;
  char oprtr;
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

queueNode* newNode(int data, char oprtr)
{
  queueNode* new_node = (queueNode*)malloc(sizeof(queueNode));
  new_node->data = data;
  new_node->oprtr = oprtr;
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

void push_first(queue* q, int data, char oprtr)
{
  queueNode *new_node = newNode(data, oprtr);
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

void push_last(queue* q, int data, char oprtr)
{
  queueNode *new_node = newNode(data, oprtr);
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



queueNode* pop_first(queue* q)
{
  if (q->size == 0) {
    return NULL;
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
  return temp;

}

queueNode* pop_last(queue* q)
{
  if (q->size == 0) {
    return NULL;
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
  return temp;

}

//for debug;
void print_queue(queue* q) {
  while (q->size != 0) {
    if (q->front->data == -1) {
      char c = pop_first(q)->oprtr;
      printf("%c ", c);
    }
    else if(q->front->oprtr == 'N')
    {
      int digit = pop_first(q)->data;
      printf("%d ", digit);
    }
  }
}

int prio(char c)
{
	if(c == '^')
	return 3;
	else if(c == '*' || c == '/')
	return 2;
	else if(c == '+' || c == '-')
	return 1;
	else
	return -1;
}

queue* infixToPostfix(std::string s)
{
  queue* rQueue = newQueue();
  std::stack<char> cStack;
	cStack.push('N');// for convinence
  int n = s.length();

  int i = 0;

  while (i < n)
  {
    if ((s[i] >= '0' && s[i] <= '9')) {
      int j = 0;
      int digit = 0;
      while((s[i+j] >= '0' && s[i+j] <= '9'))
      {
        j++;
      }
      for (int k = 0; k < j; k++) {
        digit += (s[i+k] - '0') * pow(10, j-k-1);
      }
      push_last(rQueue, digit, 'N');
      i = i+j;
    }

    else if(s[i] == '(')
    {
      cStack.push('(');
      i++;
    }

    else if(s[i] == ')')
    {
    	while(cStack.top() != 'N' && cStack.top() != '(')
    	{
    		char c = cStack.top();
    		cStack.pop();
    	  push_last(rQueue, -1, c);
    	}

    	if(cStack.top() == '(')
    	{
    		char c = cStack.top();
    		cStack.pop();
    	}
        i++;
    }

    else{
		while(cStack.top() != 'N' && prio(s[i]) <= prio(cStack.top()))
		{
			char c = cStack.top();
			cStack.pop();
			push_last(rQueue, -1, c);
		}

		cStack.push(s[i]);
		i++;
		}
  }

  while(cStack.top() != 'N')

	{
		char c = cStack.top();
		cStack.pop();
		push_last(rQueue, -1, c);
	}


  while(!cStack.empty()) {
		cStack.pop();
	}

	return rQueue;

}



int main()
{
  int count;

  std::cin >> count;

  for (int i = 0; i < count; i++) {
    std::string infix;
    std::cin >> infix;
    queue* postfix = infixToPostfix(infix);

		std::stack<int> rStack;

    char operators;

    int outcoming;


    for (int j = 0, n = postfix->size; j < n; j++)
    {


      if (postfix->front->data != -1)
      {
        int temp = pop_first(postfix)->data;
        rStack.push(temp);
      }
      else
      {
        int a = rStack.top();
				rStack.pop();
        int b = rStack.top();
				rStack.pop();
				int result;

        operators = pop_first(postfix)->oprtr;

        if (operators == '/') {
						result = b/a;
          rStack.push(result);
        } else if (operators == '*')
				{
					result = b*a;
          rStack.push(result);
        } else if (operators == '+')
				{
					result = b+a;
          rStack.push(result);
        } else if (operators == '^')
				{
					result = (int) pow(b, a);
          rStack.push(result);
        } else if (operators == '-'){
					result = b - a;
					rStack.push(result);
      }

    }


  }
		outcoming = rStack.top();
		rStack.pop();
		if (rStack.empty()) {
			std::cout << outcoming << '\n';
		}

  }

	return 0;
}
