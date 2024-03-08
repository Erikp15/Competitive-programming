#include <iostream>
using namespace std;
int a,b,m;
char st[256];
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
void makeSt()
{int n;
 initSt(1,a+b);
 for (n=1;n<=a+b;n++) playDyn(1,n);
 st[0]=st[a+b];
}
void Solve(istream &is=cin)
{int n,r;
 char buf[1024];
 makeSt();
 for (int i=0;i<m;i++)
 {is>>buf;
  r=0;
  for (int j=0;buf[j];j++) r=(10*r+buf[j]-'0')%(a+b);
  cout<<(st[r]^1)<<endl;
 }
}
int main()
{cin>>a>>b>>m;
 Solve();
 return 0;
}
