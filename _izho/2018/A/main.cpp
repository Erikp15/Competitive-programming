#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e5+1;

class point2d{
public:
    ll x,y;
};

point2d top[Size],bot[Size];
pair<ll,ll> ans[Size];


void square_calc(point2d a,ll i){
    if((a.x/i+a.y/i)%2==0){
        ans[i].first++;
        ans[i].second--;
    }else{
        ans[i].first--;
        ans[i].second++;
    }
}

void solve(){
    ll n,k;
    cin>>n>>k;
    for(ll i=0;i<=n;i++){
        ans[i].first=1e18;
        ans[i].second=1e18;
    }
    for(ll i=0;i<k;i++){
        cin>>top[i].y>>top[i].x>>bot[i].y>>bot[i].x;
        top[i].y--;
        top[i].x--;
        bot[i].y--;
        bot[i].x--;
    }
    for(ll i=n/2;i>=1;i--){
        if(n%i==0){
            if((n/i)%2==1){
                ans[i].first=((n/i/2)*(n/i/2+1)*i*i)*2;
                ans[i].second=ans[i].first+i*i;
            }else{
                ans[i].first=n*n/2;
                ans[i].second=n*n/2;
            }
        }
    }
    ll best_ans=1e18;
    for(ll i=1;i<=n/2;i++){
        if(ans[i].first!=1e18){
            for(ll j=0;j<k;j++){
                if(bot[j].x-top[j].x==1 or bot[j].x-top[j].x==1){
                    if()
                }
                point2d proper_bot,proper_top,top_right,bot_left;
                proper_bot.x=bot[j].x-(bot[j].x%i);
                proper_bot.y=bot[j].y-(bot[j].y%i);
                proper_top.x=top[j].x+i-(top[j].x%i);
                proper_top.y=top[j].y+i-(top[j].y%i);
                if(top[j].x%i==0){
                    proper_top.x=top[j].x;
                }
                if(top[j].y%i==0){
                    proper_top.y=top[j].y;
                }
                ll rows=(proper_bot.x-proper_top.x)/i;
                ll cols=(proper_bot.y-proper_top.y)/i;
                ll right_cols=(bot[j].x-proper_top.x)%i;
                ll bot_rows=(bot[j].y-proper_top.y)%i;
                ll top_rows=(proper_bot.y-top[j].y)%i;
                ll left_cols=(proper_bot.x-top[j].x)%i;
                top_right.x=bot[j].x;
                top_right.y=top[j].y;
                bot_left.x=top[j].x;
                bot_left.y=bot[j].y;
                -
                if(cols%2==1 and rows%2==1){
                    ans[i].first+=i*i;
                    ans[i].second-=i*i;
                }
                if(cols%2==1){
                    if(rows%2==1){
                        ans[i].first+=i*bot_rows;
                        ans[i].second-=i*bot_rows;
                        ans[i].first+=i*top_rows;
                        ans[i].second-=i*top_rows;
                    }else{
                        ans[i].first-=i*bot_rows;
                        ans[i].second+=i*bot_rows;
                        ans[i].first-=i*top_rows;
                        ans[i].second+=i*top_rows;
                    }
                }
                if(rows%2==1){
                    if(cols%2==1){
                        ans[i].first-=i*right_cols;
                        ans[i].second+=i*right_cols;
                        ans[i].first-=i*left_cols;
                        ans[i].second+=i*left_cols;
                    }else{
                        ans[i].first+=i*right_cols;
                        ans[i].second-=i*right_cols;
                        ans[i].first+=i*left_cols;
                        ans[i].second-=i*left_cols;
                    }
                }
                square_calc(top[j],i);
                square_calc(bot[j],i);
                square_calc(top_right,i);
                square_calc(bot_left,i);
            }
            best_ans=min(best_ans,min(ans[i].first,ans[i].second));
        }
    }
    cout<<best_ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}
/*
2 0

4 1
1 1 1 4

6 6
6 1 6 1
6 2 6 2
6 3 6 3
6 4 6 4
6 5 6 5
6 6 6 6

6 8
3 3 3 3
1 2 1 2
3 4 3 4
5 5 5 5
4 3 4 3
4 4 4 4
2 1 2 1
3 6 3 6
*/
