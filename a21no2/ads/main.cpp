#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=6e5+10;

vector<pair<ll,ll>> a;
pair<ll,ll> pos_count[Size];
ll suf[Size];

void solve(){
    ll n,m;
    cin>>n>>m;
    for(ll i=0,from,to;i<n;i++){
        cin>>from>>to;
        if(from+m>to)continue;
        a.push_back({from,1});
        a.push_back({to-m,-1});
    }
    sort(a.begin(),a.end());
    ll s=0;
    for(ll i=0,c=0,rem=0;i<a.size();i++){
        if(a[i].second>0){
            c++;
        }
        if(a[i].second<0){
            rem++;
        }
        if(a[i].first<a[i+1].first or i==a.size()-1){
            pos_count[s++]={a[i].first,c};
            c-=rem;
            rem=0;
        }
    }
    ll best=0;
    for(ll i=s;i>=0;i--){
        best=max(best,pos_count[i].second);
        suf[i]=best;
    }
    ll ans=0,j=0;
    for(ll i=0;i<s;i++){
        while(j<s and pos_count[j].first<pos_count[i].first+m)j++;
        if(j==s)break;
        ans=max(ans,pos_count[i].second+suf[j]);
    }
    cout<<max(ans,best)<<endl;
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
/*
4 5
2 7
2 7
2 7
2 7
*/
