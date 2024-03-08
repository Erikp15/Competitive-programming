#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<pair<char,ll>> ans;

void calc(ll light,bool add){
    if(light<1)return;
    char t;
    add==1 ? t='+' : t='-';
    if(light==1){
        ans.push_back({t,light});
        return;
    }
    if(light==2){
        ans.push_back({t,1});
        ans.push_back({t,2});
        return;
    }
    calc(light-1,1);
    ans.push_back({t,light});
    calc(light-1,0);
}

void solve(ll n){
    calc(n-1,1);
    ans.push_back({'+',n});
    for(auto itr:ans){
        //cout<<itr.first<<itr.second<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n=20;
    while(n>=1){
        solve(n);
        ans.clear();
        n-=2;
    }
    return 0;
}
