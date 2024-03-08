#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    for(ll m=0;m<t;m++){
        ll n,a[2001],ans=0;
        cin>>n;
        vector<ll> even,odd;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            if(a[i]%2==0){
                even.push_back(a[i]);
            }else{
                odd.push_back(a[i]);
            }
        }
        ans+=(even.size()*odd.size()+even.size()*(even.size()-1)/2);
        ll pairs=0;
        for(ll i=0;i<(ll)odd.size();i++){
            for(ll j=0;j<i;j++){
                if(__gcd(odd[i],odd[j])!=1){
                    pairs++;
                }
            }
            for(ll j=i+1;j<(ll)odd.size();j++){
                if(__gcd(odd[i],odd[j])!=1){
                    pairs++;
                }
            }
        }
        pairs/=2;
        ans+=pairs;
        cout<<ans<<endl;
    }
    return 0;
}
/*
3
4
3 6 5 3
2
1 7
5
1 4 2 4 1
4
0
9
*/
