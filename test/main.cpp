#include <iostream>

using namespace std;

typedef long long ll;

    ll a[1000001];

int main(){
    ll n,sum=0;
    cin>>n;
    a[0]=1;
    for(ll i=1;i<n;i++){
        a[i]=a[i-1]+sum;
        sum+=a[i-1]+a[i-1];
    }
    cout << a[n-1] << endl;
    return 0;
}
