#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=2e5+1;
bool d1[26],d2[26][26],d3[26][26][26];

void solve(){
    ll n;
    cin>>n;
    string a;
    cin>>a;
    for(ll i=0;i<26;i++){
        d1[i]=false;
        for(ll j=0;j<26;j++){
            d2[i][j]=false;
            for(ll k=0;k<26;k++){
                d3[i][j][k]=false;
            }
        }
    }
    for(ll i=0;i<n;i++){
        d1[a[i]-'a']=true;
    }
    for(ll i=0;i<26;i++){
        if(!d1[i]){
            cout<<char(i+'a')<<"\n";
            return;
        }
    }
    for(ll i=1;i<n;i++){
        d2[a[i-1]-'a'][a[i]-'a']=true;
    }
    for(ll i=0;i<26;i++){
        for(ll j=0;j<26;j++){
            if(!d2[i][j]){
                cout<<char(i+'a')<<char(j+'a')<<"\n";
                return;
            }
        }
    }
    for(ll i=2;i<n;i++){
        d3[a[i-2]-'a'][a[i-1]-'a'][a[i]-'a']=true;
    }
    for(ll i=0;i<26;i++){
        for(ll j=0;j<26;j++){
            for(ll k=0;k<26;k++){
                if(!d3[i][j][k]){
                    cout<<char(i+'a')<<char(j+'a')<<char(k+'a')<<"\n";
                    return;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
1
28
qaabzwsxedcrfvtgbyhnujmiklop

1
13
cleanairactbd

1
10
aannttoonn
*/
