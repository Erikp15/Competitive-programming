#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    ll n,bridge_order[51];
    bool unreachable_top[51][51],unreachable_bot[51][51];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>bridge_order[i];
    }
    ll curr=1;
    for(ll i=1;i<n;i++){
        if(i%2!=0){
            if(unreachable_top[curr][bridge_order[i]]){
                cout<<0<<endl;
                return 0;
            }
            for(ll j=min(curr,bridge_order[i])+1;j<max(curr,bridge_order[i]);j++){
                for(ll m=1;m<=min(curr,bridge_order[i]);m++){
                    unreachable_top[j][m]=true;
                }
                for(ll m=max(curr,bridge_order[i]);m<=n;m++){
                    unreachable_top[j][m]=true;
                }
            }
            for(ll j=1;j<=n;j++){
                unreachable_top[curr][j]=true;
                unreachable_bot[curr][j]=true;
                unreachable_top[bridge_order[i]][j]=true;
            }
            curr=bridge_order[i];
        }else{
            if(unreachable_bot[curr][bridge_order[i]]){
                cout<<0<<endl;
                return 0;
            }
            for(ll j=min(curr,bridge_order[i])+1;j<max(curr,bridge_order[i]);j++){
                for(ll m=1;m<=min(curr,bridge_order[i]);m++){
                    unreachable_bot[j][m]=true;
                }
                for(ll m=max(curr,bridge_order[i]);m<=n;m++){
                    unreachable_bot[j][m]=true;
                }
            }
            for(ll j=1;j<=n;j++){
                unreachable_top[curr][j]=true;
                unreachable_bot[curr][j]=true;
                unreachable_bot[bridge_order[i]][j]=true;
            }
            curr=bridge_order[i];
        }
    }
    if(n%2==0){
        for(ll i=1;i<=n;i++){
            if(unreachable_bot[curr][i]){
                cout<<0<<endl;
                return 0;
            }
        }
    }else{
        for(ll i=1;i<=n;i++){
            if(unreachable_top[curr][i]){
                cout<<0<<endl;
                return 0;
            }
        }
    }
    cout<<1<<endl;
    return 0;
}
