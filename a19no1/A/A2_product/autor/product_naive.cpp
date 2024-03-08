#include<iostream>
using namespace std;

const int N=1000001;
int a[N+1];
int n;


int main()
{
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];

    int s = 0;

	for(int i1=1;i1<=n;i1++)
    for(int i2=i1+1;i2<=n;i2++)
    {
      int s0 = (i2-i1)*min(a[i1],a[i2]);
      s = max(s,s0);
    }

	cout << s << endl;
}

