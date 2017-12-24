/***
Description:
There is a set with size n initially, and there are q operations, each operation will be one of the following cases:

Add x: add x to this set.

Delete: delete the minimum element of the set.

Query: print the minimum element of the set.


Input:
The first line will be an integer T, which is the number of test cases. (1 <= T <= 10). For each test case, the first line will be an integer n(1 <= n <= 106), then the second line will be n integers, they make up the initial set. The third line will be an integer q(1 <= q <= 105), it means the number of operations. Then followed by q lines, each line will be one of the following cases:

1 x: Add x.

2: Delete.

3: Query.



Output:
For each “Query”, print the minimum element of the set.


Input Example:
1
1
1
1
3

Output Example:
1

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
  MinHeap(int cap, long long *nums, int array_len);

  int parent(int i) { return (i-1)/2; }
  int left(int i) { return (2*i+1); }
  int right(int i) { return (2*i+2); }

  long long popMin();

  long long getMin();

  void MinHeapify(int i);

  void insert(long long num);
};

MinHeap::MinHeap(int cap, long long *nums, int array_len) {
  capacity = cap;
  size = 0;
  data = new long long[cap];

  for (int i = 0; i < array_len; i++) {
    data[i] = nums[i];
    size++;
  }

  for (int i = size-1; i >= 0; --i) {
    MinHeapify(i);
  }

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

  int initial_nums;
  long long num;
  int operations;
  int oprt;

  for (int i = 0; i < t_times; i++) {
    scanf("%d\n", &initial_nums);
    long long nums[initial_nums];
    for (int j = 0; j < initial_nums; j++) {
      scanf("%lld", &num);
      nums[j] = num;
    }

    MinHeap h(1000010, nums, initial_nums);
    scanf("%d\n", &operations);

    for (int j = 0; j < operations; j++) {
      scanf("%d", &oprt);
      if (oprt == 1) {
        scanf("%lld", &num);
        h.insert(num);
      }
      else if (oprt == 2) {
        h.popMin();
      }
      else if (oprt == 3) {
        printf("%lld\n", h.getMin());
      }
    }

  }
  return 0;
}
