#include <iostream>
using namespace std;
void reverse(int (&arr)[6], const int len)
{
  for(int i=0; i<len/2; i++)
  {
    int val = arr[i];
    int idxFromEnd = len-i-1;
    arr[i] = arr[idxFromEnd];
    arr[idxFromEnd] = val;
  }
  
  return;
}
void transpose(const int input[][LENGTH], const int output[][WIDTH])
{
  for(int i=0; i<WIDTH; i++)
  {
    for(int j=0; j<LENGTH; j++)
    {
      output[j][i] = input[i][j];
    }
  }
}
int main()
{
  int arr[] = {1,2,3,47,12,62};
  transpose(
  return 0;
}
