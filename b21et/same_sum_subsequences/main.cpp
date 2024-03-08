#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e3+1;
ll a[Size],b[Size];
pair<bool,int> start1[Size*Size],start2[Size*Size];
pair<bool,int> dp1[Size*Size],dp2[Size*Size];
vector<ll> ans1,ans2;

void solve(){
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        start1[a[i]].first=true;
        start1[a[i]].second=i;
    }
    ll m;
    cin>>m;
    for(ll i=0;i<m;i++){
        cin>>b[i];
        start2[b[i]].first=true;
        start2[b[i]].second=i;
    }
    for(ll i=1;i<=n;i++){
        if(start1[i].first and start2[i].first){
            cout<<1<<endl<<start1[i].second<<endl<<1<<endl<<start2[i].second<<endl;
            return;
        }
    }
    dp1[0].first=true;
    dp1[0].second=-1;
    dp2[0].first=true;
    dp2[0].second=-1;
    for(ll i=0;i<n;i++){
        for(ll j=m*m;j>=0;j--){
            if(dp1[j].first){
                if(dp1[j+a[i]].first==false){
                    dp1[j+a[i]].first=true;
                    dp1[j+a[i]].second=i;
                }
            }
        }
    }
    for(ll i=0;i<m;i++){
        for(ll j=n*n;j>=0;j--){
            if(dp2[j].first){
                if(dp2[j+b[i]].first==false){
                    dp2[j+b[i]].first=true;
                    dp2[j+b[i]].second=i;
                }
            }
        }
    }
    ll finish=min(n*n,m*m);
    for(ll j=1;j<finish;j++){
        if(dp1[j].first and dp2[j].first){
            for(ll i=j;dp1[i].second!=-1;i=i-a[dp1[i].second]){
                ans1.push_back(dp1[i].second);
            }
            for(ll i=j;dp2[i].second!=-1;i=i-b[dp2[i].second]){
                ans2.push_back(dp2[i].second);
            }
            cout<<ans1.size()<<endl;
            for(auto itr:ans1){
                cout<<itr<<" ";
            }
            cout<<endl<<ans2.size()<<endl;
            for(auto itr:ans2){
                cout<<itr<<" ";
            }
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}
