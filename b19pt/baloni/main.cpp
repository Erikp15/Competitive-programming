#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    ll n,t,bal_color[100002],colorness=1;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    cin>>bal_color[1];
    ll curr_color=bal_color[1];
    for(ll i=2;i<=n;i++){
        cin>>bal_color[i];
        if(bal_color[i]!=curr_color){
            colorness++;
            curr_color=bal_color[i];
        }
    }
    cin>>t;
    for(ll i=0;i<t;i++){
        ll q;
        cin>>q;
        if(q==1){
            ll a;
            cin>>a;
            if(bal_color[a-1]!=bal_color[a] and bal_color[a-1]!=bal_color[a-2]){
                if(bal_color[a-2]==bal_color[a]){
                    colorness-=2;
                }else{
                    colorness--;
                }
            }
            bal_color[a-1]=0;
            continue;
        }
        if(q==2){
            ll a;
            cin>>a;
            if(bal_color[a-1]!=bal_color[a] and bal_color[a-1]!=bal_color[a-2]){
                if(bal_color[a-2]==bal_color[a]){
                    colorness-=2;
                }else{
                    colorness--;
                }
            }
            bal_color[a-1]=0;
            continue;
        }
    }
    cout << "Hello world!" << endl;
    return 0;
}
