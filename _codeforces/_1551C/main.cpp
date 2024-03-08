#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll const Size=2e5+1;

string a[Size];
ll value[5][Size];

void solve(){
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<5;j++){
            value[j][i]=0;
        }
        for(ll j=0;j<(ll)a[i].size();j++){
            for(ll m=0;m<5;m++){
                if(a[i][j]=='a'+m){
                    value[m][i]++;
                }else{
                    value[m][i]--;
                }
            }
        }
    }
    for(ll i=0;i<5;i++){
        sort(value[i],value[i]+n);
        reverse(value[i],value[i]+n);
    }
    ll best_ans=0;
    for(ll i=0;i<5;i++){
        ll ans=0,sum=0;
        for(ll j=0;j<n;j++){
            if(sum+value[i][j]<=0)break;
            sum+=value[i][j];
            ans++;
        }
        best_ans=max(best_ans,ans);
    }
    cout<<best_ans<<"\n";
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
1
13 1
3 1 4 1 5 9 2 6 5 3 5 8 9
*/
