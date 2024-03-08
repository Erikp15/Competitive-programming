#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,i,j,ii,jj,zx,xc,k,f[1000009],X[1000009],T,dep,pi;
vector <vector <long long> > ans;
vector <long long> vv;
vector <pair <long long, long long> > v[1000009];
int main(){
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>a>>k;zx=0;xc=0;
	for(i=1; i<=a; i++){
		cin>>f[i];xc=max(xc,f[i]);
		zx+=f[i];
	}
	if(zx%k!=0){
		cout<<-1;exit(0);
	}
	if(xc*k>zx){
		cout<<-1;exit(0);
	}
	T=zx/k;
	j=1;jj=1;
	for(i=1; i<=a; ){
		if(jj>T){j++;jj=1;}
		if(T-jj+1>=f[i]){
			v[j].push_back(make_pair(f[i]+jj-1,i));jj+=f[i];
			i++;
			continue;
		}
		v[j].push_back(make_pair(T,i));f[i]-=T-jj+1;
		j++;jj=1;
	}
	dep=1;pi=0;
	while(dep<=T){
		pi++;vv.clear();X[pi]=1000000000000000000LL;
		for(i=1; i<=k; i++){
			c=lower_bound(v[i].begin(),v[i].end(),make_pair(dep,0LL))-v[i].begin();
			X[pi]=min(X[pi],v[i][c].first-dep+1);vv.push_back(v[i][c].second);
		}
		ans.push_back(vv);dep+=X[pi];
	}
	cout<<ans.size()<<"\n";
	for(i=0; i<ans.size(); i++){
		cout<<X[i+1]<<" ";
		for(j=0; j<k; j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
