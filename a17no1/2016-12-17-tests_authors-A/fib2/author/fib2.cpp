#include <iostream>
#include <cstring>
using namespace std;
char digChar(int d)//Превръща "цифра" в съответен символ
{if (d<10) return d+'0';
 return d-10+'A';
}
int DigVal(char d)//Връща числовата стойност на символ
{if (d<='9') return d-'0';
 return d-'A'+10;
}
int atoiMod(const char *a,int mod)//Намира остатъка на дълго число в
                                  //десетичен запис, зададено като низ, 
                                  //по задаен модул
{unsigned long long r=0;
 while (*a>='0' && *a<='9') r=(10ULL*r+*a++-'0')%mod;
 return r;
}
int cycle(int f1,int f2,int radix)//Намира цикъла за последните
                                  //две цифри на редицата по зададени
                                  //първи и втори член и основа на
                                  //бройната система
{int i,mod,t1,t2,t;
 mod=radix*radix;
 f1%=mod;
 f2%=mod;
 t1=f1;t2=f2;
 for (i=3;true;i++)
 {t=(t1+t2)%mod;
  t1=t2;
  t2=t;
  if (t1==f1 && t2==f2) return i-2;
 }  
}
//Решение на задачата по зададени данни
void sol(int p,const char *n,const char *s1,const char *s2)
{int t,f1,f2,d,m,r;
 //определяне на стойностите на f1 и f2
 t=strlen(s1);
 if (t==1) f1=DigVal(*s1);
 else f1=p*DigVal(s1[t-2])+DigVal(s1[t-1]);   
 t=strlen(s2);
 if (t==1) f2=DigVal(*s2);
 else f2=p*DigVal(s2[t-2])+DigVal(s2[t-1]);
 //намиране на цикъла за последните две цифри
 d=cycle(f1,f2,p);
 //определяне на необходимия член на редицата
 m=atoiMod(n,d);
 if (!m) m=d;
 //намиране и извеждане на предпослената цифра
 //в бройна система с основа radix
 t=p*p;
 switch(m)
 {case 1:{r=f1;break;}
  case 2:{r=f2;break;}   
  default:for (int i=3;i<=m;i++)
          {r=(f1+f2)%t;
           f1=f2;
           f2=r;   
          }
 }
 cout<<digChar(r/p)<<endl;
}
int main()
{int radix;
 char f1[128],f2[128],n[128];
 cin>>radix>>n>>f1>>f2;
 sol(radix,n,f1,f2);
 return 0;
}
