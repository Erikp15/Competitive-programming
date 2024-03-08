#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll t;
    cin>>t;
    for(ll i=0;i<t;i++){
        ll n,a[51];
        cin>>n;
        for(ll j=0;j<n;j++){
            cin>>a[j];
        }
        bool is_sort=true;
        for(ll j=1;j<n;j++){
            if(a[j]<=a[j-1]){
                if(a[0]!=1 and a[n-1]!=n){
                    if(a[0]==n and a[n-1]==1){
                        cout<<3<<endl;
                        cout<<endl;
                        is_sort=false;
                        break;
                    }else{
                        cout<<2<<endl;
                        cout<<endl;
                        is_sort=false;
                        break;
                    }
                }else{
                    cout<<1<<endl;
                    cout<<endl;
                    is_sort=false;
                    break;
                }
            }
        }
        if(is_sort)cout<<0<<endl;
        cout<<endl;
    }
    return 0;
}
