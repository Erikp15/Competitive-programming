#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll Size=1e2+1;

pair<ll,ll> querys[Size];
ll a[Size];
ll n,q;
bool is_zero[Size];


void solve(){
    ll n,q,c;
    cin>>n>>q>>c;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==0){
            is_zero[i]=1;
        }
    }
    for(ll i=0;i<q;i++){
        cin>>querys[i].first>>querys[i].second;
        querys[i].first--;
        querys[i].second--;
    }
    sort(querys,querys+q);
    ll largest=0,q_pointer=0;
    for(ll i=0;i<n;i++){
        if(a[i]==0){
            a[i]=1;
        }
        largest=max(largest,a[i]);
        pair<ll,ll> curr_query=querys[q_pointer];
        while(curr_query.first==i){
            if(is_zero[curr_query.second]==1){
                a[curr_query.second]=max(a[curr_query.second],largest+1);
                if(largest+1>c){
                    cout<<-1<<endl;
                    return;
                }
            }else{
                if(a[curr_query.second]<=largest){
                    cout<<-1<<endl;
                    return;
                }
            }
            q_pointer++;
            curr_query=querys[q_pointer];
        }
    }
    for(ll i=0;i<n;i++){
        if(i==n-1){
            cout<<a[i]<<endl;
        }else{
            cout<<a[i]<<" ";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
0 0 0 0 1 6 0 6
1 3
6 7
4 7
2 3
1 1 2 6 1 6 7 6
*/
