#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll Size=3e5+1;
ll bad=-1;
ll bad2=-1;
string a;
string sbess = "bessie";
ll bbest[6];
ll bmax;


vector<ll> b_start;
vector<ll> e_end;
vector<ll> nextb;
vector<ll> pans;
vector<ll> chaincnt;

void solve(){
    cin>>a;

    ll n=a.size();
    bmax=0;
    for(ll i=0;i<n;i++){
        if(a[i]=='b'){
            for(ll d=0;d<6;d++){
                bbest[d]=-1;
            }
            bbest[0]=i;
            ll j=i+1;
            bool done=false;
            while(j<n){
                for(ll d=5; d>=0; d--){
                    if(a[j]==sbess[d]){
                        if(d==0) { bbest[0]=j;} else {
                           if(bbest[d-1]!=bad) {
                               if(bbest[d-1]>bbest[d]){
                                    bbest[d]=bbest[d-1];
                               }
                               if(d==5){
                                    done=true;
                                    break;
                               }
                           }
                        }
                    }
                }

                // UPDATE THE POINTER IF E is found
                if(done){
                    b_start.push_back(bbest[5]);
                    e_end.push_back(j);
                    bmax++;
                    //bbest[5]
                    i=bbest[5]+1; //???
                    //cout<<"mas " <<i<<endl;
                    break;
                }
                j++;
            }
        }
    }

    for(ll i=0;i<bmax;i++){
        cout<<b_start[i]<<" "<<e_end[i]<<endl;
    }

    // ptr chains  TO
    for(ll i=0; i<bmax; i++){
        ll j;
        j=i+1;
        while(j<bmax && e_end[i]>b_start[j]){
            j++;
        }
        if(j>=bmax) {
            nextb.push_back(bad2);
        } else{
            nextb.push_back(j);
        }
    }

    for(ll i=0;i<bmax;i++){
        cout<<b_start[i]<<" "<<e_end[i]<<" "<<nextb[i]<<endl;
    }

    chaincnt[0]=1;
    for(ll i=0;i<bmax;i++){
        ll nex=nextb[i];
        if(nex!=bad2) {chaincnt[nex]=chaincnt[i]+1;}

    }

    ll ans=0;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}
/*
bebssieessie
    abcdefghssijebessie
*/
