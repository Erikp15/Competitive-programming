#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    ll all_nums[100001];

int main(){
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n,m;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>all_nums[i];
    }
    cin>>m;
    for(ll j=0;j<m;j++){
        ll t,l,r;
        cin>>t>>l>>r;
        if(t==1){
            all_nums[l-1]=r;
            continue;
        }
        ll each_num_count[100001];
        for(ll i=0;i<100001;i++)each_num_count[i]=0;
        for(ll i=0;i<=r-l;i++){
            each_num_count[all_nums[i+l-1]]++;
        }
        for(ll i=1;i<=r-l+1;i++){
            if(each_num_count[i]!=1){
                cout<<"NO"<<endl;
                break;
            }
            if(i==r-l+1){
                cout<<"YES"<<endl;
            }
        }
    }
    return 0;
}
/*
5
5 9 5 9 7
11
2 1 5
1 2 1
1 1 4
2 1 1
2 1 5
1 4 3
2 1 5
1 5 2
2 1 5
1 5 1
2 1 5

NO
NO
NO
NO
YES
NO

*/
