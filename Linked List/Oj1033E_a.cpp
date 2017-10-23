#include <bits/stdc++.h>
using namespace std;


//Wrong answer
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

void reverseA(node** head)
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
}


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
  node* temp2_2 = second; node* temp_result;
  node* answer = (node*)malloc(sizeof(node));
  //push(&answer, 0, 0);

  if (!first || !second) {
    return NULL;
  }

  while (temp1 != NULL)
  {
    while (temp2 != NULL)
    {
      coe = temp1->coe * temp2->coe;
      pwr = temp1->pwr + temp2->pwr;
      temp_result = create_node(coe, pwr);
      answer = add_poly(answer, temp_result);
      temp2 = temp2->next;
    }
    temp1 = temp1->next;
    temp2 = temp2_2;
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

int main() {
  int count;
  std::cin >> count;
  for (int i = 0; i < count; i++) {
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
