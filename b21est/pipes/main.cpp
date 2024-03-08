#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1001;
vector<pair<pair<ll,ll>,bool>> adj[Size];
double water_needed[Size],actual_water[Size];
ll n;

void sim(ll node){
    for(auto itr:adj[node]){
        actual_water[itr.first.first]=(actual_water[node]*(double)itr.first.second)/100.000;
        if(itr.second==true){
            if(actual_water[itr.first.first]>1){
                actual_water[itr.first.first]=actual_water[itr.first.first]*actual_water[itr.first.first];
            }
        }
        sim(itr.first.first);
    }
}

bool is_above(double water){
    actual_water[1]=water;
    sim(1);
    for(ll i=1;i<=n;i++){
        if(water_needed[i]!=-1){
            if(water_needed[i]>actual_water[i]){
                return false;
            }
        }
    }
    return true;
}

double find_ans(double l,double r){
    double water=(l+r)/2.000;
    bool curr_ans=is_above(water);
    if(!curr_ans){
        return find_ans(water+0.0001,r);
    }
    bool prev_ans=is_above(water-0.0001);
    if(curr_ans and !prev_ans){
        return water;
    }
    return find_ans(l,water);
}

void solve(){
    cin>>n;
    for(ll i=0;i<n-1;i++){
        ll from,to,percentige,modern;
        cin>>from>>to>>percentige>>modern;
        adj[from].push_back({{to,percentige},modern});
    }
    for(ll i=1;i<=n;i++){
        cin>>water_needed[i];
    }
    double ans=find_ans(0,2000000000);
    cout<<fixed<<setprecision(3)<<ans<<"\n";
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
