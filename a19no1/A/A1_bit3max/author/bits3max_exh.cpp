#include <iostream>
using namespace std;
int ones=0,zeroes=0;
bool init(int z,int o,char *a)
{int i=0;
 for (int j=0;j<o;j++)
 {a[i++]='1';
  if (j<o-1){a[i++]='0';
             z--;
             if (z<0) return false;
            }
 }
 for (int j=0;j<z;j++) a[i++]='0';
 a[i]=0;
 return true;
}
bool nextComb(int n,char *a)
{int i,c1=0;
 for (i=n-1;i>=0;i--) if (a[i]=='1')
 {c1++;
  if (a[i+1]=='0' && (i==n-2 || a[i+2]=='0'))
  {a[i]='0';
   a[i+1]='1';
   c1--;
   for (int j=i+3;j<n;j+=2)
   {if (c1){a[j]='1';c1--;}
    else a[j]='0';
    if (j<n-1) a[j+1]='0';
   }
   return true;
  }
 }
 return false;
}
void readData()
{char c;
 do
 {cin.get(c);
  if (c=='0') zeroes++;
  if (c=='1') ones++;
 }while(c!='\n');
}
bool checkStr(const char *s)
{char r=0;
 for (int i=0;s[i];i++) r=((r<<1)+(s[i]&1)) % 3;
 return !r;
}
int main()
{char s[2048];
 readData();
 if (!init(zeroes,ones,s)){cout<<"NO\n";return 0;}
 do
  if (checkStr(s)) {cout<<s<<endl; return 0;}
 while (nextComb(zeroes+ones,s));
 cout<<"NO\n";
 return 0;
}
