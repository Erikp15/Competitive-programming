#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

    const ll Size=1e6+1,mod=998244353;
    ll x[Size];
    set<ll> all_x;

    ll low(ll l,ll r,ll t){
        ll mid=(l+r)/2;
        if(l==r)return r;
        if(x[t]<mid){
            return low(l,mid,t);
        }else{
            return low(mid+1,r,t);
        }
    }

    void solve(){
        ll n,m;
        cin>>n>>m;
        for(ll i=0;i<n;i++){
            cin>>x[i];
        }
        for(ll i=0;i<m;i++){
            char d;
            cin>>d;
            ll p,t;
            cin>>p>>t;
            ll it;
            bool is_l=false,printed=false;
            if(d=='L'){
                is_l=true;
            }else{
                is_l=false;
            }
            ll index=low(0,n-1,p);
            for(ll s=1;true;is_l=!is_l,s++){
                if(is_l){
                    it=x[index];
                }else{
                    index++;
                    if(index==n)break;
                    it=x[index];
                }

                if(t<=abs(it-p)){
                    if(is_l){
                        cout<<p-t<<"\n";
                    }else{
                        cout<<p+t<<"\n";
                    }
                    printed=true;
                    break;
                }
                t-=abs(it-p);
                p=it;
                if(is_l){
                    is_l=!is_l;
                    if(index+s>=n)break;
                    index+=s;
                }else{
                    is_l=!is_l;
                    if(index-s<0)break;
                    index-=s;
                }
            }
            if(!printed){
                if(is_l){
                    cout<<p-t<<"\n";
                }else{
                    cout<<p+t<<"\n";
                }
            }

        }
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}
