#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e6+1;
string a;
ll prefix_count_c[Size],prefix_count_o[Size],prefix_count_w[Size];

void solve(){
    for(ll i=0;i<a.length();i++){
        prefix_count_c[i+1]=prefix_count_c[i];
        prefix_count_o[i+1]=prefix_count_o[i];
        prefix_count_w[i+1]=prefix_count_w[i];
        if(a[i]=='C'){
            prefix_count_c[i+1]++;
        }
        if(a[i]=='O'){
            prefix_count_o[i+1]++;
        }
        if(a[i]=='W'){
            prefix_count_w[i+1]++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a;
    solve();
    ll t;
    cin>>t;
    while(t--){
        ll l,r;
        cin>>l>>r;
        if(((prefix_count_c[r]-prefix_count_c[l-1])%2==1 and (prefix_count_o[r]-prefix_count_o[l-1])%2==0 and (prefix_count_w[r]-prefix_count_w[l-1])%2==0) or ((prefix_count_c[r]-prefix_count_c[l-1])%2==0 and (prefix_count_o[r]-prefix_count_o[l-1])%2==1 and (prefix_count_w[r]-prefix_count_w[l-1])%2==1)){
            cout<<'Y';
        }else{
            cout<<'N';
        }
    }
    cout<<endl;
    return 0;
}
