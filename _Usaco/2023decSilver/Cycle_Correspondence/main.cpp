#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Size=5e5+1;

ll a[Size], a_radix[Size];
ll b[Size], b_radix[Size];
ll needed_shift[Size];
ll best_perm[Size];
ll n,k;

ll solve(){
    for(ll i=0;i<=n;i++){
        a_radix[i]=-1;
        b_radix[i]=-1;
        best_perm[i]=0;
    }
    reverse(b,b+k);
    for(ll i=0;i<k;i++){
        a_radix[a[i]]=i;
    }
    for(ll i=0;i<k;i++){
        b_radix[b[i]]=i;
    }
    for(ll i=0;i<k;i++){
        if(b_radix[a[i]]==-1){
            needed_shift[i]=-1;
        }else{
            ll calc=(b_radix[a[i]]-i+k)%k;
            needed_shift[i]=calc;
            best_perm[calc]++;
        }
    }
    ll best=0;
    for(ll i=0;i<k;i++){
        best=max(best,best_perm[i]);
    }
    return best;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(ll i=0;i<=n;i++){
        a_radix[i]=-1;
        b_radix[i]=-1;
    }
    for(ll i=0;i<k;i++){
        cin>>a[i];
        a_radix[a[i]]=i;
    }
    for(ll i=0;i<k;i++){
        cin>>b[i];
        b_radix[b[i]]=i;
    }
    ll ans=0;
    for(ll i=1;i<=n;i++){
        if(a_radix[i]==-1 and b_radix[i]==-1){
            ans++;
        }
    }
    for(ll i=0;i<k;i++){
        if(b_radix[a[i]]==-1){
            needed_shift[i]=-1;
        }else{
            ll calc=(b_radix[a[i]]-i+k)%k;
            needed_shift[i]=calc;
            best_perm[calc]++;
        }
    }
    ll best=0;
    for(ll i=0;i<k;i++){
        best=max(best,best_perm[i]);
    }
    ll res=solve();
    best=max(best, res);
    cout<<ans+best<<endl;
    return 0;
}
