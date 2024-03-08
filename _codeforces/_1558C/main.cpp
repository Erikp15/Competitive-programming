#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=2e5+2;
ll pos[Size],a[Size];

void solve(){
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        pos[a[i]]=i;
    }
    for(ll i=1;i<=n;i++){
        if(pos[a[i]]%2!=a[i]%2){
            cout<<-1<<"\n";
            return;
        }
    }
    vector<ll> moves;
    for(ll i=n;i>=2;i-=2){
        if(i%2==0)continue;
        moves.push_back(pos[i]);
        ll s=pos[i];
        for(ll j=1;j<=s/2;j++){
            swap(a[j],a[s-j+1]);
            swap(pos[a[j]],pos[a[s-j+1]]);
        }
        moves.push_back(pos[i-1]-1);
        s=pos[i-1]-1;
        for(ll j=1;j<=s/2;j++){
            swap(a[j],a[s-j+1]);
            swap(pos[a[j]],pos[a[s-j+1]]);
        }
        moves.push_back(pos[i-1]+1);
        s=pos[i-1]+1;
        for(ll j=1;j<=s/2;j++){
            swap(a[j],a[s-j+1]);
            swap(pos[a[j]],pos[a[s-j+1]]);
        }
        moves.push_back(3);
        s=3;
        for(ll j=1;j<=s/2;j++){
            swap(a[j],a[s-j+1]);
            swap(pos[a[j]],pos[a[s-j+1]]);
        }
        moves.push_back(i);
        s=i;
        for(ll j=1;j<=s/2;j++){
            swap(a[j],a[s-j+1]);
            swap(pos[a[j]],pos[a[s-j+1]]);
        }
    }
    cout<<moves.size()<<"\n";
    for(auto itr:moves){
        cout<<itr<<" ";
    }
    cout<<"\n";
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
