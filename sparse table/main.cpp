#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=100001;
    ll n,q,a[Size],sparse_table[Size][25];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        sparse_table[i][0]=a[i];
    }
    for(ll j=1;j<=(ll)log2(n);j++){
        for(ll i=0;i<n;i++){
            sparse_table[i][j]=max(sparse_table[i][j-1],sparse_table[(ll)(i+pow(2,j-1))][j-1]);
        }
    }
    cin>>q;
    for(ll i=0;i<q;i++){
        ll l,r;
        cin>>l>>r;
        ll p=floor(log2(r-l+1));
        cout<<max(sparse_table[l][p],sparse_table[(ll)(r-pow(2,p)+1)][p])<<endl;
    }
    return 0;
}
/*
6
1 2 3 4 5 6
100
0 5
0 2
3 5
1 4

6
5 1 3 6 4 1
100
0 5
0 2
3 5
1 4
*/
