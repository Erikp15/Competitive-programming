#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    const ll Size=1e2+1;
    ll n,m,k;
    char ans[Size][Size];

    void solve(){
        cin>>n>>m>>k;
        if(n%2==0 and m%2==0){
            if(k%2==0){
                cout<<"Yes"<<"\n";
                ll i=0,j=0;
                bool is_black=false;
                for(i=0;i<=k/m;i+=2){
                    for(j=0,is_black=!is_black;j<m;j+=2,is_black=!is_black){
                        if(is_black){
                            ans[i][j]='a';
                            ans[i][j+1]='a';
                            ans[i+1][j]='b';
                            ans[i+1][j]='b';
                        }else{
                            ans[i][j]='c';
                            ans[i][j+1]='c';
                            ans[i+1][j]='d';
                            ans[i+1][j]='d';
                        }
                    }
                }
                for(j=0,is_black=!is_black;j<(k*2)%m;j+=2,is_black=!is_black){
                    if(is_black){
                        ans[i][j]='a';
                        ans[i][j+1]='a';
                        ans[i+1][j]='b';
                        ans[i+1][j]='b';
                    }else{
                        ans[i][j]='c';
                        ans[i][j+1]='c';
                        ans[i+1][j]='d';
                        ans[i+1][j]='d';
                    }
                }
                for(j=(k*2)%m,is_black=!is_black;j<m;j+=2,is_black=!is_black){
                    if(is_black){
                        ans[i][j]='a';
                        ans[i+1][j]='a';
                        ans[i][j+1]='b';
                        ans[i+1][j+1]='b';
                    }else{
                        ans[i][j]='c';
                        ans[i+1][j]='c';
                        ans[i][j+1]='d';
                        ans[i+1][j+1]='d';
                    }
                }
                for(;i<n;i+=2){
                    for(j=0,is_black=!is_black;j<m;j+=2,is_black=!is_black){
                        if(is_black){
                            ans[i][j]='a';
                            ans[i+1][j]='a';
                            ans[i][j+1]='b';
                            ans[i+1][j+1]='b';
                        }else{
                            ans[i][j]='c';
                            ans[i+1][j]='c';
                            ans[i][j+1]='d';
                            ans[i+1][j+1]='d';
                        }
                    }
                }
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
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                cout<<ans[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}
/*

*/
