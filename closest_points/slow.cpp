#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ld dist(pair<ll,ld> p1,pair<ll,ll> p2){
    return sqrt((p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second));
}

const ll Size=1e5+1;
pair<ll,ll> a[Size];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fstream myfile("C:/programs/closest_points/testcase.txt", ios_base::in);
    ll n;
    ll b;
    for(ll i=0;myfile>>b;i++){
        if(i==0){
            n=b;
        }else{
            if(i%2==0){
                a[(i-1)/2].second=b;
            }else{
                a[i/2].first=b;
            }
        }
    }
    ld ans=1e18;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(i!=j)
                ans=min(ans,dist(a[i],a[j]));
        }
    }
    cout << ans << endl;
    return 0;
}
