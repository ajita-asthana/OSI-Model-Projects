#include <iostream>
using namespace std;

int sum(const int *numbers, const int numberLen) 
{
  //recursion instead of for loop, pointers;
  return numberLen == 0 ? 0 : *numbers + sum(numbers+1, numberLen - 1);
}
int main() 
{
  int numbers[] = {10, 12, 13, 15, 70};
 cout << "What's going on with Array +1  " << "\n";
 for(int i=0; i<5; i++)
 {
  cout << "The current address is: "<< numbers + i << "\n";
  cout << "The value at the address is: " << *(numbers+i) << "\n";
 // cout << sum(numbers, 5) << "\n";
 }
  return 0;
}

