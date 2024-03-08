#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=2e5+2;
ll pre[Size],num[Size];

void solve(){
    ll n;
    cin>>n;
    string a;
    cin>>a;
    string ans="";
    bool is_real=false,is_2=false,is_5=false;
    ll c3=0,c7=0;
    for(ll i=0;i<(ll)a.size();i++){
        if(a[i]!='2' and a[i]!='3' and a[i]!='5' and a[i]!='7'){
            cout<<1<<"\n"<<a[i]-'0'<<"\n";
            return;
        }
        if(a[i]=='3')c3++;
        if(a[i]=='7')c7++;
        if((a[i]=='2' or a[i]=='5') and i!=0 and !is_real){
            ans=a[i-1];
            ans+=a[i];
            is_real=true;
        }
        if(a[i]=='2'){
            is_2=true;
        }
        if(a[i]=='5'){
            is_5=true;
        }
    }
    if(is_real){
        cout<<ans.size()<<"\n"<<ans<<"\n";
        return;
    }
    if(c3>1){
        cout<<2<<"\n"<<33<<"\n";
        return;
    }
    if(c7>1){
        cout<<2<<"\n"<<77<<"\n";
        return;
    }
    if(is_2){
        cout<<2<<"\n"<<27<<"\n";
    }else{
        if(is_5){
            cout<<2<<"\n"<<57<<"\n";
        }else{
            cout<<a.size()<<"\n"<<a<<"\n";
        }
    }
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
