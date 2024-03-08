#include <iostream>
#include <cstring>
using namespace std;
char cons[32],vow[8];//съгласни и гласни в "азбучен ред"
char syllable[128][4];//срички в "азбучен ред"
long N;
int c,v,p;//брой съгласни, брой гласни, брой срички
void inp()
{char a[32],s[8];
 cin>>a>>s>>N;
//отделяне на гласни и съгласни в "азбучен ред"
 c=v=0;
 for (int i=0;a[i];i++)
  if (strchr(s,a[i])) vow[v++]=a[i];
  else cons[c++]=a[i];
//генериране на сричките
 p=0;
 for (int i=0;i<c;i++)
  for (int j=0;j<v;j++) 
 {syllable[p][0]=cons[i];
  syllable[p][1]=vow[j];
  syllable[p++][2]=0;
 }
}
int main()
{ long long t,s,d;
  char num[32];//"цифрите" не надвишават 120 по стойност (p<=120)
               //и 32 по брой (N<2^32)
  inp();
//Намиране на броя p-ични цифри и числото, 
//което трябва да се представи
  t=0;s=0;d=1;
  while (s<N) {t++;d*=p;s+=d;}
  s-=d;
  s=N-1-s;
//Представяне на s в t цифри на бройна система с основа p
  for (int i=t-1;i>=0;i--)
  {num[i]=s%p;
   s/=p;
  }
//Извеждане на резултата
  for (int i=0;i<t;i++) cout<<syllable[(int)num[i]];
  cout<<endl;
  return 0;
}