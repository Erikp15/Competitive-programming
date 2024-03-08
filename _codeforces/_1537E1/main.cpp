#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    string all_ans[5001];

    void solve(){
        ll n,k;
        cin>>n>>k;
        string a,b;
        cin>>a;
        for(ll i=0;i<n;i++){
            b+=a[i];
            while(all_ans[i].size()<k){
                all_ans[i]+=b;
            }
            while(all_ans[i].size()>k){
                all_ans[i].pop_back();
            }
        }
        string best_so_far;
        for(ll i=0;i<k;i++){
            best_so_far+='z';
        }
        for(ll i=0;i<n;i++){
            for(ll j=0;j<k;j++){
                if(all_ans[i][j]>best_so_far[j])break;
                if(all_ans[i][j]<best_so_far[j])best_so_far=all_ans[i];
            }
        }
        cout<<best_so_far<<"\n";
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
1
3
1 2 3
*/
