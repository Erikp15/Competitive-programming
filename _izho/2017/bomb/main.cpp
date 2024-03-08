#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    string battleground;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m,smallest_territory=2501;
    cin>>n>>m;
    if(m==1)swap(n,m);
    ll curr_terr_size=0;
    cin>>battleground;
    for(ll i=0;i<(ll)battleground.size();i++){
        if(battleground[i]-'0'==1){
            curr_terr_size++;
        }else{
            if(curr_terr_size!=0)smallest_territory=min(smallest_territory,curr_terr_size);
            curr_terr_size=0;
        }
    }
    if(curr_terr_size!=0)smallest_territory=min(smallest_territory,curr_terr_size);
    if(smallest_territory==2501)smallest_territory=0;
    cout<<smallest_territory<<endl;
    return 0;
}
/*
5 1
1 1 0 1 1
5
1 10
0 0 0 0 0 0 0 0 1 1
1
1 31
1 1 1 1 1 1 1 0 0 1 1 0 0 1 1 1 1 0 0 0 0 1 1 0 1 1 1 0 0 1 1
2
*/
