#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=51;
    ll a[Size];

    void solve(){
        ll n;
        cin>>n;
        ll sum=0;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        double ans;
        sum%n==0 ? ans=sum/n : ans=(sum/n)+1;
        if(ans>1){
            cout<<sum-n<<"\n";
            return;
        }else{
            if(sum/n==1){
                cout<<0<<"\n";
                return;
            }
            cout<<1<<"\n";
        }
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
1
3
1 2 3
*/
