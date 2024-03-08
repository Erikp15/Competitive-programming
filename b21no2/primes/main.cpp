#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e6+1,n=1e6+1;

bool isnt_prime[Size];
ll pre[Size];
vector<ll> all_primes;

void find_all_primes(){
    isnt_prime[0]=true;
    isnt_prime[1]=true;
    for(ll i=2;i<=n;i++){
        for(ll j=i+i;j<=n;j+=i){
            isnt_prime[j]=true;
        }
    }
    for(ll i=0;i<=n;i++){
        if(!isnt_prime[i]){
            all_primes.push_back(i);
            if(pre[all_primes.size()-1]<1e6+1){
                pre[all_primes.size()]=pre[all_primes.size()-1]+i;
            }else{
                pre[all_primes.size()]=1e18;
            }
        }
    }
}

void solve(){
    ll a,b;
    cin>>a>>b;
    ll ans[4];
    ans[1]=0;
    ans[2]=0;
    for(ll i=1;pre[i-1]<=b;i++){
        for(ll j=0;j<i;j++){
            if(i-j>ans[1]-ans[2]){
                if(!isnt_prime[pre[i]-pre[j]] and pre[i]-pre[j]>=a and pre[i]-pre[j]<=b){
                    ans[0]=pre[i]-pre[j];
                    ans[1]=i;
                    ans[2]=j;
                }
            }
        }
    }
    if(ans[1]-ans[2]==0){
        for(ll i=a;i<=b;i++){
            if(!isnt_prime[i]){
                cout<<i<<" 1"<<endl<<i<<endl;
                return;
            }
        }
        cout<<"no prime"<<endl;
        return;
    }
    cout<<ans[0]<<" "<<ans[1]-ans[2]<<endl;
    for(ll i=ans[2];i<ans[1];i++){
        cout<<all_primes[i]<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    find_all_primes();
    while(t--){
        solve();
    }
    return 0;
}
