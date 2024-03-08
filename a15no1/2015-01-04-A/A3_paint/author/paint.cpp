#include <iostream>
using namespace std;
//ќпредел€не на числото, което се намира
//на задаено ниво lev, с отместване над€сно от началото offs
long long No(int lev, long long offs)
{long long one=1;
 if (!lev) return 0;
 long long size=(one<<lev);//брой елементи на нивото
 long long start=size-1;//най-л€в елемент на нивото
 if (offs&1) start+=(size>>1);//начало на нечетните (броим от 0)
 return start+(offs>>1);   
}
//ќпредел€не на координатите (ниво и отместване) на зададено число
void Coord(long long n,int &lev,long long &offs)
{long long one=1;
 long long m=1;
 //определ€не на нивото
 lev=-1;
 while (n>=m-1){m<<=1;lev++;}
 
 long long size=(one<<lev);//брой възли на нивото
 long long start=size-1;//най-л€в елемент
 offs=0;//начално отместване
 //ако елементът е от втората половина:
 if (n>=start+(size>>1)){offs++;n-=(size>>1);}
 //нарастване на отместването
 offs+=((n-start)<<1);
}
void solve(long long N,long long &prev,long long &nextL,long long &nextR)
{int lev;
 long long offs;
 Coord(N,lev,offs);// оординати на подаденото число (ниво, отместване)
 prev=No(lev-1,offs>>1);//число, записано на бащата (едно ниво по-долу и половината от изместването)
 //числа, записани на синовете: едно ниво по-горе и двойно изместване (+1 за десни€ син)
 nextL=No(lev+1,2*offs);
 nextR=No(lev+1,2*offs+1);
}
int main()
{long long N,prev,nextL,nextR;
 cin>>N;
 solve(N,prev,nextL,nextR);
 cout<<prev<<endl;
 cout<<nextL<<' '<<nextR<<endl;
 return 0;
}