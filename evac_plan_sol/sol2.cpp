#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb(e) push_back(e)
#define sv(a) sort(a.begin(),a.end())
#define sa(a,n) sort(a,a+n)
#define mp(a,b) make_pair(a,b)
#define vf first
#define vs second
#define ar array
#define all(x) x.begin(),x.end()
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
bool remender(ll a , ll b){return a%b;}

const int N = 100003 , M = 500003 , l = 25;
vector<int> adj[N+M];
ll ans[N+M];
int timer;
int tin[N+M], tout[N+M];
int up[N+M][l + 5];
ll dis[N];
vector<pair<int,ll>> vp[N];
int root;

void Dijkstra(vector<int> e){
	 priority_queue< pair<ll,ll>, vector <pair<ll,ll>> , greater<pair<ll,ll>> > pq;
	 for(int i : e){
		 dis[i] = 0;
		 pq.push({0,i});
	 }
	 while(!pq.empty()){
		 ll node = pq.top().second,ww=pq.top().first;
		 pq.pop();
		 if(dis[node] < ww)continue;
		 for(auto i : vp[node]){
			 ll w = i.second;
			 if(dis[i.first] > dis[node] + w){
				 dis[i.first] = dis[node] + w;
				 pq.push({dis[i.first],i.first});
			 }
		 }
	 }
}

struct UFDS {

vector<int> p,siz;

void init(int n){
	p.resize(n + 2);
	siz.resize(n + 2);
	for(int i = 0; i <= n; i++){
		p[i] = i;
		siz[i] = 1;
	}
}

int get(int x){
	return p[x]=(x==p[x] ? x : get(p[x]));
}

void unio(int u , int v , int w , int a , int b){
	if(a == b){
		return;
	}
	adj[root].pb(a);
	adj[root].pb(b);
	p[a] = p[b] = root;
	ans[root] = w;
	root++;
}
};


void dfs(int v, int p){
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v){
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void solve(){
	int n , m;
	cin >> n >> m;
	vector<pair<ll,ll>> v1;
	for(int i = 0; i < m; i++){
		int x , y;
		ll z;
		cin >> x >> y >> z;
		vp[x].pb(mp(y,z));
		vp[y].pb(mp(x,z));
		v1.pb(mp(x,y));
	}
	UFDS d;
	d.init(n + m + 2);
	int k;
	cin >> k;
	vector<int> v;
	for(int i = 0; i < k; i++){
		int x;
		cin >> x;
		v.pb(x);
	}
	for(int i = 0; i <= n; i++)dis[i] = 10000000000000;
	Dijkstra(v);
	//for(int i = 1; i <= n; i++)cout << dis[i] << ' ';
	vector<pair<ll,pair<int,int>>> vp1;
	for(int i = 0; i < m; i++){
		int x = v1[i].vf , y = v1[i].vs;
		vp1.pb(mp(min(dis[x] , dis[y]) , mp(x , y)));
	}
	root = n + 1;
	timer = 0;
	sv(vp1);
	reverse(all(vp1));
	for(int i = 0; i < m; i++){
		d.unio(vp1[i].vs.vf , vp1[i].vs.vs , vp1[i].vf , d.get(vp1[i].vs.vf) , d.get(vp1[i].vs.vs));
	}
	dfs(root-1,root-1);
	int q;
	cin >> q;
	while(q--){
		int s , t;
		cin >> s >> t;
		int lc = lca(s , t);
		cout << ans[lc] << '\n';
	}
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
	//int t;cin >> t;while(t--)
	solve();
	return 0;
}
