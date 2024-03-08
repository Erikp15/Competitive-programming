#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,a=1,b=1,c=1,final_a=1,final_b=1,final_c=1,area=100000000,par=100000000;
    cin>>n;
    for(a=1;2*a+2*a+2<=n;a++){
        for(b=1; b<=a and 2*(a*b)+2*a+2*b<=n; b++){
            for(c=1; c<=b and 2*(a*b)+2*(a*c)+2*(b*c)<=n; c++){
                ll cubes_used=0;
                for(ll l=1; cubes_used<=n; l++){
                    cubes_used+=2*(a*b)+2*(a*c)+2*(b*c);
                    cubes_used+=4*a*(l-1)+4*b*(l-1)+4*c*(l-1);
                    for(ll i=2;i<l;i++){
                        cubes_used+=8*(l-i);
                    }
                    if(cubes_used==n){
                        if(2*(a*b)+2*(a*c)+2*(b*c)<par){
                            final_a=a;
                            final_b=b;
                            final_c=c;
                            par=2*(a*b)+2*(a*c)+2*(b*c);
                            area=a*b*c;
                            continue;
                        }
                        if(2*(a*b)+2*(a*c)+2*(b*c)==par){
                            if(a*b*c<area){
                                final_a=a;
                                final_b=b;
                                final_c=c;
                                par=2*(a*b)+2*(a*c)+2*(b*c);
                                area=a*b*c;
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<final_a<<"x"<<final_b<<"x"<<final_c<<endl;
    return 0;
}
