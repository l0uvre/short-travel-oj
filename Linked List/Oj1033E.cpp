/***
Description:
With the help of you, ItakEjgo finally find out the spy, and reach the castle where Huang Bo lives with the army list and special group.

Huang Bo: How can you arrive here? Why my spy didn’t send any message to me?

ItakEjgo: It’s not important. Today you will die here, and the people in the Linked List Planet don’t need to program anymore!

Huang Bo: Too young too naive! Do you know why I can dominate the Planet? Because I have a special weapon, Zangetsu!

Since the Zangetsu is very powerful, ItakEjgo and the soldier are going to lose. But suddenly, Cuperman comes out and gives ItakEjgo a new weapon. Cuperman tells ItakEjgo that: ” This weapon must be used by two armies at the same time. With this new weapon, the total combat value of the army list will be the multiplication of the combat value of the two armies. By using this, you can defeat Huang Bo and save all planet citizens!”

Finally, Huang Bo lost the war. The people in the Linked List Planet live a happy life! Cuperman and ItakEjgo go back to earth by taking the machine. After they arrived at the earth, ItakEjgo still wants to know what the total combat value of two soldier list is. Since ItakEjgo is not good at math, so he asked your help again.

Input:
First line will be a positive integer T (T<=10), which is the number of messages.

The first line will be an integer n, which is the number of terms of the first polynomial. Then n lines will be the (coefficient, exponent) pairs.

After n + 1 lines, there will be an integer m for the number of terms of the second polynomial. And m lines of the (coefficient, exponent) pairs.

(1 <= n, m <= 100, all coefficients are in the range [1, 10000], all exponents are in the range [0,10^9])

Output:
For each message, print the polynomial with the same syntax as the sample shows.

Input Example:
1
2
1 1
1 2
2
1 1
1 2

Output Example:
x^2+2x^3+x^4

***/

#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
  long long coe;
  long long pwr;
  struct Node* next;
}
node;

//void print_poly(node* poly);

void push(node** head, long long coe, long long pwr)
{
  node *new_node = (node*)malloc(sizeof(node));
  new_node->coe = coe; new_node->pwr = pwr;
  new_node->next = (*head);
  (*head) = new_node;
}

node* create_node(long long coe, long long pwr)
{
  node* ptr = new node;
  ptr->coe = coe; ptr->pwr = pwr;
  ptr->next = NULL;
  //return ptr;
}

/*void reverseA(node** head)
{
  node* prev = NULL;
  node* current = *head;
  node* next;
  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  (*head) = prev;
}*/

/*void push_or_add(node** head, int coe, int pwr)
{
  node *temp = *head;
  node *pPtr = *head; node *qPtr = *head;
  while (temp)
  {
    if (temp->pwr == pwr)
    {
      temp->pwr = pwr;
      temp->coe = temp->coe + coe;

      return;
    }
    temp = temp->next;
  }
  if (!temp)
  {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->coe = coe; new_node->pwr = pwr;
    while (qPtr) {
      pPtr = qPtr;
      qPtr = qPtr->next;
      if (!qPtr) {
        pPtr->next = new_node;
        break;
      } else if (pPtr->pwr > pwr && qPtr->pwr < pwr)
      {
        new_node->next = qPtr;
        pPtr->next = new_node;
        break;
      }
    }
    return;
  }

}*/

node* add_poly(node* first, node* second)
{
  node* result = NULL;
  if (second == NULL)
  {
    return first;
  }
  if (first == NULL) {
    return second;
  }

  if (first->pwr == second->pwr)
  {
    result = first;
    result->pwr = first->pwr;
    result->coe = first->coe + second->coe;
    result->next = add_poly(first->next, second->next);
  }
  else if (first->pwr > second->pwr)
  {
    result = first;
    result->pwr = first->pwr;
    result->coe = first->coe;
    result->next = add_poly(first->next, second);
  }
  else
  {
    result = second;
    result->pwr = second->pwr;
    result->coe = second->coe;
    result->next = add_poly(first, second->next);

  }
  return result;

}


node* multiply_poly(node* first, node* second)
{
  long long coe, pwr;
  node* temp1 = first; node* temp2 = second;
  node* answer = NULL;

  if ((first==NULL) || (second==NULL)) {
    return NULL;
  }

  while (temp1 != NULL)
  {
    while (temp2 != NULL)
    {
      coe = temp1->coe * temp2->coe;
      pwr = temp1->pwr + temp2->pwr;
      answer = add_poly(answer, create_node(coe, pwr));
      temp2 = temp2->next;
    }
    temp1 = temp1->next;
    temp2 = second;
  }
  return answer;
}

void print_poly(node* poly)
{
  vector<long long> coes = {};
  vector<long long> pwrs = {};

  while (poly != NULL)
  {
    if(poly->coe != 0){
      coes.push_back(poly->coe);
      pwrs.push_back(poly->pwr);
    }
    poly = poly->next;

  }
  if (coes.size() == 0) {
    printf("0");
    return;
  }
  for (int i = coes.size()-1; i >= 0; i--)
  {
    if (pwrs[i] == 0)
    {
      if (coes[i] != 0)
      {
        printf("%lld", coes[i]);
      }
    }
    else if(pwrs[i] == 1)
    {
      if (coes[i] != 0)
      {
        if (i != coes.size()-1)
        {
          if (coes[i] > 0) {
            printf("+");
          }
        }

        if (coes[i] == 1)
        {
          printf("x");
        }
        else if (coes[i] == -1) {
          printf("-x");
        }
        else
        {
          printf("%lldx", coes[i]);
        }
      }
    }
    else
    {
      if (coes[i] != 0)
      {
        if (i != coes.size()-1)
        {
          if (coes[i] > 0) {
            printf("+");
          }
        }
        if (coes[i] == 1)
        {
          printf("x^%lld", pwrs[i]);
        }
        else if(coes[i] == -1)
        {
          printf("-x^%lld", pwrs[i]);
        }
        else
        {
          printf("%lldx^%lld", coes[i], pwrs[i]);
        }
      }
    }
  }
}

/*void polynomial_delete(node *ptr) {
        node *temp;
        while (ptr){
            temp = ptr->next;
            free(ptr);
            ptr = temp;
        }
        return;
  }*/

int main() {
  int count;
  std::cin >> count;
  for (int i = 0; i < count; i++)
  {
    node* first_poly = NULL;
    node* second_poly = NULL;
    node* result = NULL;
    int term1, term2;
    long long coe, pwr;
    cin >> term1;
    for (int j = 0; j < term1; i++) {
      cin >> coe >> pwr;
      push(&first_poly, coe, pwr);
    }

    cin >> term2;
    for (int j = 0; j < term2; i++) {
      cin >> coe >> pwr;
      push(&second_poly, coe, pwr);
    }

    result = multiply_poly(first_poly, second_poly);
    print_poly(result);
    std::cout << '\n';
  }

  return 0;
}
