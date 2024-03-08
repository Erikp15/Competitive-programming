#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll a,b;
    cin>>a>>b;
    ll s=a;
    if(s>10000000){
        s=sqrt(s);
    }
    for(ll x=0;x<=s;x++){
        if((x^b)==(a-x)){
            cout<<x<<" "<<a-x<<endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
