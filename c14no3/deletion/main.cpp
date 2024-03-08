#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=1e4+1;
    ll dp_2[10*Size],dp_0[10*Size],dp_1[10*Size],dp_4[10*Size],num_2_a[Size];

    void solve(){
        string a;
        a="";
        for(ll i=1;i<10001;i++){
            ll num=i;
            string b;
            b="";
            while(num>0){
                b+=(num%10)+'0';
                num/=10;
            }
            reverse(b.begin(),b.end());
            a+=b;
            num_2_a[i]=a.size()-1;
        }
        for(ll i=1;i<=a.size();i++){
            if(a[i]=='2'){
                dp_2[i]=dp_2[i-1]+1;
            }else{
                dp_2[i]=dp_2[i-1];
            }
            if(a[i]=='0'){
                dp_0[i]=dp_2[i-1]+dp_0[i-1];
            }else{
                dp_0[i]=dp_0[i-1];
            }
            if(a[i]=='1'){
                dp_1[i]=dp_0[i-1]+dp_1[i-1];
            }else{
                dp_1[i]=dp_1[i-1];
            }
            if(a[i]=='4'){
                dp_4[i]=dp_1[i-1]+dp_4[i-1];
            }else{
                dp_4[i]=dp_4[i-1];
            }
        }
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    solve();
    while(t--){
        ll n;
        cin>>n;
        cout<<dp_4[num_2_a[n]]<<endl;
    }
    return 0;
}
