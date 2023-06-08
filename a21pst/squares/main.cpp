#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class point{
public:
    ll x,y;
};

    ll n,m,q;
    point all_squares[50001],all_points[50001];
    ll closest_sq[50001];
    set<ll> x_axis,y_axis;

ll bi_search(ll s,ll b,ll e){
    ll curr=((e-b)/2)+b;
    ll ans=-1;
    if((closest_sq[curr]>s and closest_sq[curr-1]<=s) or curr==m-1 or curr==0){
        return curr+1;
    }
    if(closest_sq[curr]<=s){
        ans=bi_search(s,curr+1,e);
    }
    if(closest_sq[curr]>s){
        ans=bi_search(s,b-1,curr);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(ll i=0;i<n;i++){
        cin>>all_squares[i].x>>all_squares[i].y;
        x_axis.insert(all_squares[i].x);
        y_axis.insert(all_squares[i].y);
    }
    for(ll i=0;i<m;i++){
        cin>>all_points[i].x>>all_points[i].y;
        ll ans1=0,ans2=0;
        if(x_axis.lower_bound(all_squares[i].x)!=x_axis.begin()){
            ans1=max(closest_sq[i],abs(all_points[i].x-*x_axis.lower_bound(all_points[i].x)));
        }
        if(x_axis.upper_bound(all_squares[i].x)!=x_axis.end()){
            ans1=max(closest_sq[i],abs(all_points[i].x-*x_axis.upper_bound(all_points[i].x)));
        }
        if(y_axis.lower_bound(all_squares[i].y)!=y_axis.begin()){
            ans2=max(closest_sq[i],abs(all_points[i].y-*y_axis.lower_bound(all_points[i].y)));
        }
        if(y_axis.upper_bound(all_squares[i].y)!=y_axis.end()){
            ans2=max(closest_sq[i],abs(all_points[i].y-*y_axis.upper_bound(all_points[i].y)));
        }
        closest_sq[i]=min(ans1,ans2);
        closest_sq[i]*=2;
    }
    cout<<endl;
    sort(closest_sq,closest_sq+m);
    cin>>q;
    for(ll i=0;i<q;i++){
        ll s;
        cin>>s;
        cout<<bi_search(s,0,m-1)<<" ";
    }
    return 0;
}
