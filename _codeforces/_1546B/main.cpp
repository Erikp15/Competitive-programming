#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=100001;
    ll sum_1[Size][26];
    string a[2*Size],ans;

    void solve(){
        ll n,m;
        cin>>n>>m;
        for(ll i=0;i<m;i++){
            for(ll j=0;j<26;j++){
                sum_1[i][j]=0;
            }
        }
        ans="";
        for(ll i=0;i<2*n-1;i++){
            cin>>a[i];
        }

        for(ll i=0;i<m;i++){
            for(ll j=0;j<n;j++){
                sum_1[i][a[j][i]-'a']++;
            }
            for(ll j=n;j<2*n-1;j++){
                sum_1[i][a[j][i]-'a']--;
            }
            for(ll j=0;j<26;j++){
                if(sum_1[i][j]!=0){
                    cout<<(char)(j+'a')<<flush;
                    sum_1[i][j]--;
                }
            }
        }
        cout<<ans<<"\n"<<flush;
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
3 5
asyutz
myppic
abcdef
mspuiz
ayyptc

abcdef

1
3 5
xyzklm
abcdef
suckam
ayzdem
xbcklf

5 6
abcdef
uuuuuu
ekekek
kekeke
xyzklm
xbcklf
eueueu
ayzdem
ukukuk
*/
