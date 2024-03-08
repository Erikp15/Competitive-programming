#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=1e5+1;
    ll a[Size],even[Size],odd[Size],s_even[Size],s_odd[Size];

    void solve(){
        ll n;
        cin>>n;
        for(ll i=0;i<=100000;i++){
            even[i]=0;
            odd[i]=0;
            s_even[i]=0;
            s_odd[i]=0;
        }
        for(ll i=0;i<n;i++){
            cin>>a[i];
            if(i%2==0){
                even[a[i]]++;
            }else{
                odd[a[i]]++;
            }
        }
        sort(a,a+n);
        for(ll i=0;i<n;i++){
            if(i%2==0){
                s_even[a[i]]++;
            }else{
                s_odd[a[i]]++;
            }
        }
        for(ll i=0;i<=100000;i++){
            if(odd[i]!=s_odd[i] or even[i]!=s_even[i]){
                cout<<"No"<<"\n";
                return;
            }
        }
        cout<<"Yes"<<"\n";
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
