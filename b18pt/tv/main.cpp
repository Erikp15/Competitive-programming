#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    ll n,q,range_sum[500001];
    string init_seq,imp_seq;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>init_seq;
    ll imp_range=n-1;
    for(;;imp_range--){
         if(init_seq[imp_range]=='o')break;
         if(imp_range==0){break;}
    }
    for(ll i=imp_range;i<n;i++){
        imp_seq+=init_seq[i];
    }
    range_sum[0]=1;
    for(ll i=1;i<n-imp_range-1;i++){

    }
    return 0;
}
