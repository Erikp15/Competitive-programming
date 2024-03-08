#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll Size=1e6+1, mod=1e9+7;
ll n;

void solve(){
    cin>>n;
    ll state=0,gap_size=1;
    bool white=1;
    ll a1=0,a2=0,b1=0,b2=0;
    n-=gap_size;
    while(n>=0){
        if(state==0){
            if(white){
                if(gap_size%2==0){
                    a1+=gap_size/2;
                }else{
                    a1+=gap_size/2+1;
                    white=0;
                }
                a2+=gap_size/2;
            }else{
                if(gap_size%2==0){
                    a2+=gap_size/2;
                }else{
                    a2+=gap_size/2+1;
                    white=1;
                }
                a1+=gap_size/2;
            }
            state=1;
        }else{
            if(white){
                if(gap_size%2==0){
                    b1+=gap_size/2;
                }else{
                    b1+=gap_size/2+1;
                    white=0;
                }
                b2+=gap_size/2;
            }else{
                if(gap_size%2==0){
                    b2+=gap_size/2;
                }else{
                    b2+=gap_size/2+1;
                    white=1;
                }
                b1+=gap_size/2;
            }
            state=0;
        }
        gap_size+=4;
        n-=gap_size;
    }
    gap_size+=n;
    if(state==0){
        if(white){
            if(gap_size%2==0){
                a1+=gap_size/2;
            }else{
                a1+=gap_size/2+1;
                white=0;
            }
            a2+=gap_size/2;
        }else{
            if(gap_size%2==0){
                a2+=gap_size/2;
            }else{
                a2+=gap_size/2+1;
                white=1;
            }
            a1+=gap_size/2;
        }
        state=1;
    }else{
        if(white){
            if(gap_size%2==0){
                b1+=gap_size/2;
            }else{
                b1+=gap_size/2+1;
                white=0;
            }
            b2+=gap_size/2;
        }else{
            if(gap_size%2==0){
                b2+=gap_size/2;
            }else{
                b2+=gap_size/2+1;
                white=1;
            }
            b1+=gap_size/2;
        }
        state=0;
    }
    cout<<a1<<" "<<a2<<" "<<b1<<" "<<b2<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=200;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
