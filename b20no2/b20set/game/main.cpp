#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=2e4+1;
ll a[Size];
ll n;

ll find_split(ll l,ll r,ll sum,ll depth){
    ll first_sum=0,second_sum=sum;
    if(l==r)return depth;
    for(ll i=l;i<=r;i++){
        first_sum+=a[i];
        second_sum-=a[i];
        if(first_sum==second_sum){
            ll left_depth=find_split(l,i,first_sum,depth+1);
            ll right_depth=find_split(i+1,r,second_sum,depth+1);
            return max(left_depth,right_depth);
        }
    }
    return depth;
}

void solve(){
    cin>>n;
    ll total_sum=0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        total_sum+=a[i];
    }
    cout<<find_split(0,n-1,total_sum,0)<<"\n";
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
