#include<iostream>
using namespace std;

const int N=1000001;
int a[N], b[N], c[N];
int n;

int main()
{
  cin >> n;
  for(int i=0;i<n;i++) cin >> a[i];
  b[0]=a[0];
  for(int i=1;i<n;i++) b[i] = b[i-1]+a[i];
  c[n-1]=a[n-1];
  for(int i=n-2;i>=0;i--) c[i] = c[i+1]+a[i];

  int m=0;
  for(int i=0;i<n;i++)
   {
     for(int j=i+1; j<n; j++)
     {
       if(b[i]==c[j])
        if(m < i+n-j+1) m=i+n-j+1;
     }
   }
  cout << m << endl;
}
