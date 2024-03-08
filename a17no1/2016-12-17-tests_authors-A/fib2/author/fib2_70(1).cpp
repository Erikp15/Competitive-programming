#include <iostream>
#include <cstring>
using namespace std;
typedef int Matrix[2][2];
const Matrix E={{1,1},{1,0}};
char digChar(int d)
{if (d<10) return d+'0';
 return d-10+'A';
}
int DigVal(char d)
{if (d<='9') return d-'0';
 return d-'A'+10;
}
void mul(const Matrix *a,const Matrix *b,Matrix *c,int mod)
{for (int i=0;i<2;i++)
  for (int j=0;j<2;j++)
  {int s=0;
   for (int k=0;k<2;k++) s+=(*a)[i][k]*(*b)[k][j];
   (*c)[i][j]=s%mod;
  }
}
void MatrixCopy(Matrix *a,const Matrix *b)
{for (int i=0;i<2;i++)
  for (int j=0;j<2;j++) (*a)[i][j]=(*b)[i][j];
}
void deg(unsigned long long n,int mod,const Matrix *E,Matrix *r)
{if (n==1){MatrixCopy(r,E);return;}
 Matrix t;
 if (n&1) {deg(n-1,mod,E,&t);mul(&t,E,r,mod);}
 else {deg(n>>1,mod,E,&t);mul(&t,&t,r,mod);}
}
void sol(int radix,unsigned long long n,const char *s1,const char *s2)
{int mod=radix*radix,p,f1,f2,f3;
 Matrix F,R,T;
 p=strlen(s1);
 if (p==1){if (n==1){cout<<0<<endl;return;}
           f1=DigVal(*s1);
          }
 else {if (n==1){cout<<s1[p-2]<<endl;return;}
       f1=radix*DigVal(s1[p-2])+DigVal(s1[p-1]);
      }
 p=strlen(s2);
 if (p==1){if (n==2){cout<<0<<endl;return;}
           f2=DigVal(*s2);
          }
 else {if (n==2){cout<<s2[p-2]<<endl;return;}
       f2=radix*DigVal(s2[p-2])+DigVal(s2[p-1]);
      }
 f3=(f1+f2)%mod;
 if (n==3){cout<<digChar(f3/radix)<<endl;return;}
 MatrixCopy(&R,&E);
 deg(n-3,mod,&E,&R);
 F[0][0]=f3;F[0][1]=F[1][0]=f2;F[1][1]=f1;
 mul(&F,&R,&T,mod);
 cout<<digChar(T[0][0]/radix)<<endl;
}
int main()
{ int radix;
  unsigned long long n;
  char f1[128],f2[128];
  cin>>radix>>n>>f1>>f2;
  sol(radix,n,f1,f2);
  return 0;
}