#include <iostream>
#include <cmath>
using namespace std;
typedef unsigned long long card;
bool nextTripple(card P,card &a,card &b,card &c)
{do
 {b-=2;
  if (b<a)
  {a+=2;
   if (a>P/3) return false;
   b=((P-a)>>1);
   if (b&1) b--;
  }
  c=P-(a+b);
  if (c<b) {b=a;continue;}
  if (c<a+b) return true;
 }while(true);
}
bool isSqr(card n,card &sqr)
{sqr=(card)round(sqrt(n));
 return sqr*sqr==n;
}
bool Area(card a,card b,card c,card &S)
{card P=a+b+c;
 S=P*(P-(a<<1))*(P-(b<<1))*(P-(c<<1));
 if (S & 0xF) return false;
 S>>=4;
 return isSqr(S,S);
}
bool checkR(card a,card b,card c,card S)
{card t=a*b*c;
 if (t&3) return false;
 t>>=2;
 return !(t%S);
}
bool checkr(card a,card b,card c,card S)
{S<<=1;
 return !(S%(a+b+c));
}
int main()
{card P,a,b,S,c,N=0;
 cin>>P;
 if (P&3)
 {cout<<0<<endl;
  return 0;
 }
 a=2;b=2+((P-a)>>1);if (b&1)b--;N=0;
 while(nextTripple(P,a,b,c))
 {if (!Area(a,b,c,S))continue;
  if (checkR(a,b,c,S) && checkr(a,b,c,S))N++;
 }
 cout<<N<<endl;
 return 0;
}
