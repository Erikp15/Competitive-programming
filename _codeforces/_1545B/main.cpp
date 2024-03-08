#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=1e5+1,mod=998244353;
    ll fact[Size],r_fact[Size];
    string a;

    long long inv(long long a, long long m) {
        if (a == 1) return 1;
        return inv(m%a, m) * (m - m/a) % m;
    }

    void solve(){
        ll n,count_0=0,pair_count=0;
        cin>>n;
        a="";
        cin>>a;
        for(ll i=0;i<(ll)a.size();i++){
            if(a[i]=='1'){
                ll count_1=0;
                while(a[i]=='1' and i<n){
                    count_1++;
                    i++;
                }
                pair_count+=count_1/2;
            }
            if(a[i]=='0'){
                count_0++;
            }
        }
        if(count_0==0 or pair_count==0){
            cout<<1<<"\n";
            return;
        }
        ll n1=fact[count_0+pair_count];
        ll n2=r_fact[count_0];
        ll n3=r_fact[pair_count];
        cout<<n1*n2%mod*n3%mod<<"\n";
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    fact[0]=r_fact[0]=1;
    for(ll i=1;i<=100000;i++){
        fact[i]=fact[i-1]*i%mod;
        r_fact[i]=r_fact[i-1]*inv(i,mod)%mod;
    }
    while(t--){
        solve();
    }
    return 0;
}

