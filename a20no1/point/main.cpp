#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e3+10;

bool grid[Size][Size];

void solve(){
    ll n,ans=0;
    cin>>n;
    for(ll k=0,x1,y1,x2,y2;k<n;k++){
        cin>>x1>>y1>>x2>>y2;
        x1+=500;
        y1+=500;
        x2+=500;
        y2+=500;
        if(x1>x2){
            swap(x1,x2);
            swap(y1,y2);
        }
        ll a=x2-x1;
        ll b=y2-y1;
        if(a==0 or b==0){
            if(x1==x2){
                for(ll i=0;i<=abs(y1-y2);i++){
                    grid[(y1<y2) ? y1+i : y1-i][x2]=true;
                }
                continue;
            }
            if(y1==y2){
                for(ll i=0;i<=abs(x1-x2);i++){
                    grid[y2][(x1<x2) ? x1+i : x1-i]=true;
                }
                continue;
            }
        }
        ll gcd=__gcd(abs(a),abs(b));
        a/=gcd;
        b/=gcd;
        ll i=x1,j=y1;
        for(;i!=x2 and j!=y2;i+=a,j+=b){
            grid[j][i]=true;
        }
        grid[j][i]=true;
    }
    for(ll i=0;i<Size;i++){
        for(ll j=0;j<Size;j++){
            ans+=(grid[i][j]==1);
        }
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
