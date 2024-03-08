#include<iostream>
#include<algorithm>
using namespace std;
int main () {
    int n,i,j,ans=1;
    cin >> n ;
    for (i=2; i<=n; i++) {
        for (j=1; j<i; j++) {
            if (__gcd(i,j)==1) ans++;
            }
        }
    cout << ans ;
    cout << endl ;
    return 0;
}
