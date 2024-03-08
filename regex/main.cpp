#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=2e5+1,m=1e9+7;

    // aba.......bab

    void solve(){
        string a,b;
        cin>>a>>b;
        regex expression("(b)");
        ptrdiff_t const match_count(distance(
        sregex_iterator(a.begin(),a.end(),expression),
        sregex_iterator()));
        cout<<match_count<<endl;
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}
/*
10
bbala
bla
abla
xalab
aa
labal

1
aaaaaadaaaaac
aaaad

1
aaaabbaaaa
aaabbaaa

1

*/
