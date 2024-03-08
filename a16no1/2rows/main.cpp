#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(ll l=0;l<5;l++){
        map<int,int> val_to_pos;
        bool is_pos=true;
        ll n;
        cin>>n;
        ll arr[100001];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            val_to_pos.insert(make_pair<int,int>(arr[i],i));
        }
        ll m;
        cin>>m;
        ll arr2[100001],furthest_i=0;
        for(ll i=0;i<m;i++){
            cin>>arr2[i];
        }
        for(ll i=0;i<m;i++){
            if(val_to_pos.find(arr2[i])!=val_to_pos.end()){
                if(val_to_pos[arr2[i]]<furthest_i){
                    is_pos=false;
                    break;
                }
                furthest_i=val_to_pos[arr2[i]];
            }
        }
        if(is_pos){
            cout<<'1';
        }else{
            cout<<'0';
        }
    }
    cout<<endl;
    return 0;
}
/*
3 1 2 3
4 1 3 5 6
3 5 1 4
4 150 1 20 5
4 1 5 6 2
3 2 1 6
5 100 20 45 10 3
4 3 100 80 10
5 90 1 4 8 80
5 90 1 8 100 5
10001
*/
