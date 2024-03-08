#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=100001;
    string a;
    ll pre_ans[Size],alpha[27];

    void solve(){
        ll n,q;
        cin>>n>>q;
        cin>>a;
        ll count_so_far=1;
        for(ll i=0;i<n;i++){
            pre_ans[i]=pre_ans[i-1]+(a[i]-'a'+1);
        }

        for(ll i=0;i<q;i++){
            ll l,r;
            cin>>l>>r;
            l-=2; r--;
            if(l<0){
                cout<<pre_ans[r]<<"\n";
            }else{
                cout<<pre_ans[r]-pre_ans[l]<<"\n";
            }
        }
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
*/
