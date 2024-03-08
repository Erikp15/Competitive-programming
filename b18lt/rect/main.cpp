#include <bits/stdc++.h>

using namespace std;

typedef int ll;

const ll Size=1e3+1;

class point{
public:
    ll x,y;
    bool operator<(const point& a)const {
        return x<a.x;
    }
    bool operator>(const point& a)const {
        return y>a.y;
    }
};

class node{
public:
    node *l,*r;
    ll c;
    node(ll v){
        c=v;
        *l=nullptr;
        *r=nullptr;
    }
};

point a[Size],b[Size][2],x[Size],y[Size];
ll n,m,seg_tree[4*Size][4*Size];
ll c=0;

void build_y(ll xl,ll xr,ll i,ll yl,ll yr,ll j){
    ll mid=(yl+yr)/2;
    if(yl==yr){
        if(xl==xr){
            if(p[xl][yl]){
                seg_tree[i][j]=1;
            }
        }else{
            seg_tree[i][j]=seg_tree[i*2][j]+seg_tree[i*2+1][j];
        }
    }else{
        build_y(xl,xr,i,yl,mid,j*2);
        build_y(xl,xr,i,mid+1,yr,j*2+1);
        seg_tree[i][j]=seg_tree[i][j*2]+seg_tree[i][j*2+1];
    }
}

node* build_x(ll l,ll r,ll i,ll tx,ll ty){
    ll mid=(l+r)/2;
    if(mid<=tx){
        return new build_x(l,mid,i*2,tx,ty);
    }
    build_y(l,r,i,0,Size-1,1);
}

ll query_y(ll tl,ll tr,ll i,ll yl,ll yr,ll j){
    ll mid=(yl+yr)/2;
    if(tl>tr)
        return -1;
    if(tl==yl and tr==yr){
        return seg_tree[i][j];
    }else{
        ll n1=query_y(tl,min(mid,tr),i,yl,mid,j*2);
        ll n2=query_y(max(tl,mid+1),tr,i,mid+1,yr,j*2+1);
        if(n1==-1)
            return n2;
        if(n2==-1)
            return n1;
        return n1+n2;
    }
}

ll query_x(ll l,ll r,ll i,ll txl,ll txr,ll tyl,ll tyr){
    ll mid=(l+r)/2;
    if(txl>txr)
        return -1;
    if(txl!=l or txr!=r){
        ll n1=query_x(l,mid,i*2,txl,min(txr,mid),tyl,tyr);
        ll n2=query_x(mid+1,r,i*2+1,max(txl,mid+1),txr,tyl,tyr);
        if(n1==-1)
            return n2;
        if(n2==-1)
            return n1;
        return n1+n2;
    }else{
        return query_y(tyl,tyr,i,0,Size-1,1);
    }
}

void solve(){
    bool g=false;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i].x>>a[i].y;
        a[i].x--; a[i].y--;
        if(a[i].x>Size or a[i].y>Size)
            g=true;
        p[a[i].x][a[i].y]=true;
    }
    sort(x,x+n,less<point>());
    sort(y,y+n,greater<point>());
    if(g)return;
    build_x(0,Size-1,1);
    cin>>m;
    for(ll i=0;i<m;i++){
        cin>>b[i][0].x>>b[i][0].y>>b[i][1].x>>b[i][1].y;
        b[i][0].x--; b[i][0].y--; b[i][1].x--; b[i][1].y--;
        cout<<query_x(0,Size-1,1,min(b[i][0].x,b[i][1].x),max(b[i][0].x,b[i][1].x),min(b[i][0].y,b[i][1].y),max(b[i][0].y,b[i][1].y))<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    while(t--)
        solve();
    return 0;
}


