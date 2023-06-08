#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e5+1;
ll nextg[Size],nexth[Size];
char gow='G';
char othergow='H';

void solve(){
    string s,output;
    ll ans=0;
    ll n,k;
    cin>>n>>k;
    cin>>s;
    output="";
    for(ll i=0;i<n;i++){
        output+='.';
    }
    for(ll g=0; g<2; g++){
        bool isgow=bool(g);
        char cgow=(isgow?gow:othergow);
        ll i=s.size()-1;
        while(i>=0){
            while(i>=0 && s[i]!=cgow){
                i--;
            }
            if(i<0) break;
            ll pos=i-k;
            if(pos<0) pos=0;
            if(pos==0 and output[0]!='.' and output[0]!=cgow) {
                output[1]=cgow;
            } else {
                output[pos]=cgow;
            }
            i=i-2*k-1;
            ans++;
        }
    }
    cout<<ans<<endl;
    cout<<output<<endl;
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
/*
1
10 2
GHHHHG
*/
