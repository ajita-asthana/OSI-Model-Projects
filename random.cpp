#include <iostream>
#include <vector>
using namespace std;
int main()
{
  const int ARRAY_LEN = 100;
  int arr[ARRAY_LEN];
  int *p = arr;
  int *q = &arr[0];
  arr[0] = 90;
  cout <<"Value of variable q is " << *q;
}
