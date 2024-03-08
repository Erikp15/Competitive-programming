#include <iostream>
#include <iomanip> 
#include <cmath>
using namespace std;
const long double M_PI=4*atanl(1);
long double minA(long double a, long double b,long double &M,long double start,long double end,long double step)
{long double alpha,m,p,al,c;
 alpha=start;
 al=alpha;
 do
 {alpha-=step;
  c=sqrtl(b*b+a*a-2*a*b*cosl(alpha));
  p=a+0.5*c;
  m=0.5*a*b*sinl(alpha)+(p-a)*sqrtl(p*(p-c));
  if (m>M) {M=m;al=alpha;}     
 }while (alpha>=end);
 return al;
}
long double minArea(long double a,long double b)
{long double alpha,s,m,cosa,M,p,e,st;
 p=a+0.5*(b+a);
 if (a<b)
 {cosa=(b*b-3*a*a)/(2*a*b);
  s=acosl(cosa);
  e=acosl((b-a)/(2*a));
  M=sqrtl(p*(p-a)*(p-2*a)*(p-b));
 }
 else 
 {s=M_PI;
  e=0.5*M_PI-acosl((a-b)/(2*a));
  M=(p-a)*sqrtl(p*(p-a-b));
 }
 st=(s-e)/10;
 do
 {m=M;
  alpha=minA(a,b,M,s,e,st);
  if (fabsl(M-m)<0.01) break;
  s=alpha+st;e=alpha-st;st/=10;
 }while(true);
 return M;
}
int main()
{long double a,b,r;
 cin>>a>>b;
 if (b>=3*a) r=0;
 else r=minArea(a,b);
 cout<<fixed<<setprecision(2)<<r<<endl;
 return 0;
}
