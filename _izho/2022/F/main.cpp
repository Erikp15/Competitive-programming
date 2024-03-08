#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e6+10;

ll ori_a[Size],wait[Size],ans[Size];
pair<ll,ll> a[Size];
bool visited[Size];

void l(ll curr_node,ll max_v){
    if(ori_a[curr_node]>=ori_a[curr_node+1]){
        ans[curr_node]=min(ans[curr_node],ans[curr_node+1]+1);
    }else{
        ans[curr_node]=min(ans[curr_node],max(max_v-ori_a[curr_node],ans[curr_node+1]+1));
    }
    if(curr_node==0)
        return;
    if(ori_a[curr_node-1]!=max_v){
        l(curr_node-1,max_v);
    }
}

void r(ll curr_node,ll max_v,ll n){
    if(ori_a[curr_node]>=ori_a[curr_node-1]){
        ans[curr_node]=min(ans[curr_node],ans[curr_node-1]+1);
    }else{
        ans[curr_node]=min(ans[curr_node],max(max_v-ori_a[curr_node],ans[curr_node-1]+1));
    }
    if(curr_node==n-1)
        return;
    if(ori_a[curr_node+1]!=max_v){
        r(curr_node+1,max_v,n);
    }
}

void solve(){
    ll n,q;
    cin>>n>>q;
    for(ll i=0;i<n;i++){
        cin>>a[i].first;
        ori_a[i]=a[i].first;
        a[i].second=i;
        ans[i]=1e18;
    }
    sort(a,a+n);
    reverse(a,a+n);
    ll max_v=a[0].first;
    for(ll i=0;a[i].first==max_v and i<n;i++){
        ans[a[i].second]=0;
        if(a[i].second-1>=0 and ori_a[a[i].second-1]!=max_v ){
            l(a[i].second-1,max_v);
        }
        if(a[i].second+1<n and ori_a[a[i].second+1]!=max_v){
            r(a[i].second+1,max_v,n);
        }
    }
    while(q--){
        ll x,t;
        cin>>x>>t;
        x--;
        ll delay=max(ans[x]-max_v+ori_a[x],(ll)0);
        cout<<max(ori_a[x]+t-delay,ori_a[x])<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    while(t--)
        solve();
    return 0;
}
/*
5 4
1 3 2 5 1

9 10
7 6 1 7 1 4 5 1 7
*/
