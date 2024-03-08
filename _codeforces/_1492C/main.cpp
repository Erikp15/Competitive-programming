#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=1001;
    ll dp[Size][Size];
    vector<ll> left_most,right_most;
    string a,b;

    void solve(){
        ll n,m;
        cin>>n>>m;
        cin>>a>>b;
        for(ll i=0,bp=0;i<n;i++){
            if(a[i]==b[bp]){
                left_most.push_back(i);
                bp++;
            }
        }
        for(ll i=n-1,bp=m-1;i>=0;i--){
            if(a[i]==b[bp]){
                right_most.push_back(i);
                bp--;
            }
        }
        ll ans=0;
        reverse(right_most.begin(),right_most.end());
        for(ll i=0;i<(ll)right_most.size()-1;i++){
            ans=max(ans,right_most[i+1]-left_most[i]);
        }
        cout<<ans<<endl;
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
/*
6 3
abcabc
abc
4

9 4
abcxxcxxd
abcd
6
*/
