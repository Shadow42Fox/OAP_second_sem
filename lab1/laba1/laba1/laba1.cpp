//#include <iostream>
//double mn(double n, ...);
//using namespace std;
//
//int main()
//{
//  cout << mn(3, 5.1, 6.2, 1.08);
//}
//
//double mn(double n, ...) {
//  double res = 0;
//  double*p = &n + 1;
//  for (; n > 0; n--)
//    res += *(p++);
//  return res;
//}

#include <iostream>
double numb(double n, ...);
using namespace std;

int main()
{
  cout << numb(5, 4, 9, 6, 8, -9);
}

double numb(double n, ...) {
  double min = n;
  double*p = &n;
  for (int i = 1; i <= n; i++)
    if (min < *(p += 2))
        min = *p;
  return min;
}
