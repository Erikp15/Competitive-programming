#include <iostream>
#include <algorithm>

using namespace std;

int main ()
{
    int a[1005], s[1005];
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
      cin >> a[i];
    int k=min(n,3);
    for(int i=1; i<=k; i++)
      s[i]=a[i];
    for(int i=k+1; i<=n; i++)
      s[i]=min(min(s[i-1],s[i-2]),s[i-3])+a[i];
    int ans;
    if (n==1) ans=s[1];
    else if (n==2) ans=min(s[1],s[2]);
    else ans=min(min(s[n],s[n-1]),s[n-2]);
    cout << ans << endl;
}