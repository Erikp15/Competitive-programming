#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e6+1;

ll a[Size];
unordered_map<ll,ll> first_end;
vector<ll> all_bests;

void solve(){
    ll s,t,n;
    cin>>n>>s>>t;
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    if(s==t){
        cout<<0<<endl;
        return;
    }
    if(s<t){
        ll best_price=1e18,ans=0;
        for(ll i=s;i<t;i++){
            if(best_price>a[i]){
                first_end[best_price]=i;
                best_price=a[i];
                all_bests.push_back(a[i]);
            }
            ans+=best_price;
        }
        first_end[best_price]=t;
        reverse(all_bests.begin(),all_bests.end());
        ll dist_so_far=0,ans_begin=s;
        best_price=a[s];
        for(ll i=s-1;i>0;i--){
            dist_so_far+=best_price;
            if(best_price<=a[i])
                continue;
            best_price=a[i];
            ll to_remove=0,final_stop=0;
            for(ll j=all_bests.size()-1;all_bests[j]>best_price and j>=0;j--){
                ll curr=all_bests[j],prev=all_bests[j+1];
                if(j!=all_bests.size()-1){
                    to_remove+=(first_end[curr]-first_end[prev])*curr;
                }else{
                    to_remove+=(first_end[curr]-ans_begin)*curr;
                }
                final_stop=first_end[curr];
            }
            if((final_stop-i)*a[i]+dist_so_far<to_remove){
                while(*all_bests.rbegin()>best_price and !all_bests.empty()){
                    all_bests.pop_back();
                }
                all_bests.push_back(a[i]);
                first_end[a[i]]=final_stop;
                ans-=to_remove;
                ans+=(final_stop-i)*a[i]+dist_so_far;
                dist_so_far=0;
                ans_begin=i;
            }
        }
        cout<<ans<<endl;
    }
    if(s>t){
        ll best_price=1e18,ans=0;
        for(ll i=s;i>t;i--){
            if(best_price>a[i]){
                first_end[best_price]=i;
                best_price=a[i];
                all_bests.push_back(a[i]);
            }
            ans+=best_price;
        }
        first_end[best_price]=t;
        reverse(all_bests.begin(),all_bests.end());
        ll dist_so_far=0,ans_begin=s;
        best_price=a[s];
        for(ll i=s+1;i<=n;i++){
            dist_so_far+=best_price;
            if(best_price<=a[i])
                continue;
            best_price=a[i];
            ll to_remove=0,final_stop=0;
            for(ll j=all_bests.size()-1;all_bests[j]>best_price and j>=0;j--){
                ll curr=all_bests[j],prev=all_bests[j+1];
                if(j!=all_bests.size()-1){
                    to_remove+=(first_end[prev]-first_end[curr])*curr;
                }else{
                    to_remove+=(ans_begin-first_end[curr])*curr;
                }
                final_stop=first_end[curr];
            }
            if((i-final_stop)*a[i]+dist_so_far<to_remove){
                while(*all_bests.rbegin()>best_price and !all_bests.empty()){
                    all_bests.pop_back();
                }
                all_bests.push_back(a[i]);
                first_end[a[i]]=final_stop;
                ans-=to_remove;
                ans+=(i-final_stop)*a[i]+dist_so_far;
                dist_so_far=0;
                ans_begin=i;
            }
        }
        cout<<ans<<endl;
    }
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
5 1 4
3 3 3 3 3
9

5 1 5
5 3 4 2 1
13

7 4 7
1 1 1 3 4 6 7
7

5 4 2
3 2 5 5 1
8

10 9 4
1 8 5 7 3 6 8 2 6 8
14

13 4 13
3 5 4 14 15 14 13 1 1 1 1 1 1

13 10 1
1 1 1 1 1 1 13 14 15 14 4 5 3
25


20 9 20
1 20 20 20 20 20 20 20 20 11 20 20 20 20 20 20 20 20 20 20
119
*/
