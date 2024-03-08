#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e3+1,mod=1e9+7;
ll n,m,s,t,l;
ll adj[65][Size][Size];
ll res[2][Size][Size];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>s>>t>>l;
    for(ll i=0;i<m;i++){
        ll from,to,weight;
        cin>>from>>to>>weight;
        from--; to--;
        if(weight==1){
            adj[0][to][from]=1;
        }else{
            adj[0][n][from]=1;
            for(ll j=0;j<weight-2;j++){
                adj[0][n+1][n]=1;
                n++;
            }
            adj[0][to][n]=1;
        }
    }
    for(ll i=1;i<=64;i++){
        for(ll j=0;j<n;j++){
            for(ll k=0;k<n;k++){
                for(ll m=0;m<n;m++){
                    adj[i][j][k]=(adj[i][j][k]+adj[i-1][j][m]*adj[i-1][m][k])%mod;
                }
            }
        }
    }
    for(ll i=0;i<n;i++){
        res[0][i][i]=1;
        res[1][i][i]=0;
    }
    for(ll i=0;i<64;i++){
        if(l&(1ULL<<i)){
            for(ll j=0;j<n;j++){
                for(ll k=0;k<n;k++){
                    for(ll m=0;m<n;m++){
                        res[1][j][k]=(res[1][j][k]+res[0][j][m]*adj[i][m][k])%mod;
                    }
                }
            }
            for(ll j=0;j<n;j++){
                for(ll k=0;k<n;k++){
                    res[0][j][k]=res[1][j][k];
                    res[1][j][k]=0;
                }
            }

        }
    }
    t--;
    s--;
    cout<<res[0][t][s]<<endl;
    return 0;
}
/*
2 3
1 2 40
2 2 2
1 1 2
1 2 2

2 3
1 2 2
2 2 1
1 2 1
2 1 1
*/
