#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=3e5+1;
ll rounds[Size][4];
ll even[Size],odd[Size];
ll dp[2][Size];
vector<ll> ans;
ll n,m,k;

void reset(){
    for(ll i=0;i<m;i++){
        even[i]=0;
        odd[i]=0;
    }
}

bool get_ans(ll curr_marb,ll depth){
    if(depth==m){
        return 1;
    }
    if(dp[0][depth]<=curr_marb){
        ans.push_back(0);
        return get_ans(curr_marb-odd[depth],depth+1);
    }
    if(dp[1][depth]<=curr_marb){
        ans.push_back(1);
        return get_ans(curr_marb-even[depth],depth+1);
    }
    return 0;
}

void solve(){
    cin>>n>>m>>k;
    reset();
    for(ll i=0;i<m;i++){
        for(ll j=0;j<k;j++){
            cin>>rounds[i][j];
            if(rounds[i][j]%2==0){
                even[i]=max(even[i],rounds[i][j]);
            }else{
                odd[i]=max(odd[i],rounds[i][j]);
            }
        }
        if(even[i]==0){
            even[i]=-1e18;
            for(ll j=0;j<k;j++){
                even[i]=max(even[i],-rounds[i][j]);
            }
        }
        if(odd[i]==0){
            odd[i]=-1e18;
            for(ll j=0;j<k;j++){
                odd[i]=max(odd[i],-rounds[i][j]);
            }
        }
    }
    dp[0][m-1]=max((ll)1,odd[m-1]+1);
    dp[1][m-1]=max((ll)1,even[m-1]+1);
    for(ll i=m-2;i>=0;i--){
        ll best_prev=min(dp[0][i+1],dp[1][i+1]);
        dp[0][i]=max(best_prev+odd[i],(ll)1);
        dp[1][i]=max(best_prev+even[i],(ll)1);
    }
    if(!get_ans(n,0)){
        cout<<-1<<endl;
    }else{
        for(ll i=0;i<ans.size();i++){
            if(ans[i]==0){
                cout<<"Even";
            }else{
                cout<<"Odd";
            }
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    ans.clear();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
2
10 3 2
2 5
1 3
1 3
10 3 2
2 5
1 3
1 3
*/
