#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,str_sum=0;
    cin>>n;
    vector<ll> answers;
    ll all_players[501];
    for(ll i=0;i<n;i++){
        cin>>all_players[i];
        str_sum+=all_players[i];
    }
    if(str_sum%2!=0){
        cout<<0<<endl;
        return 0;
    }
    for(ll i=0;i<n;i++){
        for(ll j=1;j<=str_sum;j++){
            all_players[n]=i;
            bool is_friendly=true;
            for(ll j=0;j<=n;j++){
                ll new_sum=str_sum+all_players[n]-all_players[j];
                if(new_sum%2!=0){
                    is_friendly=false;
                    break;
                }
                bool knapsack[25001];
                for(ll x=0;x<25001;x++)knapsack[x]=false;
                knapsack[0]=true;
                for(ll x=0;x<j;x++){
                    vector<ll> hold_off;
                    for(ll y=0;y<=new_sum/2-all_players[x];y++){
                        if(knapsack[y]){
                            hold_off.push_back(y+all_players[x]);
                        }
                    }
                    for(ll y=0;y<(ll)hold_off.size();y++){
                        knapsack[hold_off[y]]=true;
                    }
                }
                for(ll x=j+1;x<=n;x++){
                    vector<ll> hold_off;
                    for(ll y=0;y<=new_sum/2-all_players[x];y++){
                        if(knapsack[y]){
                            hold_off.push_back(y+all_players[x]);
                        }
                    }
                    for(ll y=0;y<(ll)hold_off.size();y++){
                        knapsack[hold_off[y]]=true;
                    }
                }
                if(!knapsack[new_sum/2]){
                    is_friendly=false;
                    break;
                }
            }
            if(is_friendly){
                answers.push_back(i);
            }
        }
    }
    cout<<answers.size()<<endl;
    for(ll i=0;i<(ll)answers.size();i++){
        cout<<answers[i]<<" ";
    }
    cout<<endl;
    return 0;
}
/*
3
2 2 2
0

4
1 3 1 5
1
3

6
3 5 7 11 9 13
4
1 3 17 19

4
200 200 200 200
2
200 600
*/
