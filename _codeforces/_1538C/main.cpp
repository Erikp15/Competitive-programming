#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=2e5+1;
ll a[Size];
ll n,l,r;

ll find_lower(ll lower,ll upper,ll i){
    ll mid=(lower+upper)/2;
    if(lower==upper){
        if(a[i]+a[mid]<l){
            return -1;
        }else{
            return mid;
        }
    }
    if(a[i]+a[mid]<l){
        return find_lower(mid+1,upper,i);
    }else{
        return find_lower(lower,mid,i);
    }
}

pair<ll,bool> find_upper(ll lower,ll upper,ll i){
    ll mid=(lower+upper)/2;
    if(lower==upper){
        if(a[i]+a[mid-1]>r){
            return {-1,false};
        }
        if(a[i]+a[mid]<=r){
            return {mid,true};
        }
        return {mid,false};
    }
    if(a[i]+a[mid]<=r){
        return find_upper(mid+1,upper,i);
    }else{
        return find_upper(lower,mid,i);
    }
}

void solve(){
    cin>>n>>l>>r;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    ll ans=0;
    for(ll i=0;i<n-1;i++){
        ll lower=find_lower(i+1,n-1,i);
        pair<ll,bool> upper=find_upper(i+1,n-1,i);
        if(lower!=-1 and upper.first!=-1){
            if(upper.second){
                ans++;
            }
            ans+=upper.first-lower;
        }
    }
    cout<<ans<<"\n";
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
1
4 100 1000
1 1 1 1

1
5 5 8
5 1 2 4 3

*/
