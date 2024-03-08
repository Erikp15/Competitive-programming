#include <iostream>

using namespace std;

typedef long long ll;

    ll state[101][101];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,dig_so_far=1,prev_dig=1;
    cin>>n;
    for(ll i=3;i<=n;i++){
        ll tmp=dig_so_far;
        dig_so_far=(dig_so_far+prev_dig)%100;
        prev_dig=tmp;
    }
    if(dig_so_far<10){
        cout<<"0"<<dig_so_far<<endl;
    }else{
        cout<<dig_so_far<<endl;
    }
    return 0;
}
