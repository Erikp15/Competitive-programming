#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e6+10;

ll radix_a[Size],radix_b[Size];

void solve(){
    ll n,ans=0;
    cin>>n;
    for(ll i=0,a;i<n;i++){
        cin>>a;
        radix_a[a]++;
    }
    for(ll i=0,b;i<n;i++){
        cin>>b;
        radix_b[b]++;
    }
    ll presum_a=0,presum_b=0;
    for(ll i=1,j=1,pos=1;i<=n and j<=n and pos<=n;pos++){
        while(pos-presum_a>radix_a[i]){
            presum_a+=radix_a[i];
            i++;
        }
        while(pos-presum_b>radix_b[j]){
            presum_b+=radix_b[j];
            j++;
        }
        if(i>j){
            radix_a[i]--;
            radix_b[j]--;
            radix_a[j]++;
            radix_b[i]++;
            presum_a++;
            ans++;
        }
    }
    cout<<ans<<endl;
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
