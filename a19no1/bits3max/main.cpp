#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll count_0=0,count_1=0;
    string bits;
    cin>>bits;
    for(ll i=0;i<(ll)bits.size();i++){
        if(bits[i]=='0'){
            count_0++;
        }else{
            count_1++;
        }
    }
    cout<<count_0<<" "<<count_1<<endl;
    return 0;
}
