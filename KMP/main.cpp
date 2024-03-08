#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=2e5+1,m=1e9+7;
    ll prefix[Size];

    // aba.......bab

    void solve(){
        string a,b;
        cin>>a>>b;
        prefix[0]=0;
        for(ll i=1;i<b.size();i++){
            ll j=prefix[i-1];
            while(b[j]!=b[i] and j>0){
                j=prefix[j-1];
            }
            if(b[j]==b[i]){
                j++;
            }
            prefix[i]=j;
        }
        ll appear=0;
        for(ll i=0,j=0;i<a.size();){
            if(b[j]==a[i]){
                i++;
                j++;
            }
            if(j==b.size()){
                appear++;
            }
            if(i<a.size() and b[j]!=a[i]){
                if(j!=0){
                    j=prefix[j-1];
                }else{
                    i++;
                }
            }
        }
        cout<<appear<<endl;
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
10
alalabalabala
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
