#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll Size=4e1+1;

struct point{
    ll x1,y1,x2,y2;
    bool is_taken;
};

bool operator <(const point& a,const point& b){
    if(a.x2==b.x2){
        return a.y1>b.y1;
    }
    return a.x2<b.x2;
}

point targets[Size];
ll slopes[4*Size];
ll miny;
ll greedy=10;

void solve(){
    ll n,x1;
    cin>>n>>x1;
    for(ll i=0;i<n;i++){
        cin>>targets[i].y1>>targets[i].y2>>targets[i].x2;
        targets[i].x1=x1;
        targets[i].is_taken=0;
    }
    for(ll i=0;i<4*n;i++){
        cin>>slopes[i];
    }
    sort(slopes,slopes+4*n);
    sort(targets,targets+n,less<point>());


    miny=targets[n-1].y1;
    ll gminy=miny;
    ll lastpt=n-1;
    for(ll i=4*n-1;i>=3*n;i--){
        ll besty=gminy;
        ll bestpoint=-1;
        for(ll j=lastpt;j>=lastpt-greedy;j--){
            if(!targets[j].is_taken){
                ll tryy=targets[j].y1-targets[j].x2*slopes[i];
                if(tryy<besty){
                    besty=tryy;
                    bestpoint=j;
                }
            }
        }
        targets[bestpoint].is_taken=true;
        miny=min(miny,besty);
        while(lastpt>=0 and targets[lastpt].is_taken){
            lastpt--;
        }
    }
    cout<<miny<<endl;
    /*
    for(ll i=0;i<n;i++){
        cout<<targets[i].x1<<" "<<targets[i].y1<<" "<<targets[i].x2<<" "<<targets[i].y2<<endl;
    }
    */
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
1
2 1
1 3 6
4 6 3
1 -1 2 -2 3 -3 4 -4
*/
