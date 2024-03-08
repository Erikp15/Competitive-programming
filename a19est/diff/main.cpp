#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=5e3+1;

set<ll> S;

void solve(){
    ll q;
    cin>>q;
    for(ll i=0;i<q;i++){
        char type;
        cin>>type;
        if(type=='I'){
            ll num;
            cin>>num;
            S.insert(num);
        }
        if(type=='D'){
            ll num;
            cin>>num;
            S.erase(num);
        }
        if(type=='X'){
            ll from,to;
            cin>>from>>to;
            ll index=0,from_v=0,to_v=0;
            for(auto itr:S){
                if(index==from)from_v=itr;
                if(index==to)to_v=itr;
                index++;
            }
            cout<<to_v-from_v<<"\n";
        }
        if(type=='N'){
            ll from,to;
            cin>>from>>to;
            ll index=0,ans=1e18;
            for(auto itr=S.begin();itr!=S.end();itr++){
                if(index==from){
                    for(;index<to;){
                        ans=min(ans,abs(*itr-*(++itr)));
                        index++;
                    }
                }
                index++;
            }
            cout<<ans<<"\n";
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
