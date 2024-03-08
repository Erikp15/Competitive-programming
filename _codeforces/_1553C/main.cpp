#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    string a;
    cin>>a;
    ll ans=9,g[2];
    g[0]=0; g[1]=0;
    for(ll i=0;i<10;i++){
        if(a[i]=='1'){
            g[i%2]++;
        }
        if(a[i]=='?'){
            if(i%2==0){
                g[0]++;
            }
        }
        if(i%2==0){
            if(g[1]+(10-i-1)/2+1<g[0]){
                ans=i;
                break;
            }
        }else{
            if(g[1]+(10-i-1)/2<g[0]){
                ans=i;
                break;
            }
        }
    }
    g[0]=0; g[1]=0;
    for(ll i=0;i<10;i++){
        if(a[i]=='1'){
            g[i%2]++;
        }
        if(a[i]=='?'){
            if(i%2==1){
                g[1]++;
            }
        }
        if(g[0]+(10-i-1)/2<g[1]){
            ans=min(ans,i);
            break;
        }
    }
    cout<<ans+1<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
8
1 1
4 5
4 2
2 2
5 4
3 6
1 3
4 4
11.5

6
1 1
5 5
4 2
4 3
2 5
3 4
works

2 38
20 46
64 53
31 27
13 11
93 19
85 37

0 10
5 16
10 20
15 16
20 10
15 4
10 0
5 4
*/
