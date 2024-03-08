#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll n=1e6+1;

set<ll> sorted;
ll radix[n];
ll a[n];

vector<ll> merge_sort(ll l,ll r){
    vector<ll> ans;
    if(l==r){
        ans.push_back(a[l]);
        ans.push_back(1e18);
        return ans;
    }else{
        ll mid=(l+r)/2;
        vector<ll> r1=merge_sort(l,mid);
        vector<ll> r2=merge_sort(mid+1,r);
        for(ll p1=0,p2=0;p1<r1.size()-1 or p1<r1.size()-1;){
            if(r1[p1]<r2[p2]){
                ans.push_back(r1[p1]);
                if(p1<r1.size()-1){
                    p1++;
                }
            }else{
                ans.push_back(r2[p2]);
                if(p2<r2.size()-1){
                    p2++;
                }
            }
        }
        ans.push_back(1e18);
        return ans;
    }
}


int main(){
    for(ll i=0;i<n;i++){
        a[i]=n-i-1;
        //sorted.insert(a[i]);
        radix[a[i]]++;
    }
    //sort(a,a+n);
/*
    for(ll i=0;i<n;i++){
        for(ll j=n-1;j>=0;j--){
            if(a[j]>a[j-1]){
                swap(a[j],a[j-1]);
            }
        }
    }
    */
    //vector<ll> yes=merge_sort(0,n-1);
    return 0;
}
