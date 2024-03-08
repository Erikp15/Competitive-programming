#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=3001;
    ll a[Size],sorted_a[Size];
    map<ll,ll> num_2_sort;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    for(ll m=0;m<t;m++){
        ll n,ans=0,lis=0;
        cin>>n;
        for(ll i=0;i<Size;i++){
            a[i]=-1;
            sorted_a[i]=-1;
        }
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        for(ll i=0;i<n;i++){
            sorted_a[i]=a[i];
        }
        sort(sorted_a,sorted_a+n);
        for(ll i=0;i<n;i++){
            num_2_sort[sorted_a[i]]=i;
        }
        for(ll i=0;i<n;i++){
            for(ll j=i,p=num_2_sort[a[i]];j<n;j++){
                if(a[j]==sorted_a[p]){
                    p++;
                    lis++;
                }
            }
            ans=max(ans,lis);
            lis=0;
        }
        cout<<n-ans<<"\n";
    }
    return 0;
}
/*
2
10
3 7 1 6 2 9 5 4 0 8
10
8 2 3 6 0 9 4 7 5 1
8
6
*/
