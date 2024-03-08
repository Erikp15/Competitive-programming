#include<iostream>
using namespace std;
int main () {
    long long int ans=0;
    int n,i,j,phi,num;
    cin >> n ;
    for (i=1; i<=n; i++) {
        phi=i; num=i;
        for (j=2; j*j<=i; j++) {
            if (num%j==0) {
               phi=(phi/j)*(j-1);
               for (;;) {
                   num/=j;
                   if (num%j!=0) break;
                   }
               }
            }
        if (num!=1) phi=(phi/num)*(num-1);
        ans+=phi;
        }
    cout << ans ;
    cout << endl ;
    return 0;
}
