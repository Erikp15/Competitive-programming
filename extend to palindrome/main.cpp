#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void manacher_sum(string& a){
    vector<ll> d_even(a.size()-1,0),d_odd(a.size(),1);

    ll l_even=0,r_even=0;
    for(ll i=0;i<(ll)d_even.size();i++){
        ll k=(i>=r_even) ? 0 : min(d_even[l_even+r_even-i-1],r_even-i);
        while(i-k>=0 and i+k<d_even.size() and a[i-k]==a[i+k+1]){
            k++;
        }
        d_even[i]=k--;
        if(i+k+1>r_even){
            l_even=i-k;
            r_even=i+k+1;
        }
    }
    ll l_odd=0,r_odd=0;
    for(ll i=0;i<(ll)a.size();i++){
        ll k=(i>=r_odd) ? 1 : min(d_odd[l_odd+r_odd-i],r_odd-i);
        while(i-k>=0 and i+k<d_odd.size() and a[i-k]==a[i+k]){
            k++;
        }
        d_odd[i]=k--;
        if(i+k>r_odd){
            l_odd=i-k;
            r_odd=i+k;
        }
    }
    ll best_l;
    if(r_odd>r_even){
        best_l=l_odd;
    }else{
        best_l=l_even;
    }
    if(r_odd==r_even){
        best_l=min(l_odd,l_even);
    }
    cout<<a;
    for(ll i=best_l-1;i>=0;i--){
        cout<<a[i];
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a;
    while(cin>>a){
        manacher_sum(a);
    }
    return 0;
}
/*
abbbaabba

amanaplanacanal

aaaa
abba
amanaplanacanal
xyz
*/
