#include<iostream>
using namespace std;
int phi[1000001];
int main () {
    long long int ans=1;
    int n,i,j;
    cin >> n ;
    for (i=1; i<=n; i++) {
        phi[i]=i;
        }
    for (i=2; i<=n; i++) {
        if (phi[i]==i) {
           for (j=i; j<=n; j+=i) {
               phi[j]/=i; phi[j]*=(i-1);
               }
           }
        ans+=phi[i];
        }
    cout << ans ;
    cout << endl ;
    return 0;
}
