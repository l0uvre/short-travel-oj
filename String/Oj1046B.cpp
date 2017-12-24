/***
Description:
As you know, string has several operations:

1.      Add x pos: add char x to the position pos.

2.      Delete pos: delete char at the position pos.

3.      Sstr x y: print the substring of s from position x to y (don’t change origin string s).

4.      Reverse x y: reverse the char from position x to y

Now give you a string S and n operations, please output the result after each operation.

The string begins with index 0.


Input:
The first line will be an integer T, which is the number of test cases. (1 <= T <= 10)

The second line is a string S. |S| <= 1000. S will contain both upper case and lowercase English letters.

The third line will be an integer n (1 <= n <= 40). Then n operations:

Add x pos

Delete pos

Sstr x y

Reverse x y

Where x, y and pos are integers. The input ensures all operations are legal, and x <= y.



Output:
N strings for each test case, the result after each operations.


Input Example:
1
HiMadamIMAdam
6
Sstr 2 12
Delete 0
Delete 0
Reverse 0 10
Add M 0
Delete 1


Output Example:
MadamIMAdam
iMadamIMAdam
MadamIMAdam
madAMImadaM
MmadAMImadaM
MadAMImadaM

***/


#include<bits/stdc++.h>
using namespace std;

int main() {

  int t_times;
  string str_read;
  int opt_times;
  string option;

  scanf("%d\n", &t_times);

  for (int i = 0; i < t_times; i++) {
    std::cin >> str_read;
    std::cin >> opt_times;

    for (int j = 0; j < opt_times; j++) {
      std::cin >> option;
      if (option == "Sstr") {
        int begin, end;
        std::cin >> begin >> end;

        string result = str_read.substr(begin, end - begin+1);
        std::cout << result << '\n';
        //std::cout << str_read << '\n';
      }
      else if (option == "Add")
      {
        char chrToAdd;
        size_t pos;
        std::cin >> chrToAdd >> pos;
        //std::cout <<chrToAdd <<pos << '\n';
        str_read.insert(pos, 1 , chrToAdd);
        std::cout << str_read << '\n';
      }
      else if (option == "Delete")
      {
        size_t pos;
        std::cin >> pos;
        str_read.erase(pos, 1);
        std::cout << str_read << '\n';
      }
      else if (option == "Reverse")
      {
        int begin, end;
        std::cin >> begin >> end;
        reverse(str_read.begin()+begin, str_read.begin()+ end + 1);
        std::cout << str_read << '\n';
      }
    }


  }
  return 0;
}
