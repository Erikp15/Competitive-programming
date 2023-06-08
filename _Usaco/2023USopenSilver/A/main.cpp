#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll Size=2e5+1;

ll n;
pair<ll,ll> a[Size];
ll prefix_sum[Size];
unordered_map<ll,ll> ori_2_sort;

ll b_search(ll l,ll r,ll v){
    ll mid=(l+r)/2;
    if(l==r){
        return l;
    }
    if(a[mid].first>v){
        return b_search(l,mid,v);
    }else{
        return b_search(mid+1,r,v);
    }
}

void solve(){
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a,a+n);
    for(ll i=0;i<n;i++){
        ori_2_sort[a[i].second]=i;
    }
    ll ans=0;
    prefix_sum[1]=a[0].first;
    for(ll i=2;i<=n;i++){
        prefix_sum[i]=prefix_sum[i-1]+a[i-1].first;
    }
    for(ll i=0;i<n;i++){
        ans+=a[i].first*(i+1);
    }

    ll q;
    cin>>q;
    while(q--){
        ll i,j,c_ans=ans;
        cin>>i>>j;
        i--;
        ll p1=ori_2_sort[i];
        ll p2=0;
        if(j>a[n-1].first){
            p2=n;
        }else{
            p2=b_search(0,n-1,j);
        }
        ll offset=0;
        if(p1<p2){
            p2--;
            offset=1;
        }
        c_ans-=a[p1].first*(p1+1);
        c_ans+=j*(p2+1);
        c_ans-=prefix_sum[p2+offset];
        c_ans+=prefix_sum[p1+offset];
        cout<<c_ans<<endl;
    }
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
2
3 4
4
1 10
1 2
2 10
2 2


3
10 11 12
2
1 5
1

*/
