#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=2e3+10;

ll bags[Size][Size],bin_rep[Size][33],s[Size][33];

void upd(ll a,ll b){

}

void solve(){
    ll n,k;
    cin>>n>>k;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<k;j++){
            cin>>bags[i][j];
        }
    }
    for(ll i=0;i<n;i++){
        ll bit_count=0,num=0;
        for(ll j=0;j<k;j++){
            if(bit_count==32){
                bit_count=0;
                num++;
            }
            bin_rep[i][num]+=bags[i][j]%2;
            bin_rep[i][num]=bin_rep[i][num]<<1;
            s[i][num]++;
        }
    }
    ll ans=0,pos=0;
    ll limit=k/32;
    if(k%32!=0)limit++;
    for(ll i=0;i<n;i++){
        ll seq[33];
        for(ll j=0;j<33;j++){
            seq[j]=bin_rep[i][j];
        }
        for(ll j=i+1;j<n;j++){
            ll even_c=0,odd_c=0;
            for(ll m=0;m<limit;m++){
                seq[m]=seq[m]^bin_rep[j][m];
                if(seq[m]==0){
                    even_c++;
                    continue;
                }
                if(__builtin_popcount(seq[m])==s[i][m]){
                    odd_c++;
                }
            }
            if(even_c==limit or odd_c==limit){
                if(ans<j-i+1){
                    pos=i+1;
                    ans=j-i+1;
                }
            }
        }
    }
    if(pos==0 and ans==0){
        for(ll i=0;i<n;i++){
            ll even_c=0,odd_c=0;
            for(ll j=0;j<limit;j++){
                if(bin_rep[i][j]==0){
                    even_c++;
                    continue;
                }
                if(__builtin_popcount(bin_rep[i][j])==s[i][j]){
                    odd_c++;
                }
            }
            if(even_c==limit or odd_c==limit){
                cout<<i+1<<" "<<1<<endl;
                return;
            }
        }
    }
    cout<<pos<<" "<<ans<<endl;
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
2 2
1 1
1 0
*/
