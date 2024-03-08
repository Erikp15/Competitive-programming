#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e3+2;

ll from[Size][Size],to[Size][Size],final_pos[Size*Size],books_per_row[Size],dp[Size];
bool is_not_full[Size];

void reset_dp(ll n){
    dp[0]=-1e18;
    for(ll i=1;i<=n+1;i++){
        dp[i]=1e18;
    }
}

ll find_pos(ll book,ll l,ll r){
    ll mid=(l+r)/2;
    if(dp[mid]>book){
        return find_pos(book,l,mid);
    }
    if(dp[mid]<book and dp[mid+1]>book){
        return mid+1;
    }
    if(dp[mid]<book){
        return find_pos(book,mid+1,r);
    }
}

void solve(){
    ll n,m,ans=0;
    cin>>n>>m;
    bool any_space=false;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>from[i][j];
            if(from[i][j]!=0){
                books_per_row[i]++;
            }
        }
        if(books_per_row[i]<m){
            any_space=true;
        }
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>to[i][j];
            final_pos[to[i][j]]=j;
        }
    }
    if(!any_space){
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                if(from[i][j]!=to[i][j]){
                    cout<<-1<<"\n";
                    return;
                }
            }
        }
        cout<<0<<"\n";
        return;
    }
    for(ll i=0;i<n;i++){
        if(books_per_row[i]>=m){
            bool is_corr=true;
            for(ll j=0;j<m;j++){
                if(from[i][j]!=to[i][j]){
                    is_corr=false;
                }
            }
            if(!is_corr){
                ans++;
            }
        }
    }
    for(ll i=0;i<n;i++){
        reset_dp(m);
        for(ll j=0;j<m;j++){
            if(from[i][j]!=0){
                ll pos=find_pos(final_pos[from[i][j]],0,j+1);
                dp[pos]=final_pos[from[i][j]];
            }
        }
        for(ll j=m;j>=0;j--){
            if(dp[j]!=1e18){
                ans+=books_per_row[i]-j;
                break;
            }
        }
    }
    cout<<ans<<"\n";
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
4 3
0 1 2
3 4 5
6 7 8
9 10 11
0 1 2
5 4 3
6 8 7
10 9 11

4 3
0 1 2
3 4 5
6 7 8
9 10 11
0 1 2
3 4 5
6 7 8
9 10 11
*/
