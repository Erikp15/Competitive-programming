#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=300001;
    ll a[Size],t[Size],l_ans[Size],r_ans[Size];
    pair<ll,ll> tmp[Size];

    void solve(){
        ll n,k;
        cin>>n>>k;
        for(ll i=0;i<n;i++){
            l_ans[i]=1e10;
            r_ans[i]=1e10;
        }
        for(ll i=0;i<k;i++){
            cin>>tmp[i].first;
            tmp[i].first--;
        }
        for(ll i=0;i<k;i++){
            cin>>tmp[i].second;
        }
        sort(tmp,tmp+k);
        for(ll i=0,p=0;i<n;i++){
            a[i]=0;
            if(tmp[p].first==i and p<k){
                a[i]=tmp[p].second;
                p++;
            }
        }
        if(a[0]!=0){
            l_ans[0]=a[0];
        }
        if(a[n-1]!=0){
            r_ans[n-1]=a[n-1];
        }
        for(ll i=1;i<n;i++){
            if(a[i]!=0){
                l_ans[i]=a[i];
            }
            l_ans[i]=min(l_ans[i],l_ans[i-1]+1);
        }
        for(ll i=n-2;i>=0;i--){
            if(a[i]!=0){
                r_ans[i]=a[i];
            }
            r_ans[i]=min(r_ans[i],r_ans[i+1]+1);
        }
        for(ll i=0;i<n;i++){
            cout<<min(l_ans[i],r_ans[i])<<" ";
        }
        cout<<"\n";
        for(ll i=0;i<n;i++){
            a[i]=0;
            t[i]=0;
        }
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
