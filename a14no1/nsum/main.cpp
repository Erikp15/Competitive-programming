#include <iostream>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    ll sum=0,l=1,r=0,sum_count=0;
    for(ll i=1;i<=n;i++){
        if(sum==n){
            sum_count++;
            sum-=l;
            l++;
            continue;
        }
        if(sum<n){
            r++;
            sum+=r;
            continue;
        }
        if(sum>n){
            sum-=l;
            l++;
        }
    }
    cout<<sum_count+1<<endl;
    return 0;
}
