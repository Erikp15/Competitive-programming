#include <iostream>
using namespace std;
int a,b,m;
int play(int p,int n)
{if (n<a && n<b) return p^3;
 if (n==a||n==b) return p;
 if (n>=a)
 {if (play(p^3,n-a)==p) return p;
 }
 if (n>=b)
 {if (play(p^3,n-b)==p) return p;
 }
 return p^3;
}
void noDyn(istream &is=cin)
{int n;
 for (int i=0;i<m;i++)
 {is>>n;
  cout<<play(1,n)<<endl;
 }
}
int main()
{cin>>a>>b>>m;
 noDyn();
 return 0;
}
