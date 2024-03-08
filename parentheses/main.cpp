#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll m=1e9+7;

void solve(){
    ll prev_ans[5001],ans[5001];
    string a;
    cin>>a;
    ll n=a.size();
    for(ll i=0;i<=n;i++){
        ans[i]=0;
    }
    ans[1]=1;
    if(a[0]==')'){
        cout<<0<<endl;
        return;
    }
    for(ll i=1;i<n;i++){
        if(a[i]=='('){
            for(ll j=i+1;j>=0;j--){
                ans[j]=ans[j-1];
            }
        }
        if(a[i]==')'){
            for(ll j=0;j<=i+1;j++){
                ans[j]=ans[j+1];
            }
        }
        if(a[i]=='?'){
            for(ll j=0;j<=i;j++){
                prev_ans[j]=ans[j];
            }
            ans[0]=prev_ans[1];
            ans[i+1]=prev_ans[i];
            for(ll j=1;j<=i;j++){
                ans[j]=(prev_ans[j-1]+prev_ans[j+1])%m;
            }
        }
    }
    cout<<ans[0]<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}
//????????????????????????????????????????????????
