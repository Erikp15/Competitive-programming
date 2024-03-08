#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    void solve(){
        ll x1,y1,x2,y2,w,h,w2,h2;
        cin>>w>>h>>x1>>y1>>x2>>y2>>w2>>h2;
        ll dist_top=h-y2;
        ll dist_bot=y1;
        ll dist_left=x1;
        ll dist_right=w-x2;
        ll best_x=max(dist_left,dist_right);
        ll best_y=max(dist_top,dist_bot);
        if(x2-x1+w2>w){
            best_x=1e18;
        }else{
            best_x=min(max(w2-x1,(ll)0),max(x2-w+w2,(ll)0));
        }
        if(y2-y1+h2>h){
            best_y=1e18;
        }else{
            best_y=min(max(h2-y1,(ll)0),max(y2-h+h2,(ll)0));
        }
        if(best_x==1e18 and best_y==1e18){
            cout<<-1<<"\n";
            return;
        }
        double sol=min(best_x,best_y);
        cout<<double(sol)<<fixed<<setprecision(9)<<endl;
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

