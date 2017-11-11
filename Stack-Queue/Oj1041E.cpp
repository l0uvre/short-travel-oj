/***
Description:
For the sequence {an}, let’s define the beautiful number of ai is j, where j is the minimum index with aj >ai and j > i. If no such j, the beautiful number of ai is 0. For each i in range [1, n], please output its corresponding beautiful number j.

Input:
The first line will be an integer T, which is the number of test cases. (1 <= T <= 10)

For each test case, the first line will be the integer n. (1 <= n <= 500000)

Then there will n lines, and the ith line will have a number represent ai. (0 <= ai <= 1000000)

Output:
N lines for each test case. The beautiful number of ai

Input Example:
1
6
3
2
6
1
1
2

Output Example:
3
3
0
6
6
0

***/

#include<bits/stdc++.h>
using namespace std;


typedef struct Node
{
  int data;
  int index;
}
myNode;

int main() {
  int count;
  scanf("%d\n", &count);

  int result[500000];

  for (int i = 0; i < count; i++) {
    int length, scanned;
    scanf("%d\n", &length);

    stack<myNode> st;

    for (int j = 0; j < length; j++)
    {
      scanf("%d\n", &scanned);
      myNode nd = {scanned, j+1};

      if (st.empty())
      {
        st.push(nd);
      }
      else if (scanned > st.top().data)
      {
        while (!st.empty() && scanned > st.top().data) {
          result[st.top().index - 1] = j + 1;
          st.pop();
        }

        st.push(nd);
      }
      else
      {
        st.push(nd);
      }
    }

    while (!st.empty())
    {
      result[st.top().index - 1] = 0;
      st.pop();
    }

    for (int j = 0; j < length; j++) {
      printf("%d\n", result[j]);
    }



  }
  return 0;
}


/***
//Brute Force
int main() {
  int count;
  scanf("%d\n", &count);

  for (int i = 0; i < count; i++) {
    int length, num, pos;
    scanf("%d\n", &length);

    int nums[length];
    for (int j = 0; j < length; j++) {
      scanf("%d\n", &num);
      nums[j] = num;
    }
    for (int j = 0; j < length; j++) {
      if (j == length - 1) {
        printf("0\n");
        break;
      }
      pos = j + 1;
      while (nums[j] >= nums[pos] && pos < length) {
        pos++;
      }
	//printf("  %d\n", pos);
      if (pos == length) {
        printf("0\n");
        continue;
      }
      else
      {
        printf("%d\n", ++pos);
      }
    }




  }
  return 0;
}
***/
