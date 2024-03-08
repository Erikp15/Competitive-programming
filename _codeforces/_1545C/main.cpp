#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=501,mod=998244353;
    ll num_count[Size][Size],a[2*Size][Size];
    vector<ll> res;
    bool to_skip[2*Size];

    void solve(){
        ll n,ans=1;
        cin>>n;
        for(ll i=0;i<2*n;i++){
            for(ll j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        for(ll i=0;i<2*n;i++){
            for(ll j=0;j<n;j++){
                num_count[j][a[i][j]]++;
            }
        }
        for(ll i=0;i<2*n;i++){
            for(ll j=0;j<n;j++){
                if(num_count[j][a[i][j]]==1){
                    res.push_back(i);
                    to_skip[i]=true;
                    break;
                }
            }
            if(res.size()==n)break;
        }
        for(ll i=0;i<res.size();i++){
            for(ll x=0;x<2*n;x++){
                if(to_skip[x])continue;
                for(ll y=0;y<n;y++){
                    if(a[res[i]][y]==a[x][y]){
                        to_skip[x]=true;
                        /*
                        for(ll z=0;z<n;z++){
                            num_count[z][a[x][z]]--;
                        }
                        */
                        break;
                    }
                }
            }
        }
        for(ll i=0;i<2*n;i++){
            if(res.size()==n)break;
            ll is_ans=true;
            if(to_skip[i])continue;
            for(ll j=0;j<n;j++){
                if(num_count[j][a[i][j]]==2){
                    is_ans=false;
                    break;
                }
            }
            if(is_ans){
                res.push_back(i+1);
                for(ll x=0;x<2*n;x++){
                    for(ll y=0;y<n;y++){
                        if(a[i][y]==a[x][y]){
                            to_skip[i]=true;
                            /*
                            for(ll z=0;z<n;z++){
                                num_count[z][a[x][z]]--;
                            }
                            */
                            break;
                        }
                    }
                }
                ans*=2;
                ans=ans%mod;
            }
        }
        cout<<ans<<"\n";
        for(ll i=0;i<res.size();i++){
            cout<<res[i]+1<<" ";
        }
        cout<<"\n";
        res.clear();
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                num_count[i][j]=0;
            }
        }
        for(ll i=0;i<2*n;i++){
            to_skip[i]=false;
        }
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        solve();
        cout<<endl;
    }
    return 0;
}
/*
1
3
1 2 3
1 3 2
3 1 2
2 3 1
2 3 1
2 1 3

123
312
231 x2

1
5
4 5 1 2 3
3 5 2 4 1
1 2 3 4 5
5 2 4 1 3
3 4 5 1 2
2 3 4 5 1
1 3 5 2 4
4 1 3 5 2
2 4 1 3 5
5 1 2 3 4

45123
12345
34512
23451
51234 x1

35241
12345
52413
34512
23451
*/
