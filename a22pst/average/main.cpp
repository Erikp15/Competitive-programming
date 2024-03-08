#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll Size=3e2+1;

ll pre[Size],arr[Size];
pair<ld,ll> dp[Size];

void b_search(ll l, ll r, ll i){
    if(l>r)
        return;
    ll mid=(l+r)/2;
    if(dp[mid].first==0){
        b_search(l,mid,i);
    }
    ld n1=dp[mid].first*mid+pre[i]-pre[dp[mid].second];
    ld n2=(i-dp[mid].second+mid);
    ld curr_avg=n1/n2;
    ld prev_avg=dp[i-dp[mid].second+mid].first;
    if(l==r){
        if(curr_avg>prev_avg){
            dp[i-dp[l].second+l].first=curr_avg;
            dp[i-dp[l].second+l].second=i;
        }
    }else{
        if(curr_avg>prev_avg){
            dp[i-dp[l].second+l].first=curr_avg;
            dp[i-dp[l].second+l].second=i;
            b_search(mid+1,r,i);
        }else{
            b_search(l,mid,i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,k;
    cin>>n>>k;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    pre[0]=arr[0];
    for(ll i=1;i<n;i++){
        pre[i]=pre[i-1]+arr[i];
    }
    dp[1].first=pre[0];
    for(ll i=1;i<n;i++){
        b_search(1,n,i);
    }
    ld ans=0;
    for(ll i=k;i<=n;i++){
        ans=max(ans,dp[i].first);
    }
    cout<<fixed<<setprecision(6)<<ans<<endl;
    return 0;
}
/*
4 1
1 2 3 4

4 2
2 4 3 4

6 3
7 1 2 1 3 6
*/
