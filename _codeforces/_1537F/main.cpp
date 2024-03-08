#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=2e5+10;
    ll v[Size],t[Size];
    ll n,m,v_sum=0,t_sum=0,sum_1=0,sum_2=0;
    ll color[Size];
    vector<ll> adj[Size];

    bool bfs(){
        bool ans=true;
        for(ll i=0;i<n;i++){
            color[i]=-1;
        }
        queue<ll> to_process;
        for(ll i=0;i<n;i++){
            if(color[i]!=-1)continue;
            to_process.push(i);
            color[i]=0;
            while(!to_process.empty()){
                ll node=to_process.front();
                to_process.pop();
                for(ll i=0;i<(ll)adj[node].size();i++){
                    ll next_node=adj[node][i];
                    if(color[next_node]==-1){
                        color[next_node]=color[node]^1;
                        to_process.push(next_node);
                    }else{
                        ans&=color[next_node]!=color[node];
                    }
                }
            }
        }
        return ans;
    }

    void solve(){
        v_sum=0; t_sum=0; sum_1=0; sum_2=0;
        cin>>n>>m;
        for(ll i=0;i<n;i++){
            cin>>v[i];
            v_sum=(v_sum+abs(v[i]))%2;
        }
        for(ll i=0;i<n;i++){
            cin>>t[i];
            t_sum=(t_sum+abs(t[i]))%2;
        }
        for(ll i=0;i<m;i++){
            ll a,b;
            cin>>a>>b;
            a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        if(v_sum!=t_sum){
            cout<<"No"<<"\n";
            return;
        }
        if(bfs()==false){
            cout<<"Yes"<<"\n";
        }else{
            vector<ll> c(2,0);
            for(ll i=0;i<n;i++){
                c[color[i]]+=v[i]-t[i];
            }
            if(c[0]==c[1]){
                cout<<"Yes"<<"\n";
            }else{
                cout<<"No"<<"\n";
            }
        }
        for(ll i=0;i<n;i++){
            adj[i].clear();
            t[i]=0;
            v[i]=0;
            color[i]=0;
        }
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


 int main()
 {
	 ios_base::sync_with_stdio(0);cin.tie(0);
	 long long T;
	 cin >> T;
	 while(T--)
	 {
		 cin >> n >> m;
		 for(long long i = 0;i < n;i++)
			 adj[i].clear();

		 vector<long long> v(n), t(n);
		long long p1 = 0, p2 = 0;
		 for(long long i = 0;i < n; i++){
			 cin >> v[i];
			 p1 = (p1 + abs(v[i])) % 2;
		 }
		 for (long long i = 0;i < n; i++){
			 cin >> t[i];
			 p2 = (p2 + abs(t[i])) % 2;
		 }

		 for(long long i = 0;i < m;i++){
			 long long a, b;
			 cin >> a >> b;
			 --a, --b;
			 adj[a].push_back(b);
			 adj[b].push_back(a);
		 }

		 if(p1 != p2){
		   cout << "NO\n";
		   continue;
		 }

		 if(bipartite() == false){
			 cout << "YES\n";
		 }else{
			 vector<long long> c(2, 0);

			 for(int i = 0;i < n;i++){
				 c[s[i]] += v[i] - t[i];
			 }

			 if(c[0] == c[1]){
				 cout << "YES\n";
			 }else cout << "NO\n";
		 }
	 }
*/
