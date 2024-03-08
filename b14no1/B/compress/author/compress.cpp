#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a, n;
    cin>>n>>a;
    long long c[60];
    c[0] = 1;
    for(int i=1; i<=n; i++)
    {
        int m = min(i,a); 
        c[i] = 0;
        for(int j=1; j<=m; j++)
          c[i]+=c[i-j];
    }
    cout << c[n] << endl;
    return 0;
}
 
 
