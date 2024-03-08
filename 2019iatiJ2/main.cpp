#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class point{
    ll x,y,id;
};
class xgreater{
    bool operator <(const point& a,const point& b){
        return a.x<b.x;
    }
};
class ygreater{
    bool operator >(const point& a,const point& b){
        return a.y<b.y;
    }
};

    ll n,ex_total=0,in_total=0;
    set<point,xgreater()> x_axis[100001];
    set<point,ygreater()> y_axis[100001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(ll i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        x_axis[y].insert(x);
        y_axis[x].insert(y);

    }
    cout << "Hello world!" << endl;
    return 0;
}
