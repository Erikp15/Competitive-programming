#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e6+10;

class ticket{
public:
    ll from,to,price;
};

bool comp(const ticket& a,const ticket& b){
    return a.from<b.from;
}

ll dp[Size];
ticket tickets[Size];

void solve(){
    ll a,b,n;
    cin>>n>>a>>b;
    for(ll i=0;i<n;i++){
        cin>>tickets[i].from>>tickets[i].to>>tickets[i].price;
        tickets[i].from=max(tickets[i].from-a,0);
        tickets[i].to=max(tickets[i].to-a,0);
    }
    sort(tickets,tickets+n,comp);
    b-=a;
    for(ll i=1;i<b;i++){

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
