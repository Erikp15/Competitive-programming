#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    ll n,m;
    long double prob[5001];
    pair<ll,ll> kids[5001];
    vector<long double> all_leaves;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        ll a,b; cin>>a;
        if(a==-1){
            kids[i].first=a;
            kids[i].second=a;
            continue;
        }
        cin>>b;
        kids[i].first=a;
        kids[i].second=b;
    }
    prob[1]=1;
    for(ll i=1;i<=n;i++){
        if(kids[i].first==-1){
            all_leaves.push_back(prob[i]);
            cout<<i<<" "<<prob[i]<<endl;
        }
        prob[kids[i].first]=prob[i]*0.66666666;
        prob[kids[i].second]=prob[i]*0.33333334;
    }
    cout<<endl;
    sort(all_leaves.begin(),all_leaves.end());
    long double prob_of_red=0;
    //if(*all_leaves.end()==0){cout<<"ADnasdhas"<<endl;return 0;}
    for(ll i=0;i<all_leaves.size();i++){
        cout<<all_leaves[i]<<endl;
    }
    cout<<endl;
    for(ll i=all_leaves.size()-1;m>0;i--,m--){
        prob_of_red+=all_leaves[i];
        cout<<all_leaves[i]<<endl;
    }
    cout<<setprecision(8)<<fixed<<prob_of_red<<endl;
    return 0;
}
/*
15 4
2 3
4 5
6 7
8 9
10 11
12 13
14 15
-1
-1
-1
-1
-1
-1
-1
-1
0.74074074
*/
