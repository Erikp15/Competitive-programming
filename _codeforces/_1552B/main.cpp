#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    ll r[50001][5];

    void solve(){
        ll n;
        cin>>n;
        ll best_i=0;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<5;j++){
                cin>>r[i][j];
            }
        }
        for(ll i=1;i<n;i++){
            ll good=0;
            for(ll j=0;j<5;j++){
                if(r[i][j]<r[best_i][j])good++;
            }
            if(good>=3){
                best_i=i;
            }
        }
        for(ll i=0;i<n;i++){
            ll good=0;
            if(i==best_i)continue;
            for(ll j=0;j<5;j++){
                if(r[i][j]>r[best_i][j])good++;
            }
            if(good<3){
                cout<<-1<<"\n";
                return;
            }
        }
        cout<<best_i+1<<"\n";
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
