#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

    const ll Size=5001,mod=998244353;
    ll a[Size],p[Size],d[Size];
    pair<ll,ll> high[Size];
    ll n,x,y,ans=0;
    vector<ll> adj[Size],r_adj[Size];
    bool visited[Size];

    void dfs(ll node,ll depth){
        visited[node]=true;
        d[node]=depth;
        for(auto it:adj[node]){
            if(!visited[it])dfs(it,depth+1);
        }
    }

    ll find_close(ll node,ll no){
        if(a[node]==1 and no!=node){
            a[node]=0;
            return node;
        }
        ll ans=-1;
        for(auto it:r_adj[node]){
            ll t=find_close(it,no);
            if(t!=-1)ans=t;
        }
        return ans;
    }

    bool check_down(ll node,ll no){
        if(a[node]==1 and no!=node){
            return true;
        }
        bool ans=false;
        for(auto it:adj[node]){
            ll t=check_down(it,no);
            if(t)ans=true;
        }
        return ans;
    }

    void solve(){
        cin>>n>>x>>y;
        for(ll i=1;i<n;i++){
            cin>>a[i];
        }
        for(ll i=1;i<n;i++){
            cin>>p[i];
            adj[p[i]-1].push_back(i);
            r_adj[i].push_back(p[i]-1);
        }
        dfs(0,0);
        for(ll i=0;i<n;i++){
            if(a[i]>=2){
                ans+=(a[i]/2)*d[i]*y;
                a[i]%2==0 ? a[i]=0 : a[i]=1;
            }
        }
        for(ll i=0;i<n;i++){
            high[i].first=d[i];
            high[i].second=i;
        }
        sort(high,high+n);
        if(x<y){
            for(ll i=0;i<n;i++){
                if(a[high[i].second]==0)continue;
                ll num=find_close(high[i].second,high[i].second);
                if(num!=-1){
                    a[high[i].second]=0;
                    ans+=min(high[i].first*x+d[ans]*x,high[i].first*y);
                }else{
                    if(!check_down(high[i].second,high[i].second)){
                        a[high[i].second]=0;
                        ans+=high[i].first*x;
                    }
                }
            }
        }else{
            for(ll i=n-1;i>=0;i--){
                if(a[high[i].second]==0)continue;
                ll num=find_close(high[i].second,high[i].second);
                if(num!=-1){
                    a[high[i].second]=0;
                    ans+=min(high[i].first*x+d[ans]*x,high[i].first*y);
                }else{
                    if(!check_down(high[i].second,high[i].second)){
                        a[high[i].second]=0;
                        ans+=high[i].first*x;
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll test=1;
    while(test--){
        solve();
    }
    return 0;
}

