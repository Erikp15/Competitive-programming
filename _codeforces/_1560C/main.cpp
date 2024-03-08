#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=4e5+2;

void solve(){
    ll n,sum=1,i=1,lower=0,c=1,r=1;
    cin>>n;
    if(n==1){
        cout<<1<<" "<<1<<"\n";
        return;
    }
    for(i=1;true;i+=2,c++){
        sum+=i;
        if(sum>=n){
            lower=sum-i;
            break;
        }
    }
    ll mid=(lower+sum)/2;
    if(sum==n){
        cout<<1<<" "<<c+1<<"\n";
        return;
    }
    if(n<mid){
        cout<<n-lower+1<<" "<<c<<"\n";
        return;
    }else{
        cout<<mid-lower+1<<" "<<sum-n<<"\n";
        return;
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
