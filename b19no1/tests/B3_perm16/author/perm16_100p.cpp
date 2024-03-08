#include<iostream>
using namespace std;
const long long int mod=1e9+7;
long long int ans=0;
int main () {
    long long int fact;
    int n,i,j,h,k,num;
    cin >> n ;
    if (n==1) cout << 0 ;
    else if (n==2) cout << 0 ;
    else if (n==3) cout << 0 ;
    else {
        fact=1;
        for (i=2; i<=n-4; i++) {
            fact*=i; fact%=mod;
            }
        for (i=1; i<=n; i++) {
            for (j=1; j<=n; j++) {
                if (i==j) continue;
                for (h=1; h<=n; h++) {
                    if ((i==h)||(j==h)) continue;
                    for (k=1; k<=n; k++) {
                        if ((i==k)||(j==k)||(h==k)) continue;
                        num=i;
                        if (j<10) num*=10; else num*=100;
                        num+=j;
                        if (h<10) num*=10; else num*=100;
                        num+=h;
                        if (k<10) num*=10; else num*=100;
                        num+=k;
                        if (num%16==0) ans+=fact;
                        }
                    ans%=mod;
                    }
                }
            }
        cout << ans ;
        }
    cout << endl ;
    return 0;
}
