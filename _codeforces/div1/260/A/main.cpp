#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=100001;
    ll n,a[Size],radix[Size],dp_ex[Size],dp_in[Size],points_per[Size];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        radix[a[i]]++;
    }
    for(ll i=0;i<=100000;i++){
        points_per[i]=radix[i]*i;
    }
    dp_in[0]=points_per[0];
    for(ll i=1;i<=100000;i++){
        dp_in[i]=dp_ex[i-1]+points_per[i];
        dp_ex[i]=max(dp_in[i-1],dp_ex[i-1]);
    }
    cout<<max(dp_in[100000],dp_ex[100000])<<endl;
    return 0;
}
/*
10
1 2 3 4 5 6 7 8 9 10
30

10
10 9 9 8 11 12 11 8 12 9
51

12
4 5 2 3 5 5 2 5 5 4 4 4
29

1
10
10

100
6 6 6 6 7 7 7 7 7 7 7 8 9 6 6 6 6 6 6 6 6 7 7 7 7 7 7 7 7 7 8 8 8 8 8 8 8 8 8 9 9 9 9 9 9 9 6 6 6 6 6 6 6 6 7 7 7 7 8 8 8 9 9 9 6 6 6 7 7 7 7 7 8 8 8 8 8 8 8 8 8 9 9 9 9 9 9 9 6 7 7 7 7 7 7 7 7 7 9 9
418
*/
