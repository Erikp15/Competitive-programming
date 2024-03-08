#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    vector<ll> taken,not_taken;

    void solve(){
        ll n,l,r,s;
        cin>>n>>l>>r>>s;
        ll max_sum=(n*(n+1)/2)-((r-l)*(r-l+1)/2);
        for(ll i=n;i>=1;i--){
            if(s-i>=0){
                s-=i;
                taken.push_back(i);
            }else{
                not_taken.push_back(i);
            }
            if(s<=0)break;
        }
        if(s>max_sum){
            cout<<"-1"<<"\n";
        }else{
            for(ll i=0,j=0;i+j<n;){
                if(i==l){
                    cout<<taken[i]<<" ";
                    i++;
                }else{
                    cout<<not_taken[j]<<" ";
                    j++;
                }
            }
            cout<<"\n";
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
