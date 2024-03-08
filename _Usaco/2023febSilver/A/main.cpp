#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

struct query{
    ld a,b,c;
};

const ll Size=1e2+1,mod=1e9+7;
ld tc,tmuffin;
ll n;
query lines[Size];

ld det(ld a,ld b,ld c,ld d){
    return a*d-c*b;
}

pair<ll,ll> get_common_point(ll id1,ll id2){
    ll d=det(lines[id1].a,lines[id1].b,lines[id2].a,lines[id2].b);
    if(d==0){
        return {-2e18-1,-2e18-1};
    }
    ll dx=det(lines[id1].c,lines[id1].b,lines[id2].c,lines[id2].b);
    ll dy=det(lines[id1].a,lines[id1].c,lines[id2].a,lines[id2].c);
    return {dy/d,dx/d};
}

void solve(){
    cin>>n>>tc>>tmuffin;
    for(ll i=0;i<n;i++){
        cin>>lines[i].a>>lines[i].b>>lines[i].c;
    }
    ld ans=1e18;
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            pair<ll,ll> curr_point=get_common_point(i,j);
            if(curr_point.first<0 or curr_point.second<0)
                continue;
            bool is_ans=true;
            for(ll k=0;k<n;k++){
                if(lines[k].a*curr_point.first+lines[k].b*curr_point.second>lines[k].c){
                    is_ans=false;
                }
            }
            if(is_ans){
                //cout<<curr_point.first<<" "<<curr_point.second<<endl;
                ans=min(ans,max((ld)0,tc-curr_point.first)+max((ld)0,tmuffin-curr_point.second));
            }
        }
    }
    lines[n].a=(ld)0;
    lines[n].b=(ld)1;
    lines[n].c=(ld)tmuffin;
    lines[n+1].a=(ld)1;
    lines[n+1].b=(ld)0;
    lines[n+1].c=(ld)tc;
    pair<ll,ll> down_point={1e18,1e18};
    pair<ll,ll> left_point={1e18,1e18};
    for(ll i=0;i<n;i++){
        down_point=min(down_point,get_common_point(n,i));
        left_point=min(left_point,get_common_point(n+1,i));
    }
    //if(down_point.first>=0 and down_point.second>=0){
        ans=min(ans,max((ld)0,tc-down_point.first)+max((ld)0,tmuffin-down_point.second));
    //}
    //if(left_point.first>=0 and left_point.second>=0){
        ans=min(ans,max((ld)0,tc-left_point.first)+max((ld)0,tmuffin-left_point.second));
   // }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
1
1 10 10
1 1 2
*/
