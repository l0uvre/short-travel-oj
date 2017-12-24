/***
Description:
There are n sorted values a1……an, you are asked to combine them to one, you are allowed to combine at most k values to one each time, and the cost of one combination is the sum of all values that you combine, the cost are not allowed to be more than m, you are asked to find the minimum k.

Input:
The first line will be an integer T, which is the number of test cases. (1 <= T <= 10). For each test case, the first line will be two integer n(1 <= n <= 105) and m( <= m <= 1018), n is the number of values, m is the limit of cost, the second line will be n integers, a1……an(1 <= ai <= 1.2*109). We promise that ai >= ai-1 (2 <= i <= n)


Output:
For each test output the minimum k.

Input Example:
1
2 100
1 2

Output Example:
2

***/


#include<bits/stdc++.h>

// Have leant copy constructor

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

  MinHeap(const MinHeap &h);

  int parent(int i) { return (i-1)/2; }
  int left(int i) { return (2*i+1); }
  int right(int i) { return (2*i+2); }

  long long popMin();

  long long getMin();

  int getSize();

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

MinHeap::MinHeap(const MinHeap &h) {
  capacity = h.capacity;
  data = new long long[capacity];
  size = h.size;
  for (int i = 0; i < size; i++) {
    data[i] = h.data[i];
  }

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


int isLegal(MinHeap h, long long k, long long cost, long long initial_nums);


int main() {

  int t_times;
  scanf("%d\n", &t_times);

  long long initial_nums, max_cost;
  long long num;
  long long start, end, middle;

  long long result;



  for (int i = 0; i < t_times; i++) {

    scanf("%lld %lld\n", &initial_nums, &max_cost);

    long long result = initial_nums;
    //long long temp = 0;

    long long nums[initial_nums];

    for (int j = 0; j < initial_nums; j++) {
      scanf("%lld", &num);
      nums[j] = num;
      //h.insert(num);
    }

    MinHeap h(200001, nums, initial_nums);


    if (h.getSize() == 1) {
      result = 1;
      printf("%lld\n", result);
      continue;
    }

    start = 2;
    end = initial_nums;

    while (start <= end)
    {
      middle = start + (end - start) /2;

      if (isLegal(h, middle, max_cost, initial_nums)) {
        if (middle < result) {
          result = middle;
        }
        end = middle - 1;
      }
      else {
        start = middle + 1;
      }
    }


    printf("%lld\n", result);

  }
  return 0;
}

int isLegal(MinHeap minPQ, long long k, long long cost, long long initial_nums) {

  MinHeap h = minPQ;

  while ((initial_nums-1)%(k-1) !=0 ) {
    initial_nums++;
    h.insert(0);
  }

  long long temp = 0;
  long long result = 0;

  while (h.getSize() != 1) {
    for (int j = 0; j < k; j++) {
      if (h.getSize() == 0) {
        break;
      }
      temp += h.popMin();
    }

    h.insert(temp);
    result += temp;
    temp = 0;

  }

  if (result <= cost) {
    return 1;
  } else {
    return 0;
  }
}
