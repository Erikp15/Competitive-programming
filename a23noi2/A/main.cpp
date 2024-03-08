#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll Size=1e5+1,mod=1e9+7,p=33;
string a[10];
unordered_map<ll,ll> is_present;
ll power[26][Size];
ll n,k;

bool calc_is_present(ll length){
    is_present.clear();
    ll curr_hash=0;
    for(ll i=0;i<length;i++){
        curr_hash+=power[a[0][i]-'a'][length-i-1]%mod;
    }
    is_present[curr_hash]=0;
    for(ll i=1;i<a[0].size()-length+1;i++){
        curr_hash=((curr_hash+mod-power[a[0][i-1]-'a'][length-1])*p+(a[0][i+length-1]-'a'))%mod;
        is_present[curr_hash]=0;
    }
    for(ll j=1;j<k;j++){
        ll curr_hash=0;
        for(ll i=0;i<length;i++){
            curr_hash+=power[a[j][i]-'a'][length-i-1]%mod;
        }
        auto var=is_present.find(curr_hash);
        if(var!=is_present.end() and (*var).second==j-1)
            (*var).second=j;
        for(ll i=1;i<a[j].size()-length+1;i++){
            curr_hash=((curr_hash+mod-power[a[j][i-1]-'a'][length-1])*p+(a[j][i+length-1]-'a'))%mod;
            auto var=is_present.find(curr_hash);
            if(var!=is_present.end() and (*var).second==j-1)
                (*var).second=j;
        }
    }
    for(auto curr_hash:is_present){
        if(curr_hash.second==k-1){
            return true;
        }
    }
    return false;
}

ll binary_find(ll l,ll r){
    ll mid=(l+r)/2;
    bool curr_ans=calc_is_present(mid);
    bool next_ans=calc_is_present(mid+1);
    if(mid==1 and !curr_ans){
        return 0;
    }
    if(curr_ans and !next_ans){
        return mid;
    }
    if(curr_ans){
        return binary_find(mid+1,r);
    }else{
        return binary_find(l,mid);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(ll i=0;i<26;i++){
        power[i][0]=i;
    }
    for(ll i=1;i<Size;i++){
        for(ll j=0;j<26;j++){
            power[j][i]=power[j][i-1]*p%mod;
        }
    }
    cin>>n>>k;
    for(ll i=0;i<k;i++){
        cin>>a[i];
        a[i]+=a[i];
    }
    ll ans=binary_find(1,n);
    cout<<ans<<endl;
    return 0;
}
/*
5 2
abcde
aaaaa

5 2
fabcq
bcdda

*/
