/***
Description:
In the CS203 midterm examination, Dr. Tang requires K students to sit in a row. However, it only has N available seats in that row, at positions seat[1], seat[2], …, seat[n]. To prevent cheating, Dr. Tang wants to assign the students to these available seats, such that the minimum distance between any two adjacent students is as large as possible. Could you tell him what is the largest minimum distance?

Input:
Standard input will contain multiple test cases. The first line of the input is a single integer T (1 <= T <= 10) which is the number of test cases.

T test cases follow, for each test case:

The first line contains two integers N and K (2 <= K <= N <= 100000)

The second line contains N integers, which are the positions of available seats, i.e., the i-th integer is the position of seat[i] (0 <= seat[i] <= 109).

Output:
Each test case prints a single line. The largest minimum distance between any two adjacent students.

Input Example:
2
7 7
1 2 3 4 5 6 7
3 2
1 4 7

Output Example:
1
6

***/

//prototype: http://www.geeksforgeeks.org/place-k-elements-such-that-minimum-distance-is-maximized/


#include <bits/stdc++.h>
using namespace std;

/*bool check(int nums[], int array_len, int rows, int result);*/
bool isFeasible(int nums[], int array_len, int target, int result);

int main() {
  int count, array_len, target;
  cin >> count;

  for (int i = 0; i < count; i++) {
    cin >> array_len >> target;
    int nums[array_len];
    for (int i = 0; i < array_len; i++) {
      cin >> nums[i];
    }
    size_t size = sizeof(nums) / sizeof(nums[0]);
    sort(nums, nums + size);

    int end = round((nums[array_len-1] - nums[0])/(float)(target-1));
    int begin = 0;
    int result = 1;

    while (begin <= end){
      int medium = begin + (end - begin)/2;
      if (isFeasible(nums, array_len, target, medium)) {
        if (medium > result) {
          result = medium;
        }
        begin = medium + 1;
      }else{
        end = medium - 1;
      }
    }
    cout << result << endl;
  }
  return 0;
}

bool isFeasible(int nums[], int array_len, int target, int result)
{
    int pos = nums[0];

    int elements = 1;

    for (int i=1; i < array_len; i++)
    {
        if (nums[i] - pos >= result)
        {
            pos = nums[i];
            elements++;

            if (elements == target)
              return true;
        }
    }
    return 0;
}
