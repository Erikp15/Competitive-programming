#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    void solve(){
        ll k,n,m;
        cin>>k>>n>>m;
        ll a[101],b[101];
        vector<ll> ans;
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        for(ll i=0;i<m;i++){
            cin>>b[i];
        }
        ll ap=0,bp=0;
        bool a_done=false,b_done=false;
        for(;!a_done or !b_done;){
            if(a[ap]==0 and !a_done){
                ans.push_back(a[ap]);
                k++;
                if(ap<n-1){
                    ap++;
                }else{
                    a_done=true;
                }
                continue;
            }
            if(b[bp]==0 and !b_done){
                ans.push_back(b[bp]);
                k++;
                if(bp<m-1){
                    bp++;
                }else{
                    b_done=true;
                }
                continue;
            }
            if(a[ap]<=k and !a_done){
                ans.push_back(a[ap]);
                if(ap<n-1){
                    ap++;
                }else{
                    a_done=true;
                }
                continue;
            }
            if(b[bp]<=k and !b_done){
                ans.push_back(b[bp]);
                if(bp<m-1){
                    bp++;
                }else{
                    b_done=true;
                }
                continue;
            }
            if(a_done and b_done)break;
            cout<<-1<<"\n";
            return;
        }
        for(ll i=0;i<(ll)ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
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
