#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    void solve(){
        ll ax,ay,bx,by,fx,fy;
        cin>>ax>>ay>>bx>>by>>fx>>fy;
        if((ax==bx and fx==ax and (fy<ay and fy>by or fy>ay and fy<by)) or (ay==by and fy==ay and (fx<ax and fx>bx or fx>ax and fx<bx))){
            cout<<abs(ax-bx)+abs(ay-by)+2<<"\n";
        }else{
            cout<<abs(ax-bx)+abs(ay-by)<<"\n";
        }

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
