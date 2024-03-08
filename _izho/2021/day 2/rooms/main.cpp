#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e6+10;

ll a[Size],b[Size],ans[Size],cost_left[Size],cost_right[Size];
ll n;
bool zero=true;

void find_ans(ll start){
    ll l=start,r=start+1;
    ll curr_exp=a[start],curr_cost=0;
    while(l>0 and r<=n+1 and curr_exp<100){
        if(b[l]<=b[r]){
            ll paid=max(b[l]-curr_exp,(ll)0);
            curr_cost+=paid;
            l--;
            curr_exp+=a[l]+paid;
        }else{
            ll paid=max(b[r]-curr_exp,(ll)0);
            curr_cost+=paid;
            curr_exp+=a[r]+paid;
            r++;
        }
    }
    ans[start]=curr_cost;
}

void solve(){
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=0)
            zero=false;
    }
    for(ll i=1;i<=n+1;i++){
        cin>>b[i];
        cost_left[i]=max(cost_left[i-1],b[i]);
    }
    for(ll i=n+1;i>0;i--){
        cost_right[i]=max(cost_right[i+1],b[i]);
    }
    if(n<=5000){
        for(ll i=1;i<=n;i++){
            find_ans(i);
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;
    }
    if(zero){
        for(ll i=1;i<=n;i++){
            cout<<min(cost_left[i],cost_right[i+1])<<" ";
        }
    }else{
        for(ll i=1;i<=n;i++){
            cout<<max(b[i]-a[i],(ll)0)<<" ";
        }
    }
    cout<<endl;
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
5
0 0 0 0 0
1 8 4 4 1 9

5
6 3 4 1 3
1 4 4 4 9 9
0 1 0 3 6

3
2 1 3
9 8 5 7
6 4 3

3
1 3 3
10 5 5 6
1 1 2
*/
