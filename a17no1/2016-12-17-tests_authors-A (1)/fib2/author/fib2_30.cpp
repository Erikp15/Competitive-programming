#include <iostream>
#include <cstring>
using namespace std;
char digChar(int d)
{if (d<10) return d+'0';
 return d-10+'A';
}
int DigVal(char d)
{if (d<='9') return d-'0';
 return d-'A'+10;
}
char *decToP(unsigned long long a,int radix,int bufSize, char *buf)
{int i=bufSize-1;
 buf[i--]=0;
 do
 {buf[i--]=digChar(a%radix);
  a/=radix;   
 }while(a);
 return &buf[i+1];
}
unsigned long long PToDec(int radix, const char *buf)
{unsigned long long s=0;
 for (int i=0;buf[i];i++) s=radix*s+DigVal(buf[i]);
 return s;
}

char *makeFibMod(int radix,long long n,const char *s1,const char *s2,int sz,char *b)
{int f1,f2,f,p,mod=radix*radix;
 p=strlen(s1);
 if (p==1) f1=PToDec(radix,s1);
 else f1=PToDec(radix,&s1[p-2]);
 p=strlen(s2);
 if (p==1) f2=PToDec(radix,s2);
 else f2=PToDec(radix,&s2[p-2]);
 f=(n==1)?f1:f2;
 for (long long i=3;i<=n;i++)
 {f=(f1+f2)%mod;
  f1=f2;
  f2=f;
 }
 return decToP(f,radix,sz,b);
}
void sol(int radix,unsigned long long n,const char *s1,const char *s2)
{const int sz=1024;
 char b[sz],*r;
 r=makeFibMod(radix,n,s1,s2,sz,b);
 if (!*(r+1)) cout<<0<<endl;
 else cout<<b[sz-3]<<endl;
}
int main()
{ int radix;
  unsigned long long n;
  char f1[128],f2[128];
  cin>>radix>>n>>f1>>f2;
  sol(radix,n,f1,f2);
  return 0;
}