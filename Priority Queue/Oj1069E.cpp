/***
Description:
There are n values, you are asked to combine them to one, you are allowed to combine at most k values to one each time, and the cost of one combination is the sum of all values that you combine, print the minimum cost.

Input:
The first line will be an integer T, which is the number of test cases. (1 <= T <= 10). For each test case, the first line will be two integer n(1 <= n <= 105) and k(2 <= k <= 105), n is the number of values, k has been explained in problem description. The second line are those n values, we promise that (n - 1) % (k - 1) = 0.


Output:
For each test output the minimum cost.

Input Example:
1
3 2
1 2 3

Output Example:
9

***/


#include<bits/stdc++.h>


void swap(long long *a, long long *b) {
  long long temp = *a;
  *a = *b;
  *b = temp;
}

class MinHeap {
  long long  *data;
  int capacity;
  int size; // current size of the priority_queue

public:
  MinHeap(int capacity);

  int parent(int i) { return (i-1)/2; }
  int left(int i) { return (2*i+1); }
  int right(int i) { return (2*i+2); }

  long long popMin();

  long long getMin();

  int getSize();

  void MinHeapify(int i);

  void insert(long long num);
};

MinHeap::MinHeap(int cap) {
  capacity = cap;
  size = 0;
  data = new long long[cap];
}

int MinHeap::getSize() {
  return size;
}

void MinHeap::insert(long long num) {
  size++;
  int i = size-1;
  data[i] = num;

  while (i != 0 && data[parent(i)]> data[i]) {
    swap(&data[parent(i)], &data[i]);
    i = parent(i);
  }
}

long long MinHeap::popMin() {

  if (size <= 0) {
    return 0;
  }

  if (size == 1) {
    size--;
    return data[0];
  }

  long long root = data[0];
  data[0] = data[size-1];
  size--;
  MinHeapify(0);

  return root;

}


long long MinHeap::getMin(){
  return data[0];
}

void MinHeap::MinHeapify(int i) {

  int l = left(i);
  int r = right(i);

  int smallest = i;

  if (l < size && data[i] > data[l]) {
    smallest = l;
  }

  if (r < size && data[smallest] > data[r]) {
    smallest = r;
  }

  if (smallest != i) {
    swap(&data[i], &data[smallest]);
    MinHeapify(smallest);
  }

}



int main() {

  int t_times;
  scanf("%d\n", &t_times);

  int initial_nums, comb_nums;
  long long num;

  for (int i = 0; i < t_times; i++) {
    long long result = 0;
    long long temp = 0;
    scanf("%d %d\n", &initial_nums, &comb_nums);

    MinHeap h(100001);

    for (int j = 0; j < initial_nums; j++) {
      scanf("%lld", &num);
      h.insert(num);
    }

    if (h.getSize() == 1) {
      result += h.getMin();
    }

    while (h.getSize() != 1) {
      for (int j = 0; j < comb_nums; j++) {
        if (h.getSize() == 0) {
          break;
        }
        temp += h.popMin();
      }
      h.insert(temp);
      result += temp;
      temp = 0;

    }

    printf("%lld\n", result);

  }
  return 0;
}
