#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;

class player{
public:
    ll ans;
    string first,last;
    bool operator<(const player& a){
        if(ans==a.ans){
            if(first==a.first){
                return last>a.last;
            }
            return first>a.first;
        }
        return ans<a.ans;
    }
};

    player a[101];

    void solve(){
        ll n,m,k;
        cin>>n>>m>>k;
        db keeper[101][101];
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                cin>>keeper[i][j];
            }
        }
        for(ll e=0;e<k;e++){
            a[e].ans=0;
            cin>>a[e].first>>a[e].last;
            for(ll i=0;i<n;i++){
                for(ll j=0;j<m;j++){
                    db tmp; cin>>tmp;
                    if(tmp*(1-keeper[i][j])>=0.65){
                        a[e].ans++;
                    }
                }
            }
        }
        sort(a,a+k);

        for(ll i=k-1;i>k-6;i--){
            cout<<a[i].first<<" "<<a[i].last<<endl;
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
