#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=2e5+1;
ll a[Size];

void solve(){
    ll n,ans=0,ansr=0,sum=0;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        if(a[i]%2==0){
            sum++;
        }else{
            sum--;
        }
    }
    if(sum<-1 or sum>1){
        cout<<-1<<"\n";
        return;
    }
    for(ll j=0;j<=log2(n);j++){
        for(ll i=1;i<n-1;i+=2){
            if(a[i]%2==a[i-1]%2 and a[i]%2!=a[i+1]%2){
                swap(a[i],a[i+1]);
                ans++;
                continue;
            }
            if(a[i]%2==a[i+1]%2 and a[i]%2!=a[i-1]%2){
                swap(a[i],a[i-1]);
                ans++;
            }
        }
        bool f=true;
        for(ll i=1;i<n-1;i++){
            if(a[i]==a[i-1] or a[i]==a[i+1]){
                f=false;
                break;
            }
        }
        if(f){
            break;
        }
    }
    for(ll j=0;j<=log2(n);j++){
        for(ll i=n-1;i>=1;i-=2){
            if(a[i]%2==a[i-1]%2 and a[i]%2!=a[i+1]%2){
                swap(a[i],a[i+1]);
                ans++;
                continue;
            }
            if(a[i]%2==a[i+1]%2 and a[i]%2!=a[i-1]%2){
                swap(a[i],a[i-1]);
                ansr++;
            }
        }
        bool f=true;
        for(ll i=1;i<n-1;i++){
            if(a[i]==a[i-1] or a[i]==a[i+1]){
                f=false;
                break;
            }
        }
        if(f){
            break;
        }
    }
    cout<<max(ans,ansr)<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
*/
