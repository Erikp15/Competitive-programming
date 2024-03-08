#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    ll even_count[100001],odd_count[100001];
    string a;

void manacher_for_odd(){
    ll l=0,r=0;
    for(ll i=0;i<a.size();i++){
        ll k=1;
        if(i<=r){
            k=odd_count[l+r-i];
        }
        while(i-k>=0 and i+k<a.size() and a[i-k]==a[i+k]){
            k++;
        }
        odd_count[i]=k--;
        if(i+k>r){
            l=i-k;
            r=i+k;
        }
    }
}

void manacher_for_even(){
    ll l=0,r=0;
    for(ll i=0;i<a.size();i++){
        ll k=0;
        if(i<r){
            k=even_count[l+r-i-1];
        }
        while(i-k>=0 and i+k<a.size() and a[i-k]==a[i+k+1]){
            k++;
        }
        even_count[i]=k--;
        if(i+k+1>r){
            l=i-k;
            r=i+k+1;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a;
    manacher_for_odd();
    manacher_for_even();
    ll most=0;
    for(ll i=0;i<(ll)a.size();i++){
        most+=odd_count[i];
    }
    for(ll i=0;i<(ll)a.size()-1;i++){
        most+=even_count[i];
    }
    cout<<most<<endl;
    return 0;
}
/*
abbbaabba
18

amanaplanacanal
23
*/
