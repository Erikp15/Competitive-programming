#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e3+1;
string ans;

void solve(){
    ll n;
    cin>>n;
    ll a[Size];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    stack<ll> ans;
    vector<ll> output;
    for(ll i=0;i<n;i++){
        if(a[i]!=1){
            while(ans.top()+1!=a[i]){
                ans.pop();
                if(ans.empty())break;
            }
            ans.pop();
        }
        ans.push(a[i]);
        while(!ans.empty()){
            output.push_back(ans.top());
            ans.pop();
        }
        reverse(output.begin(),output.end());
        for(auto itr:output){
            ans.push(itr);
        }
        for(ll j=0;j<output.size();j++){
            cout<<output[j];
            if(j!=output.size()-1)cout<<".";
        }
        cout<<endl;
        output.clear();
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
