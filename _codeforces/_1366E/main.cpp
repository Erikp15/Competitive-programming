#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=200001,p=998244353;
    ll a[Size],b[Size];

int main(){
    ll n,m,ans=1;
    cin>>n>>m;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    for(ll i=0;i<m;i++){
        cin>>b[i];
    }
    for(ll i=0;i<n/2;i++){
        swap(a[i],a[n-i-1]);
    }
    for(ll i=0;i<m/2;i++){
        swap(b[i],b[m-i-1]);
    }
    b[m]=b[m-1];
    ll curr_b=0;
    for(ll i=0;i<n;i++){
        if(a[i]<b[curr_b]){
            cout<<0<<endl;
            return 0;
        }
        if(a[i]==b[curr_b]){
            for(ll j=i+1,counter=1;j<n;j++,counter++){
                if(a[j]<b[curr_b+1]){
                    cout<<0<<endl;
                    return 0;
                }
                if(a[j]<b[curr_b]){
                    ans=ans*counter;
                    ans=ans%p;
                    break;
                }
            }
            curr_b++;
        }
    }
    if(curr_b<m){
        cout<<0<<endl;
        return 0;
    }
    for(ll i=n-1;i>=0;i--){
        if(a[i]<b[m-1]){
            cout<<0<<endl;
            return 0;
        }
        if(a[i]==b[m-1])break;
    }
    cout<<ans<<endl;
    return 0;
}
