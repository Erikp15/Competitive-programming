#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=1001,m=10e9+7;
    ll count_val[Size];

    void solve(){
        ll n,k;
        cin>>n>>k;
        ll ans=n+1;
        for(ll i=0;i<n;i++)count_val[i]=1;
        if(k==1){
            cout<<1<<"\n";
            return;
        }
        k--;
        bool reversed=false;
        while(k>1){
            ll sum_so_far=0;
            if(!reversed){
                for(ll i=n-1;i>=0;i--){
                    ans=(ans+(count_val[i]*i)%m)%m;
                    sum_so_far=sum_so_far+count_val[i];
                    count_val[i]=(sum_so_far-count_val[i])%m;
                    sum_so_far=sum_so_far%m;
                }
            }else{
                for(ll i=0;i<n;i++){
                    ans=(ans+(count_val[i]*(n-i-1))%m)%m;
                    sum_so_far=sum_so_far+count_val[i];
                    count_val[i]=(sum_so_far-count_val[i])%m;
                    sum_so_far=sum_so_far%m;
                }
            }
            k--;
            reversed=!reversed;
        }
        cout<<ans<<"\n";
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*


*/
