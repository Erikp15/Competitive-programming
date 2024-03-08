#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=5e4+10;

ll colored=0;
ll color[Size];
ll a[Size];
ll link[Size];
vector<ll> buckets[51];
ll answer=1e18;

void solve(){
    ll n,k;
    cin>>n>>k;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(ll i=1;i<n;i++){
        link[i]=i-1;
    }
    if(k==1){
        ll ans=1e18;
        for(ll i=1;i<n;i++){
            ans=min(ans,a[i]^a[i-1]);
        }
        cout<<ans<<endl;
        for(ll i=0;i<n;i++){
            cout<<1<<" ";
        }
        cout<<endl;
        return;
    }
    while(colored<n-1){
        ll ans=1e18,ans_pos=0;
        for(ll i=1;i<n;i++){
            if(link[i]==0 or color[i]){
                continue;
            }
            if(ans>a[i]^a[link[i]]){
                ans=a[i]^a[link[i]];
                ans_pos=i;
            }
        }
        colored+=2;
        link[ans_pos+1]=link[link[ans_pos]];
        ll cost1[51],cost2[51];
        for(ll i=0;i<k;i++){
            cost1[i]=1e18;
            if(buckets[i].size()==0){
                cost1[i]=0;
            }
            for(ll j=0;j<buckets[i].size();j++){
                if(cost1[i]>a[ans_pos]^buckets[i][j]){
                    cost1[i]=a[ans_pos]^buckets[i][j];
                }
            }
            cost2[i]=1e18;
            if(buckets[i].size()==0){
                cost2[i]=0;
            }
            for(ll j=0;j<buckets[i].size();j++){
                if(cost2[i]>a[ans_pos-1]^buckets[i][j]){
                    cost2[i]=a[ans_pos-1]^buckets[i][j];
                }
            }
        }
        ll choice=1e18;
        pair<ll,ll> id;
        for(ll i=0;i<k;i++){
            for(ll j=0;j<i;j++){
                if(choice>min(cost1[i],cost2[j])){
                    choice=min(cost1[i],cost2[j]);
                    id.first=i;
                    id.second=j;
                }
            }
            for(ll j=i+1;j<k;j++){
                if(choice>min(cost1[i],cost2[j])){
                    choice=min(cost1[i],cost2[j]);
                    id.first=i;
                    id.second=j;
                }
            }
        }
        color[ans_pos]=id.first+1;
        color[ans_pos-1]=id.second+1;
        buckets[id.first].push_back(a[ans_pos]);
        buckets[id.second].push_back(a[ans_pos-1]);
    }
    if(colored==n-1){
        ll not_colored=0;
        for(ll i=0;i<n;i++){
            if(!color[i]){
                not_colored=i;
                break;
            }
        }
        ll min_v=1e18, min_b=0;
        for(ll i=0;i<k;i++){
            if(buckets[i].size()==0){
                min_b=i;
                break;
            }
            for(ll j=0;j<buckets[i].size();j++){
                if(min_v>a[not_colored]^buckets[i][j]){
                    min_v=a[not_colored]^buckets[i][j];
                    min_b=i;
                }
            }
        }
        buckets[min_b].push_back(a[not_colored]);
        color[not_colored]=min_b+1;
    }
    for(ll i=0;i<k;i++){
        sort(buckets[i].begin(),buckets[i].end());
        for(ll j=1;j<buckets[i].size();j++){
            answer=min(answer,buckets[i][j]^buckets[i][j-1]);
        }
    }
    cout<<answer<<endl;
    for(ll i=0;i<n;i++){
        cout<<color[i]<<" ";
    }
    cout<<endl;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
1
5 2
1 4 3 2 5

2
3 1
1 2 3
3 2
1 2 3

*/

