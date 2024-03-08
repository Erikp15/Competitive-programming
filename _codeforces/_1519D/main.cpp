#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=5001;
    ll ans=0,product[Size],mid_p[Size],reversed_p[Size],mid_r_p[Size];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,a[Size],b[Size],best_diff=0;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    for(ll i=0;i<n;i++){
        cin>>b[i];
    }
    for(ll i=0;i<n;i++){
        ans+=a[i]*b[i];
    }
    for(ll i=0;i<n;i++){
        product[i]=a[i]*b[i];
        reversed_p[i]=a[i]*b[i];
        for(ll j=1;i+j<n and i-j>=0;j++){
            product[i]=product[i]+a[i-j]*b[i-j]+a[i+j]*b[i+j];
            reversed_p[i]=reversed_p[i]+a[i+j]*b[i-j]+a[i-j]*b[i+j];
            best_diff=max(best_diff,reversed_p[i]-product[i]);
        }
    }
    for(ll i=0;i<n-1;i++){
        for(ll j=1;i+j<n and i-j+1>=0;j++){
            mid_p[i]=mid_p[i]+a[i-j+1]*b[i-j+1]+a[i+j]*b[i+j];
            mid_r_p[i]=mid_r_p[i]+a[i+j]*b[i-j+1]+a[i-j+1]*b[i+j];
            best_diff=max(best_diff,mid_r_p[i]-mid_p[i]);
        }
    }
    ans+=best_diff;
    cout<<ans<<"\n";
    return 0;
}
/*
5
2 3 2 1 3
1 3 2 4 2
29

2
13 37
2 4
174

6
1 8 7 6 3 6
5 9 6 8 8 6
235
*/
