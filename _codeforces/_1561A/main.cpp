#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e3+2;

void solve(){
    ll n;
    cin>>n;
    ll a[Size],b[Size];
    for(ll i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    bool sorted=true;
    for(ll j=0;j<n;j++){
        if(a[j]!=b[j])sorted=false;
    }
    if(sorted){
        cout<<0<<"\n";
        return;
    }
    for(ll i=0;i<n;i++){
        if(i%2==0){
            for(ll j=0;j<n-1;j+=2){
                if(a[j]>a[j+1])swap(a[j],a[j+1]);
            }
        }else{
            for(ll j=1;j<n-1;j+=2){
                if(a[j]>a[j+1])swap(a[j],a[j+1]);
            }
        }
        sorted=true;
        for(ll j=0;j<n;j++){
            if(a[j]!=b[j])sorted=false;
        }
        if(sorted){
            cout<<i+1<<"\n";
            return;
        }
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
/*
111674811
646490893
633627900
*/
