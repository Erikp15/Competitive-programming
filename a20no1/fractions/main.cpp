#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    ll answer[1000001];

bool gcd(ll a,ll b){
    ll larger=max(a,b), smaller=min(a,b);
    while(larger-smaller>0){
        ll new_num=larger-smaller;
        larger=max(new_num,smaller);
        smaller=min(new_num,smaller);
    }
    if(smaller==1){
        return true;
    }else{
        return false;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    ll sum_so_far=0;
    for(ll i=2;i<=n;i++){
        for(ll j=1;j<i;j++){
            if(gcd(i,j)){
                sum_so_far++;
                //cout<<j<<"/"<<i<<" ";
            }
        }
    }
    cout<<sum_so_far+1<<endl;
    return 0;
}
