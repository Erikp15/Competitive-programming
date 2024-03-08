/**
NOI2018-1
Group: A
Task: cla
Author: E.Vassilev
*/
#include <iostream>
int y,a,S,dir;
int main () {
  while (std::cin >> a)
    switch (dir=(dir+(a<0?(a=-a,3):1))%4) {
      case 0: S-=a*y; break;
      case 1: y+=a; break;
      case 2: S+=a*y; break;
      default: y-=a;
    }
  std::cout << (S<0?-S:S) << '\n';
  return 0;
}
// -100+40+40+20-20-20+40+40
