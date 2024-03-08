#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e5+2;
ll a[Size],b[Size];

void solve(){
    ll n,sum1=0,sum2=0;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    for(ll i=0;i<n;i++){
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    ll amount=n/4;
    set<ll> q1,q2;
    stack<ll> s1,s2;
    for(ll i=0;i<amount;i++){
        s1.push(a[i]);
        s2.push(b[i]);
    }
    for(ll i=amount;i<n;i++){
        q1.insert(a[i]);
        q2.insert(b[i]);
        sum2+=b[i];
        sum1+=a[i];
    }
    for(ll i=0;true;i++){
        if(sum1>=sum2){
            cout<<i<<"\n";
            return;
        }
        q1.insert((ll)100);
        sum1+=100;
        ll num=*q1.begin();
        sum1-=num;
        q1.erase(num);
        s1.push(num);
        if(!(amount<(n+i)/4)){
            if(!s1.empty()){
                num=s1.top();
                s1.pop();
                q1.insert(num);
                sum1+=num;
            }
            if(!s2.empty()){
                num=s2.top();
                s2.pop();
                q2.insert(num);
                sum2+=num;
            }
        }else{
            amount++;
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
/*
111674811
646644446
*/
