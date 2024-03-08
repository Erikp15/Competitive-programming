#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=3e5+1;
    ll n,m,k;


    bool take_m(){
        if(n%2!=0 and (n*m/2-k)%2!=0){
            return false;
        }
        if(k%(m/2)==0 and (n*m/2-k)%2==0){
            return true;
        }else{
            return false;
        }
    }

    bool take_n(){
        if(m%2!=0 and k%2!=0){
            return false;
        }
        if((n*m/2-k)%(n/2)==0 and k%2==0){
            return true;
        }else{
            return false;
        }
    }

    void solve(){
        cin>>n>>m>>k;
        if(n%2==0 and m%2==0){
            if(k%2==0){
                cout<<"Yes"<<"\n";
                return;
            }else{
                cout<<"No"<<"\n";
                return;
            }
        }
        if(n%2==0){
            if((n*m/2-k)-(n/2)<0){
                cout<<"No"<<"\n";
                return;
            }
            if(((n*m/2-k)-(n/2))%2==0){
                cout<<"Yes"<<"\n";
                return;
            }else{
                cout<<"No"<<"\n";
                return;
            }

        }else{
            if(k-(m/2)<0){
                cout<<"No"<<"\n";
                return;
            }
            if((k-(m/2))%2==0){
                cout<<"Yes"<<"\n";
                return;
            }else{
                cout<<"No"<<"\n";
                return;
            }
        }
    }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*

*/
