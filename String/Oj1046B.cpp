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
