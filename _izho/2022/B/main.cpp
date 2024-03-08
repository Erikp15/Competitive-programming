#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=2e5+10;

ll a[Size],pref[Size],to_beat[Size],ans;
ll arr[Size];
vector<ll> seg_tree[4*Size];
/*
void build(ll l,ll r,ll i){
    if(l==r){
        seg_tree[i].push_back(a[l]);
    }else{
        ll mid=(l+r)/2;
        build(l,mid,i*2);
        build(mid+1,r,i*2+1);
        ll p1=0,p2=0;
        while(p1<seg_tree[i*2].size() or p2<seg_tree[i*2+1].size()){
            if(seg_tree[p1]<a[p2]){
                if(p1<seg_tree[i*2].size()){
                    seg_tree[i].push_back(seg_tree[i*2][p1]);
                    p1++;
                }else{
                    seg_tree[i].push_back(seg_tree[i*2+1][p2]);
                    p2++;
                }
            }else{
                if(p2<seg_tree[i*2+1].size()){
                    seg_tree[i].push_back(seg_tree[i*2+1][p2]);
                    p2++;
                }else{
                    seg_tree[i].push_back(seg_tree[i*2][p1]);
                    p1++;
                }
            }
        }
    }
}
*/

void solve(){
    ll n,q;
    cin>>n>>q;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    pref[0]=a[0];
    for(ll i=1;i<n;i++){
        pref[i]=pref[i-1]+a[i];
    }
    for(ll i=n-2;i>=0;i--){
        to_beat[i]=max(to_beat[i+1],a[i+1]-pref[i]);
        cout<<to_beat[i+1]<<" ";
    }
    cout<<to_beat[0]<<" ";
    /*
    while(q--){
        ll l,r,k;
        cin>>l>>r>>k;
        for(ll i=0;i<=r-l;i++){
            arr[i]=a[i+l];
        }
        ll mid=b_search(0,r-l,k,l,r,is_increasing);
        cout<<r-l-mid<<"\n";
    }
    */
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
/*
5 1
1 2 5 14 27
*/
