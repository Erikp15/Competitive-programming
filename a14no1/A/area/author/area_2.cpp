#include <iostream>
#include <iomanip> 
#include <cmath>
using namespace std;
long double minArea(long double a,long double b)
{long double p=a+(a+b)/2;
 return (p-a)*sqrtl((p-a)*(p-b));
}
int main()
{long double a,b,r;
 cin>>a>>b;
 if (b>=3*a) r=0;
 else r=minArea(a,b);
 cout<<fixed<<setprecision(2)<<r<<endl;
 return 0;
}
