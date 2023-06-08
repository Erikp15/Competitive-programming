#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e6+1;
vector<ll> sorted[4*Size];

ll ans=0,n,k;

void mergeing(ll i){
    ll p1=0,p2=0;
    while(p1<sorted[i*2].size() or p2<sorted[i*2+1].size()){
        if(p1==sorted[i*2].size()){
            sorted[i].push_back(sorted[i*2+1][p2]);
            p2++;
            continue;
        }
        if(p2==sorted[i*2+1].size()){
            sorted[i].push_back(sorted[i*2][p1]);
            p1++;
            continue;
        }
        if(sorted[i*2][p1]<=sorted[i*2+1][p2]){
            sorted[i].push_back(sorted[i*2][p1]);
            p1++;
        }else{
            sorted[i].push_back(sorted[i*2+1][p2]);
            p2++;
        }
    }
}

void build(ll l,ll r,ll i,vector<int>& h1){
    if(l==r){
        sorted[i].push_back(h1[l]);
    }else{
        ll mid=(l+r)/2;
        build(l,mid,i*2,h1);
        build(mid+1,r,i*2+1,h1);
        mergeing(i);
    }
}

ll query(ll l,ll r,ll tl,ll tr,ll th,ll i,bool type){
    if(tr<l or tl>r)
        return 0;
    if(tl==l and tr==r){
        if(type){
            auto res=sorted[i].end()-upper_bound(sorted[i].begin(),sorted[i].end(),th);
            return res;
        }else{
            auto res=sorted[i].end()-lower_bound(sorted[i].begin(),sorted[i].end(),th);
            return res;
        }
    }else{
        ll mid=(l+r)/2;
        ll a1=query(l,mid,tl,min(mid,tr),th,i*2,type);
        ll a2=query(mid+1,r,max(mid+1,tl),tr,th,i*2+1,type);
        return a1+a2;
    }
}

ll b_search(ll l,ll r,ll i,bool type,vector<int>& h1){
    ll mid=(l+r)/2;
    if(l>r)
        return i;
    if(type){
        ll curr=query(0,n-1,mid,i,h1[i],1,type);
        if(mid==0){
            ans-=curr;
            return mid;
        }
        if(h1[i]<h1[mid] and curr==k){
            ans-=curr;
            return mid;
        }else{
            if(curr<k){
                return b_search(l,mid,i,type,h1);
            }else{
                return b_search(mid+1,r,i,type,h1);
            }
        }
    }else{
        ll curr=query(0,n-1,i+1,mid,h1[i],1,1);
        if(mid==n-1){
            curr=query(0,n-1,i+1,mid,h1[i],1,type);
            ans-=curr;
            return mid;
        }
        if(h1[i]<h1[mid] and curr==k){
            curr=query(0,n-1,i+1,mid,h1[i],1,type);
            ans-=curr;
            return mid;
        }else{
            if(curr<k){
                return b_search(mid+1,r,i,type,h1);
            }else{
                return b_search(l,mid,i,type,h1);
            }
        }
    }
}
/*
int main(){
    vector<int> h1;
    cin>>n>>k;
    for(ll i=0;i<n;i++){
        ll h;
        cin>>h;
        h1.push_back(h);
    }
    build(0,n-1,1,h1);
    for(ll i=0;i<n;i++){
        ll left=b_search(0,i-1,i,1,h1);
        ll right=b_search(i+1,n-1,i,0,h1);
        ans+=abs(i-left)+abs(i-right);
    }
    return ans;
}
*/

ll init(vector<int> h, int K){
    n=h.size(),k=K;
    build(0,n-1,1,h);
    for(ll i=0;i<n;i++){
        ll left=b_search(0,i-1,i,1,h);
        ll right=b_search(i+1,n-1,i,0,h);
        ans+=abs(i-left)+abs(i-right);
    }
    return ans;
}

/*
7 2
7 6 8 9 4 5 3
15

9 1
8 7 6 7 3 9 4 5 6
20

3 1
7 7 7
*/

