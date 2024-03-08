#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    string a;
    vector<ll> seg_tree(600001,1);

    ll upd(ll i){
        return seg_tree[i]=(a[i]!='0' ? seg_tree[i*2+1] : 0)+(a[i]!='1' ? seg_tree[i*2+2] : 0);
    }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll k;
    cin>>k;
    cin>>a;
    reverse(a.begin(),a.end());
    ll n=1<<k;
    for(ll i=n-2;i>=0;i--){
        upd(i);
    }
    ll q;
    cin>>q;
    while(q--){
        ll p;
        char c;
        cin>>p>>c;
        p=n-p-1;
        a[p]=c;
        while(p){
            upd(p);
            p=(p-1)/2;
        }
        cout<<upd(0)<<"\n";
    }
}
/*
3
0110?11
6
5 1
6 ?
7 ?
1 ?
5 ?
1 1


*/
