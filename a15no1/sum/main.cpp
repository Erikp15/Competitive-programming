#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    ll nums[1000001],radix_index[2001];
    bool radix_exists[2001];

int main(){
    //freopen("sum.05.in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>nums[i];

        if(radix_exists[nums[i]])continue;
        radix_exists[nums[i]]=true;
        radix_index[nums[i]]=i;
    }
    ll s;
    cin>>s;
    ll min_index_first=n,min_index_second=n;
    bool is_pos=false;
    for(ll i=0,j=s;i<=1000;i++,j=s-i){
        if(!radix_exists[i]){
            continue;
        }
        if(!radix_exists[j]){
            continue;
        }
        is_pos=true;
        if(min(radix_index[i],radix_index[j])==min_index_first){
            if(max(radix_index[i],radix_index[j])<min_index_second){
                min_index_second=max(radix_index[i],radix_index[j]);
                continue;
            }
            continue;
        }
        if(min(radix_index[i],radix_index[j])<min_index_first){
            min_index_first=min(radix_index[i],radix_index[j]);
            min_index_second=max(radix_index[i],radix_index[j]);
        }
    }
    if(is_pos){
        cout<<min_index_first+1<<" "<<min_index_second+1<<endl;
    }else{
        cout<<"0 0"<<endl;
    }
    return 0;
}
/*
10
3 2 2 3 3 1 5 3 1 1
6
1 1

10
7 2 2 3 3 1 5 3 5 1
7
2 7
*/
