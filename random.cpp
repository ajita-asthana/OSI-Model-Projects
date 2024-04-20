#include <iostream>
#include <cmath>
using namespace std;

double calcPi(const int number)
{
   int count = 0;
   srand(time(0));
   double x = rand() / (double) RAND_MAX;
   double y = rand() / (double) RAND_MAX;
   if(sqrt(x*x + y*y) < 1)
     count++;

   return (count / static_cast<double>(number)) * 4;
}

int main()
{
  int n;
  cout << "Insert the number of dart throws: ";
  cin >> n;
  cout << "The value of Pi is: "<< calcPi(n);

  return 0;
}
