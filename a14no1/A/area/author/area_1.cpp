#include <iostream>
#include <iomanip> 
#include <cmath>
using namespace std;
long double minArea(long double a,long double b)
{long double t=0.5*fabsl(b-a);
 long double h=sqrtl(a*a-t*t);
 return 0.5*(a+b)*h;
}
int main()
{long double a,b,r;
 cin>>a>>b;
 if (b>=3*a) r=0;
 else r=minArea(a,b);
 cout<<fixed<<setprecision(2)<<r<<endl;
 return 0;
}
