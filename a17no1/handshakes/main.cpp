#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin>>n;
    ll best_so_far=0,worst_so_far=0;
    ll all_workers[200001];
    for(ll i=0;i<n;i++){
        cin>>all_workers[i];
        if(all_workers[i]==0){
            worst_so_far=0;
            continue;
        }
        best_so_far=max(best_so_far+1,all_workers[i]);
        if(all_workers[i]==i)worst_so_far++;
        worst_so_far=min(worst_so_far,all_workers[i]);
    }
    cout<<best_so_far<<endl<<worst_so_far<<endl;
    return 0;
}
