#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll n,k,pows[33],curr_perm[33];
    cin>>n>>k;
    for(ll i=0;i<33;i++){
        pows[i]=pow(k,i);
        curr_perm[i]=0;
    }
    while(true){
        ll curr_number=0;
        ll j=0;
        while(curr_perm[j]==1){
            curr_perm[j]=0;
            j++;
        }
        curr_perm[j]++;
        for(ll i=0;i<33;i++){
            if(curr_perm[i]==1){
                curr_number+=pows[i];
            }
        }
        if(curr_number>n)break;
        cout<<curr_number<<endl;
    }
    return 0;
}
