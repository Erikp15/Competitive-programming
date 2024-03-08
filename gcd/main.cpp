#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a,ll b,ll& x,ll& y){
    if(!b){
        x=1;
        y=0;
        return a;
    }
    ll c=gcd(b,a%b,x,y),tmp=y;
    y=x-y*a/b;
    x=tmp;
    return c;
}

void dio_sol(ll a,ll b,ll c,ll min_x,ll max_x,ll min_y,ll max_y){
    ll x,y;
    ll g=gcd(a,b,x,y);
    if(c%g){
        cout<<false<<endl;
    }else{
        x+=(b/g); y-=(a/g);
        ll x_range_s,x_range_e,y_range_s,y_range_e;
        x_range_s=x-floor((x-min_x)/x+1)*b/g;
        x_range_e=x-floor((x-max_x)/x-1)*b/g;
        if(x_range_e>max_x)x_range_s-=b/g;
        if(x_range_s<min_x)x_range_e+=b/g;
        y_range_s=x-floor((y-min_y)/x+1)*b/g;
        y_range_e=x-floor((y-max_y)/x-1)*b/g;
        if(y_range_e>max_y)y_range_s-=b/g;
        if(y_range_s<min_y)y_range_e+=b/g;
        cout<<(min(x_range_e,y_range_e)-max(x_range_s,y_range_s))*g/b+1<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll a,b,c,min_x,max_x,min_y,max_y;
    cin>>a>>b>>c>>min_x>>max_x>>min_y>>max_y;
    dio_sol(a,b,c,min_x,max_x,min_y,max_y);
    return 0;
}
