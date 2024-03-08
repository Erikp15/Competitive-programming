#include<bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
using namespace std;
ll n,m;
ll a[1000001];
ll sum=0;
ll mx=0;
int main(){
	cin>>n>>m;
	vector<int> index(m+1,0);
	vector<vector<pair<ll,ll> > > blocks(n+1);
	vector<vector<ll> > ans(n+1);
	for(int k=1;k<=n;k++){
		cin>>a[k];
		sum+=a[k];
		mx=max(mx,a[k]);
	}
	if(sum%m!=0||mx>sum/m){
		cout<<-1;
		return 0;
	}
	int ind=1;
	for(int k=1;k<=m;k++){
		ll sz=sum/m;
		while(sz>0){
			ll f=a[ind];
			if(sz>=f){
				sz-=f;
				blocks[k].push_back({f,ind});
				ind++;
			}
			else{
				a[ind]-=sz;
				blocks[k].push_back({sz,ind});
				sz=0;
			}
		}
	}
	ind=0;
	while(index[1]<blocks[1].size()){
		ll mn=1e18;
		for(int k=1;k<=m;k++){
			mn=min(mn,blocks[k][index[k]].ff);
		}
		ans[ind].push_back(mn);
		for(int k=1;k<=m;k++){
			int bb=blocks[k][index[k]].ss;
			ans[ind].push_back(blocks[k][index[k]].ss);
		}
		for(int k=1;k<=m;k++){
			blocks[k][index[k]].ff-=mn;
			if(blocks[k][index[k]].ff==0){
				index[k]++;
			}
		}
		ind++;
	}
	cout<<ind<<"\n";
	for(int k=0;k<ind;k++){
		for(int i=0;i<ans[k].size();i++){
			cout<<ans[k][i]<<' ';
		}
		cout<<"\n";
	}
    return 0;
}
