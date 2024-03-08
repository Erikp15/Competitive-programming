#include<iostream>
#include<set>
using namespace std;


const int N=1000;
int a[N+1];
int n;

set<int> s;


int main()
{
 cin >> n;
 for(int i=0;i<n;i++) cin >> a[i];

 for(int i1=0;i1<n;i1++)
 for(int i2=0;i2<n;i2++)
 for(int i3=0;i3<n;i3++)
  if(a[i1]!=a[i2] && a[i2] != a[i3] && a[i3] != a[i1])
  if(a[i1]<a[i2]+a[i3] && a[i2]<a[i1]+a[i3] && a[i3]<a[i1]+a[i2])
  {

     int a1=a[i1];
     int a2=a[i2];
     int a3=a[i3];

     if(a1>a2) swap(a1,a2);
     if(a2>a3) swap(a2,a3);
     if(a1>a2) swap(a1,a2);

     s.insert(a1+1000*a2+1000000*a3);
  }
 cout << s.size() << endl;
}
