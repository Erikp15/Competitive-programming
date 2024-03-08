#include <iostream>

using namespace std;

typedef long long ll;

    ll hash_from_0[200001];

ll hash_string(string& a){
    ll p=37;
    ll m=1e9+9;
    ll pow_p=1;
    ll hash_value=0;
    for(ll i=0;i<(ll)a.size();i++){
        hash_value+=((a[i]-'a'+1)*pow_p)%m;
        pow_p=(pow_p*p)%m;
    }
    return hash_value;
}

ll rabin_karp(string& a,string& b){, str_count=0;
    ll search_hash=hash_string(b);
    ll p=37,m=1e9+9,pow_p=1;
    hash_from_0[0]=0;
    for(ll i=1;i<=a.size();i++){
        hash_from_0[i]=(hash_from_0[i-1]+(a[i-1]-'a'+1)*pow_p)%m;
        pow_p=(pow_p*p)%m;
    }
    for(ll i=0;i<=a.size()-b.size();i++){
        ll curr_str=(hash_from_0[i+b.size()]+m-hash_from_0[i])%m;
        if(search_hash==curr_str){
            str_count++;
        }
        search_hash=(search_hash*p)%m;
    }
    return str_count;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a,b;
    cin>>a>>b;
    cout<<rabin_karp(a,b)<<endl;
    return 0;
}
