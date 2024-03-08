#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=1e5+1;

    void solve(){
        string a,b;
        cin>>a>>b;
        ll i=a.size()-1,j=b.size()-1;
        for(;i>=0;){
            if(a[i]!=b[j]){
                i-=2;
            }else{
                i--;
                j--;
            }
        }
        if(j==-1){
            cout<<"Yes"<<"\n";
            return;
        }else{
            cout<<"No"<<"\n";
            return;
        }
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
