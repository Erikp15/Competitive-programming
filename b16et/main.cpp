#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=101;
    ll n,m;
    ll cap[Size][Size],ori[Size][Size],p[Size];
    vector<ll> adj[Size];
    ll ans[Size];

    ll bfs(ll s,ll t){
        for(ll i=0;i<n;i++)p[i]=-1;
        p[s]=-2;
        queue<pair<ll,ll>> next;
        next.push({s,1e18});
        while(!next.empty()){
            ll v=next.front().first;
            ll flow=next.front().second;
            next.pop();
            for(auto it:adj[v]){
                if(cap[v][it] and p[it]){
                    ll new_flow=min(flow,cap[v][it]);
                    p[it]=v;
                    if(it==t)return new_flow;
                    next.push({it,new_flow});
                }
            }
        }
        return -2;
    }

    void max_flow(ll s,ll t){
        ll flow=0;
        ll new_flow=bfs(s,t);
        while(new_flow>0){
            flow+=new_flow;
            ll curr=t;
            while(curr!=s){
                if(curr==-1){
                    break;
                }else if(p[curr]==-1){
                    break;
                }
                cap[curr][p[curr]]+=new_flow;
                cap[p[curr]][curr]-=new_flow;
                curr=p[curr];
            }
            new_flow=bfs(s,t);
        }
        ans[t]=flow;
    }

    void solve(){
        cin>>n>>m;
        for(ll i=0;i<m;i++){
            ll a,b;
            cin>>a>>b;
            a--; b--;
            if(cap[a][b]==0){
                adj[a].push_back(b);
                adj[b].push_back(a);
            }
            cap[a][b]++;
            cap[b][a]++;
            ori[a][b]++;
            ori[b][a]++;
        }
        ll best_ans=1e18;
        for(ll i=1;i<n;i++){
            max_flow(0,i);
            for(ll i=0;i<n;i++){
                for(ll j=0;j<n;j++){
                    cap[i][j]=ori[i][j];
                }
            }
            best_ans=min(best_ans,ans[i]);
        }
        cout<<best_ans<<endl;
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}
/*
3
3
1 2
2 3
3 1
2

3
2
1 2
2 3
1

4
4
1 2
2 3
3 4
4 1
2
*/

