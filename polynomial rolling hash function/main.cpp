#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll hash_function(string& a){
    ll p=53;
    ll m=1e9+9;
    ll hash_value=0;
    ll pow_i=1;
    for(ll i=0;i<(ll)a.size();i++){
        if(a[i]<'a'){
            hash_value+=((a[i]-'A'+1)*pow_i)%m;
        }else{
            hash_value+=((a[i]-'a'+1)*pow_i)%m;
        }
        pow_i=(pow_i*p)%m;
    }
    return hash_value;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a;
    cin>>a;
    cout<<hash_function(a)<<endl;
    return 0;
}
