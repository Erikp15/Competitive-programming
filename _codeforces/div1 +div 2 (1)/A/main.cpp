#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    for(ll t1=0;t1<t;t1++){
        ll n,m,dist_left[10001],dist_right[10001];
        cin>>n>>m;
        string a;
        cin>>a;
        for(ll i=0;i<n;i++){
            dist_left[i]=100000;
            dist_right[i]=100000;
        }
        for(ll i=0;i<a.size();i++){
            if(a[i]=='1'){
                dist_left[i]=0;
                dist_right[i]=0;
                for(ll j=i-1;j>=0;j--){
                    dist_right[j]=min(dist_right[j],dist_right[j+1]+1);
                }
                for(ll j=i+1;j<n;j++){
                    dist_left[j]=min(dist_left[j],dist_left[j-1]+1);
                }
            }
        }
        for(ll i=0;i<a.size();i++){
            if(dist_left[i]==dist_right[i] and a[i]!='1'){
                cout<<'0';
                continue;
            }
            if(min(dist_left[i],dist_right[i])<=m){
                cout<<'1';
            }else{
                cout<<'0';
            }
        }
        cout<<endl;
    }
    return 0;
}
