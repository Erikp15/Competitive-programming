#include <iostream>
using namespace std;
int a,b,m;
char st[1000001];
int playDyn(int p,int n)
{if (st[n]>=0) return p^st[n];
 if (n<a && n<b) {st[n]=3;return p^3;}
 if (n==a||n==b) {st[n]=0;return p;}
 if (n>=a && playDyn(p^3,n-a)==p) {st[n]=0;return p;}
 if (n>=b && playDyn(p^3,n-b)==p) {st[n]=0;return p;}
 st[n]=3;
 return p^3;
}
void initSt(int start,int fin)
{for (int i=start;i<=fin;i++) st[i]=-1;
}
void Dyn(istream &is=cin)
{int n,hi=0;
 for (int i=0;i<m;i++)
 {is>>n;
  if (n>hi){initSt(hi+1,n);hi=n;}
  cout<<playDyn(1,n)<<endl;
 }
}
int main()
{cin>>a>>b>>m;
 Dyn();
 return 0;
}
