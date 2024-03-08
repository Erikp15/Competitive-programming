#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=200001;
    ll a[Size];
    string based[Size],res[Size];

    void solve(){
        ll n;
        cin>>n;
        for(ll i=0;i<n;i++){
            based[i]="";
            res[i]="";
            a[i]=0;
        }
        for(ll i=0;i<n;i++){
            cin>>a[i];
            while(a[i]>0){
                if(a[i]%2==0){
                    based[i]+='0';
                }else{
                    based[i]+='1';
                }
                a[i]/=2;
            }
            while(based[i].size()<31){
                based[i]+='0';
            }
        }
        for(ll i=0;i<n-1;i++){
            for(ll j=0;j<(ll)based[i].size();j++){
                if(based[i][j]=='1' and based[i+1][j]=='0'){
                    res[i]+='1';
                    based[i+1][j]=based[i][j];
                }else{
                    res[i]+='0';
                }
            }
        }
        cout<<0<<" ";
        for(ll i=0;i<n-1;i++){
            ll ans=0,power=0;
            for(ll j=0;j<(ll)res[i].size();j++){
                if(res[i][j]!='0'){
                    ans+=pow(2,power);
                }
                power++;
            }
            cout<<ans<<" ";
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
/*
tesdt*/
