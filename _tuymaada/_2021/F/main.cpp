#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

    const ll Size=16,mod=998244353;
    ll m[Size],t[Size][Size],k_count[Size];

    void solve(){
        ll n,k,ans=0;
        cin>>n>>k;
        for(ll i=0;i<n;i++){
            cin>>m[i];
        }
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m[i];j++){
                cin>>t[i][j];
                if(t[i][j]==k)k_count[i]++;
            }
        }
        for(ll i=0;i<n;i++){
            if(k_count[i]==0)continue;
            for(ll j=0;j<n;j++){
                if(j==i)continue;
                if(k_count[j]==0)continue;
                ll curr_ans=1;
                for(ll x=0;x<n;x++){
                    if(x==i)continue;
                    if(x==j)continue;
                    if(k_count[x]>=1){
                        curr_ans*=(m[x]-k_count[x]);
                    }else{
                        curr_ans*=m[x];
                    }
                }
                ans+=(curr_ans*k_count[i]*k_count[j]);
            }
        }
        cout<<ans/2<<"\n";
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
15 2
10 10 10 10 10 10 10 10 10 10 10 10 10 10 10
2 1 1 1 1 1 1 1 1 1
2 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1

12 1
10 10 10 10 10 10 10 10 10 10 10 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
*/
