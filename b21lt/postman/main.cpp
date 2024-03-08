#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=2e5+1;

pair<ll,ll> points[Size];
ll n,m,k,x[Size],y[Size];

ll compute(pair<ll,ll> point){
    ll dist=0,max_dist=0;
    for(ll i=0;i<k;i++){
        max_dist=max(abs(points[i].first-point.first)+abs(points[i].second-point.second),max_dist);
        dist+=(abs(points[i].first-point.first)+abs(points[i].second-point.second))*2;
    }
    return dist-max_dist;
}

void solve(){
    cin>>n>>m>>k;
    for(ll i=0;i<k;i++){
        cin>>points[i].first>>points[i].second;
        x[i]=points[i].first;
        y[i]=points[i].second;
    }
    sort(x,x+k);
    sort(y,y+k);
    ll p1=compute({x[k/2],y[k/2]});
    ll p2=compute({x[k/2],y[k/21]});
    ll p3=compute({x[k/2-1],y[k/2]});
    ll p4=compute({x[k/2-1],y[k/2-1]});
    cout<<min(p1,min(p2,min(p3,p4)))<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    while(t--)
        solve();
    return 0;
}
/*
4 4 4
1 1
4 4
1 3
3 1
*/
