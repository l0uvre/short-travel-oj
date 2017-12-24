/***
Description:
Alice must go to school everyday, but she wants to make the journey interesting, so she would like to play a game this time.

There are n stones on the road,  Alice go though these stones step by step. In each step, Alice could go to the next nearest stone. She will throw this stone ahead if the current number of step is odd, otherwise, she will skip it.  Now, you have the information about the stones, i.e., each stone has two attributes: Pi  (the position of that stone) and Di (the throw distance of that stone), and you are asked to find the largest distance Alice could walk.

Please note that if there are two or more stones at the same position, Alice will go to the one with the smallest Di first.


Input:
The first line will be an integer T, which is the number of test cases. (1 <= T <= 3). For each test case, the first line will be an integer n(1 <= n <= 105), then followed by n lines, each line will be two integers Pi(1 <= Pi <= 109) and Di(1 <= Di <= 109), Pi means the position of the i-th stone, Di means how far Alice can throw it.


Output:
Output one line for each test, the largest distance Alice could walk.


Input Example:
1
2
1 1
2 2


Output Example:
4

***/



#include<bits/stdc++.h>


void swap(long long *a, long long *b) {
  long long temp = *a;
  *a = *b;
  *b = temp;
}

typedef struct Node {
  long long pos;
  long long dis;
}
node;

class MinHeap {
  node *nodes;
  int capacity;
  int size; // current size of the priority_queue

public:
  MinHeap(int capacity);

  int parent(int i) { return (i-1)/2; }
  int left(int i) { return (2*i+1); }
  int right(int i) { return (2*i+2); }

  node popMin();

  node getMin();

  int getSize();

  void MinHeapify(int i);

  void insert(long long data1, long long data2);
};

MinHeap::MinHeap(int cap) {
  capacity = cap;
  size = 0;
  nodes = new node[cap];
}

int MinHeap::getSize() {
  return size;
}

void MinHeap::insert(long long data1, long long data2) {
  size++;
  int i = size-1;
  nodes[i].pos = data1;
  nodes[i].dis = data2;

  while (i != 0 && (nodes[parent(i)].pos> nodes[i].pos || (nodes[parent(i)].pos == nodes[i].pos&&nodes[parent(i)].dis > nodes[i].dis)) ) {
    swap(&nodes[parent(i)].pos, &nodes[i].pos);
    swap(&nodes[parent(i)].dis, &nodes[i].dis);
    i = parent(i);
  }
}

node MinHeap::popMin() {

  if (size == 1) {
    size--;
    return nodes[0];
  }

  node root = nodes[0];
  nodes[0] = nodes[size-1];
  size--;
  MinHeapify(0);

  return root;

}

node MinHeap::getMin(){
  return nodes[0];
}

void MinHeap::MinHeapify(int i) {

  int l = left(i);
  int r = right(i);
  int smallest = i;

  if (l < size && ((nodes[i].pos > nodes[l].pos) || (nodes[i].pos == nodes[l].pos && nodes[i].dis > nodes[l].dis)) ) {
    smallest = l;
  }

  if (r < size && (nodes[smallest].pos > nodes[r].pos|| (nodes[smallest].dis > nodes[r].dis &&nodes[smallest].pos == nodes[r].pos) ) ) {
    smallest = r;
  }

  if (smallest != i) {
    swap(&nodes[i].pos, &nodes[smallest].pos);
    swap(&nodes[i].dis, &nodes[smallest].dis);
    MinHeapify(smallest);
  }

}



int main() {

  int t_times;
  scanf("%d\n", &t_times);

  int stones;
  long long pos, dis;


  for (int i = 0; i < t_times; i++) {
    long long step = 0;
    long long result = 0;
    node stone;
    scanf("%d\n", &stones);

    MinHeap h(stones);

    for (int j = 0; j < stones; j++) {
      scanf("%lld %lld", &pos, &dis);
      h.insert(pos, dis);
    }

    while (h.getSize() != 0) {
      stone = h.popMin();
      step++;
      if (step%2 == 1) {
        result = stone.pos+stone.dis;
        h.insert(result, stone.dis);
      }
    }

    printf("%lld\n", result);

  }
  return 0;
}
