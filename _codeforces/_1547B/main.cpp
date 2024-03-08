#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    void solve(){
        string a;
        cin>>a;
        ll pl=0,pr=a.size()-1;
        bool found=false;
        for(ll i=0;i<(ll)a.size();i++){
            if(a[i]=='a'){
                pl=i-1;
                pr=i+1;
                found=true;
            }
        }
        if(!found){
            cout<<"No"<<"\n";
            return;
        }
        for(ll i=1;i<(ll)a.size();i++){
            if(a[pl]=='a'+i){
                if(pl>0)pl--;
                continue;
            }
            if(a[pr]=='a'+i){
                if(pr<a.size()-1)pr++;
                continue;
            }
            cout<<"No"<<"\n";
            return;
        }
        cout<<"Yes"<<"\n";
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
