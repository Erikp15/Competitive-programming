#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    void solve(){
        string a,t;
        cin>>a>>t;
        ll n=a.size(),m=t.size();
        for(ll i=0;i<a.size();i++){
            if(a[i]==t[0]){
                ll p=0;
                for(ll j=i;j<n;j++){
                    if(a[j]==t[p]){
                        p++;
                        if(p==m){
                            cout<<"Yes"<<"\n";
                            return;
                        }
                        ll p2=p;
                        for(ll x=j-1;x>=0;x--){
                            if(a[x]==t[p2]){
                                p2++;
                                if(p2==m){
                                    cout<<"Yes"<<"\n";
                                    return;
                                }
                            }else{
                                break;
                            }
                        }
                    }else{
                        break;
                    }
                }
            }
        }
        cout<<"No"<<"\n";
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
1
abcdef
cdedcb
*/
