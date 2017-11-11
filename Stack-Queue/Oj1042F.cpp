//https://stackoverflow.com/questions/8031939/finding-maximum-for-every-window-of-size-k-in-an-array


/***
Description:
The problem is simple. Give you a sequence {an}, you should print the maximum and minimum value of every continuous subsequence of {an} with length k.


Input:
The first line will be an integer T, which is the number of test cases. (1 <= T <= 10)

For each test case there will be two integers n and k. (1 <= n <= 5*105, 1 <= k <= n)

Then a line with n elements in the sequence {an}. ( 0 <= |ai| <= 103)

Output:
The output will contain two lines for each test case.

The first line will be n – k + 1 elements, the minimum value for each continuous subsequence with length k.

Then there is a line with n – k + 1 elements, the maximum value for each continuous subsequence with length k.

Print the answer of the subsequence in the same order with their first element appeared in {an}

(see details in the sample)


Input Example:
1
5 3
1 3 2 5 4



Output Example:
1 2 2
3 5 5

***/

#include<bits/stdc++.h>
using namespace std;


int main() {
    int tests, length, window, numWindow;
    scanf("%d\n", &tests);
    //cout << tests << endl;

    for (int i = 0; i < tests; i++) {
      scanf("%d %d\n", &length, &window);
      //cout << length << window <<endl;
      numWindow = length - window + 1;

      int readInputs[length];
      int LR[length];
      int RL[length];
      int max_nums[numWindow];
      int min_nums[numWindow];

      for (int j = 0; j < length; j++) {
        scanf("%d ", &readInputs[j]);
      }
      scanf("\n");

      /*for (int j = 0; j < length; j++) {
        cout << readInputs[j]<<endl;
      }*/

      for (int j = 0; j < length; j++) {
        if (j%window == 0) {
          LR[j] = readInputs[j];
        }
        else
        {
          LR[j] = max(LR[j-1], readInputs[j]);
        }
      }

      for (int j = length - 1; j >= 0; j--) {
        if (j == length - 1) {
          RL[j] = readInputs[j];
        }
        else if ((j+1)%window == 0)
        {
          RL[j] = readInputs[j];
        }
        else
        {
          RL[j] = max(RL[j+1], readInputs[j]);
        }
      }

      for (int j = 0; j < numWindow; j++) {
        max_nums[j] = max(RL[j], LR[j + window - 1]);
      }

      for (int j = 0; j < length; j++) {
        if (j%window == 0) {
          LR[j] = readInputs[j];
        }
        else
        {
          LR[j] = min(LR[j-1], readInputs[j]);
        }
      }

      for (int j = length - 1; j >= 0; j--) {
        if (j == length - 1) {
          RL[j] = readInputs[j];
        }
        else if ((j+1)%window == 0)
        {
          RL[j] = readInputs[j];
        }
        else
        {
          RL[j] = min(RL[j+1], readInputs[j]);
        }
      }

      for (int j = 0; j < numWindow; j++) {
        min_nums[j] = min(RL[j], LR[j + window - 1]);
      }

      for (int j = 0; j < numWindow; j++) {
        std::cout << min_nums[j] << " ";
      }
      std::cout << '\n';

      for (int j = 0; j < numWindow; j++) {
        std::cout << max_nums[j] << " ";
      }
      std::cout << '\n';
    }


}
