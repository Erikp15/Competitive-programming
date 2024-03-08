#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll m=1e9+7;
ll n,k,ans[2000001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    ll lower=1;
    ans[1]=1;
    for(ll i=2;i<=k;i++){
        ans[i]=((ans[i-1])%m+(ans[i-1])%m+m)%m;
    }
    ans[k+1]=((ans[k])%m+(ans[k])%m-1+m)%m;
    for(ll i=k+2;i<=n;i++){
        ans[i]=((ans[i-1])%m+(ans[i-1])%m-(ans[i-k-1])%m+m)%m;
        lower++;
    }
    for(ll i=1;i<=n;i++){
        if(ans[i]<0){
            cout<<i<<" ";
        }
    }
    cout<<(ans[n])%m<<endl;
    return 0;
}
