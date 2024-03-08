#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=100001;
    ll a[Size],dp[Size][10];

int main(){
    ll n,d,p=1;
    cin>>n>>d;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        p*=a[i]%10;
        p%=10;
    }
    if(p==d){
        cout<<
    }
    cout << "Hello world!" << endl;
    return 0;
}
