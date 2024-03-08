#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{double a,b,r;
 cin>>a>>b;
 if (b>=3*a) r=0;
 else r=0.25*(a+b)*sqrt((a+b)*(3.0*a-b));
 cout<<fixed<<setprecision(2)<<r<<endl;
 return 0;
}
