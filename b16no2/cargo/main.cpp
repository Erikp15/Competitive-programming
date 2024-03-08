#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e6+1;

vector<pair<ll,ll>> querys;
set<pair<ll,ll>> to_process;

void solve(){
    ll n,m,p;
    cin>>n>>m>>p;
    p/=2;
    for(ll a,b;m--;){
        cin>>a>>b;
        a--,b--;
        querys.push_back({a,b});
    }
    sort(querys.begin(),querys.end());
    for(vector<pair<ll,ll>>::iterator itr:querys){
        to_process.insert(*itr);
        ll taken=0,curr_day=*to_process.begin().first;
        while(!to_process.empty() and taken<p){
            ll curr_query=*to_process.begin();
            if(curr_query.second)
        }
    }
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
