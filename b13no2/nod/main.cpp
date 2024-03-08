#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll Size=20;

string n1,n2,n3;

void add(){
    ll carry=0,smax=max(n1.size(),n2.size());
    for(ll i=0;i<smax;i++){
        ll d1,d2;
        if(i>=n1.size()){
            d1=0;
        }else{
            d1=n1[i]-'0';
        }
        if(i>=n2.size()){
            d2=0;
        }else{
            d2=n2[i]-'0';
        }
        if(d1+d2+carry>=10){
            n3+=d1+d2+carry-10+'0';
            carry=1;
        }else{
            n3+=d1+d2+carry+'0';
            carry=0;
        }
    }
    if(carry!=0){
        n3+=carry+'0';
    }
    n1=n2;
    n2=n3;
    n3.clear();
}

void solve(){
    ll n;
    cin>>n;
    n1='1';
    n2='2';
    for(ll i=1;i<n;i++){
        add();
    }
    reverse(n1.begin(),n1.end());
    reverse(n2.begin(),n2.end());
    cout<<n1<<" "<<n2<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}

