#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e2+1;
ll a[Size];
string s[Size];
bool diffed[Size];

void solve(){
    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        cin>>s[i]>>a[i];
        diffed[i]=false;
    }
    for(ll i=0;i<n;i++){
        ll map_false=-1, map_true=-1;
        bool can_diff_0=true, can_diff_1=true;
        for(ll j=0;j<m;j++){
            if(diffed[j]){
                continue;
            }
            if(s[j][i]=='0'){
                if(map_false==-1){
                    map_false=a[j];
                }else{
                    if(map_false!=a[j]){
                        can_diff_0=false;
                    }
                }
            }else{
                if(map_true==-1){
                    map_true=a[j];
                }else{
                    if(map_true!=a[j]){
                        can_diff_1=false;
                    }
                }
            }
        }
        if(can_diff_0){
            for(ll j=0;j<m;j++){
                if(s[j][i]=='0'){
                    diffed[j]=true;
                }
            }
        }
        if(can_diff_1){
            for(ll j=0;j<m;j++){
                if(s[j][i]=='1'){
                    diffed[j]=true;
                }
            }
        }
    }
    for(ll i=0;i<m;i++){
        if(!diffed[i]){
            cout<<"LIE"<<endl;
            return;
        }
    }
    cout<<"OK"<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
4

1 3
0 0
0 0
1 1

2 4
00 0
01 1
10 1
11 1

1 2
0 1
0 0

2 4
00 0
01 1
10 1
11 0
*/
