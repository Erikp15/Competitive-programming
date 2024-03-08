#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=2e5+1;
    ll pre[6][Size];
    string perm[6],a;

    void calc_pre(ll i,ll n){
        perm[i][0]==a[0] ? pre[i][0]=0 : pre[i][0]=1;
        for(ll j=1;j<n;j++){
            if(perm[i][j]==a[j]){
                pre[i][j]=pre[i][j-1];
            }else{
                pre[i][j]=pre[i][j-1]+1;
            }
        }
    }

    void solve(){
        cin>>a;
        ll n=a.size();
        perm[0]="abc";
        perm[1]="acb";
        perm[2]="bac";
        perm[3]="bca";
        perm[4]="cab";
        perm[5]="cba";
        for(ll i=3;i<n;i++){
            perm[0]+=perm[0][i-3];
            perm[1]+=perm[1][i-3];
            perm[2]+=perm[2][i-3];
            perm[3]+=perm[3][i-3];
            perm[4]+=perm[4][i-3];
            perm[5]+=perm[5][i-3];
        }
        for(ll i=0;i<6;i++){
            calc_pre(i,n);
        }
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,t=1;
    cin>>n>>t;
    solve();
    while(t--){
        ll l,r;
        cin>>l>>r;
        l--; r--;
        ll ans=r+l;
        for(ll i=0;i<6;i++){
            ans=min(ans,pre[i][r]-pre[i][l]+(perm[i][l]!=a[l]));
        }
        cout<<ans<<"\n";
    }
    return 0;
}
