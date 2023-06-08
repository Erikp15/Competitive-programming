#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool cw(pair<ll,ll> a,pair<ll,ll> b,pair<ll,ll> c){
    return a.second*(b.first-c.first)+b.second*(c.first-a.first)+c.second*(a.first-b.first)<0;
}

bool ccw(pair<ll,ll> a,pair<ll,ll> b,pair<ll,ll> c){
    return a.second*(b.first-c.first)+b.second*(c.first-a.first)+c.second*(a.first-b.first)>0;
}

    const ll Size=1e5+1,m=1e9+7;
    pair<ll,ll> p[Size],start_p,end_p;
    vector<pair<ll,ll>> upper_convex_hull,lower_convex_hull;
    set<pair<ll,ll>> lower_hull,upper_hull;

    void solve(){
        ll n;
        cin>>n;
        while(cin>>p[i].second>>p[i].first){

        }
        sort(p,p+n);
        start_p=p[0];
        end_p=p[n-1];
        lower_hull.insert(start_p);
        lower_hull.insert(end_p);
        upper_hull.insert(start_p);
        upper_hull.insert(end_p);
        for(ll i=1;i<n-1;i++){
            if(ccw(start_p,p[i],end_p)){
                lower_hull.insert(p[i]);
            }else{
                upper_hull.insert(p[i]);
            }
        }
        /*
        for(auto it:lower_hull){
            cout<<it.second<<" "<<it.first<<" ";
        }
        cout<<endl;
        for(auto it:upper_hull){
            cout<<it.second<<" "<<it.first<<" ";
        }
        */
        pair<ll,ll> last=start_p;
        upper_convex_hull.push_back(start_p);
        for(auto it:upper_hull){
            if(it==start_p or it==end_p)continue;
            if(cw(last,it,end_p)){
                upper_convex_hull.push_back(it);
            }
            last=it;
        }
        last=start_p;
        upper_convex_hull.push_back(end_p);
        lower_convex_hull.push_back(start_p);
        for(auto it:lower_hull){
            if(it==start_p or it==end_p)continue;
            if(ccw(last,it,end_p)){
                lower_convex_hull.push_back(it);
            }
            last=it;
        }
        lower_convex_hull.push_back(end_p);
        for(ll i=0;i<(ll)upper_convex_hull.size();i++){
            cout<<upper_convex_hull[i].second<<" "<<upper_convex_hull[i].first<<" ";
        }
        for(ll i=lower_convex_hull.size()-1;i>=0;i--){
            cout<<lower_convex_hull[i].second<<" "<<lower_convex_hull[i].first<<" ";
        }
        cout<<endl;
        float total_area=0,lower_area=0;
        for(ll i=1;i<(ll)upper_convex_hull.size();i++){
            total_area+=((upper_convex_hull[i].second-upper_convex_hull[i-1].second)*(upper_convex_hull[i].first+upper_convex_hull[i-1].first)/2.0);
        }
        for(ll i=lower_convex_hull.size()-2;i>=0;i--){
            lower_area+=((lower_convex_hull[i+1].second-lower_convex_hull[i].second)*(lower_convex_hull[i+1].first+lower_convex_hull[i].first)/2.0);
        }
        cout<<total_area-lower_area<<endl;
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
/*
8
1 1
4 4
3 1
2 2
1 3
2 3
5 5
6 4
*/
