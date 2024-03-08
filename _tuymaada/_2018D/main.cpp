#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class volcano{
public:
    ll x,y,t;
};

    bool operator>(const volcano& a,const volcano& b){
        return a.y<b.y;
    }

class s_tree{
public:
    ll sum,ans;
};

    const ll Size=150001;
    volcano a[Size];
    s_tree seg_tree[2*Size];
    bool started[Size];

    void update(ll l,ll r,ll i,ll tl,ll tr,ll v){
        if(tl>r or tr<l)return;
        if(tl==l and tr==r){
            seg_tree[i].sum+=v;
            seg_tree[i].ans+=v;
        }else{
            ll mid=(l+r)/2;
            update(l,mid,i*2,tl,min(mid,tr),v);
            update(mid+1,r,i*2+1,max(mid+1,tl),tr,v);
            seg_tree[i].ans=min(seg_tree[i*2].ans,seg_tree[i*2+1].ans)+seg_tree[i].sum;
        }
    }

    void solve(){
        ll n,m;
        cin>>n>>m;
        for(ll i=0;i<n;i++){
            cin>>a[i].x>>a[i].y>>a[i].t;
            a[i].x--;
            a[i].y--;
        }
        sort(a,a+n,greater<volcano>());
        ll l=0,r=m,curr_vol=0;
        while(l!=r){
            ll mid=(l+r)/2;
            for(ll i=0;i<2*m;i++){
                seg_tree[i].ans=0;
                seg_tree[i].sum=0;
            }
            for(ll i=0;i<n;i++){
                started[i]=false;
            }
            curr_vol=0;
            ll farthest=1e18;
            for(ll i=0;i<m;i++){
                while(abs(a[curr_vol].y-i)+1>mid-a[curr_vol].t and started[curr_vol]){
                    update(0,m-1,1,max(a[curr_vol].x-(mid-a[curr_vol].t),(ll)0),min(a[curr_vol].x+(mid-a[curr_vol].t),m-1),-1);
                    curr_vol++;
                }
                for(ll j=curr_vol;abs(a[j].y-i)+1<=mid-a[j].t;j++){
                    started[j]=true;
                    update(0,m-1,1,max(a[j].x-(mid-a[j].t),(ll)0),min(a[j].x+(mid-a[j].t),m-1),1);
                }
                farthest=min(farthest,seg_tree[1].ans);
                if(farthest==0){
                    break;
                }
            }
            if(farthest==0){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        cout<<l-1<<"\n";
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
