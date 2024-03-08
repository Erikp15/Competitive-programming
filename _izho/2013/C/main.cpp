#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=3e5+10;
pair<ll,ll> a[Size];
ll ansm[Size],anss[Size];

bool comp(const pair<ll,ll>& A,const pair<ll,ll>& B){
    return (A.first-A.second)<(B.first-B.second);
}

void solve(){
    ll n,m,s;
    cin>>n>>m>>s;
    for(ll i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a+1,a+n+1,comp);
    priority_queue<ll,vector<ll>,greater<ll>> to_remove;
    ll ans_for_s=0;
    for(ll i=1;i<=n;i++){
        to_remove.push(a[i].second);
        ans_for_s+=a[i].second;
        if(to_remove.size()>s){
            ans_for_s-=to_remove.top();
            to_remove.pop();
        }
        anss[i]=ans_for_s;
    }
    while(!to_remove.empty()){
        to_remove.pop();
    }
    ll ans_for_m=0;
    for(ll i=n;i>0;i--){
        to_remove.push(a[i].first);
        ans_for_m+=a[i].first;
        if(to_remove.size()>m){
            ans_for_m-=to_remove.top();
            to_remove.pop();
        }
        ansm[i]=ans_for_m;
    }
    ll ans=0;
    for(ll i=0;i<=n;i++){
        ans=max(ans,anss[i]+ansm[i+1]);
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}
