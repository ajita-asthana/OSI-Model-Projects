#include<iostream>
using namespace std;
int main()
{
  char *oddOrEven = "Never odd or even";
  char *nthCharPtr = (oddOrEven+6);
  nthCharPtr = nthCharPtr-2;
  nthCharPtr++;
  char **pointerPtr = &nthCharPtr;
  int diff = nthCharPtr - oddOrEven;
  cout << " Difference between pointers " << diff << "\n";
  return 0;
}
