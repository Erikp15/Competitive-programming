#include <iostream>
using namespace std;
int ones=0,zeroes=0;
void readData()
{char c;
 do
 {cin.get(c);
  if (c=='0') zeroes++;
  if (c=='1') ones++;
 }while(c!='\n');
}
void solve()
{if (ones==1 ||
     zeroes<ones-1 ||
     (zeroes==ones-1 && (ones%3)))
 {cout<<"NO\n";return;}
 if (ones) cout<<'1';
 switch(ones%3)
 {case 0:{for (int i=1;i<ones;i++) {cout<<"01";zeroes--;}
          break;
         }
  case 1:{for (int i=1;i<ones-2;i++) {cout<<"01";zeroes--;}
          cout<<"00101";zeroes-=3;
          break;
         }
  case 2:{for (int i=1;i<ones-1;i++) {cout<<"01";zeroes--;}
          cout<<"001";zeroes-=2;
          break;
         }
 }
 for (int i=0;i<zeroes;i++)cout<<'0';
 cout<<endl;
}
int main()
{readData();
 solve();
 return 0;
}
