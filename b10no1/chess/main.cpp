#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    bool is_captured[8][8],is_pawn[8][8];

int main(){
    ll pawns_captured_count=0;
    for(ll i=0;i<5;i++){
        string a;
        cin>>a;
        is_pawn[a[0]-'a'][a[1]-'0']=true;
    }
    for(ll i=0;i<2;i++){
        string a;
        cin>>a;
        ll queen_x=a[0]-'a',queen_y=a[1]-'0';
        for(ll j=0;j<4;j++){
            if(is_pawn[j][queen_y]){
                is_captured[j][queen_y]=true;
                break;
            }
        }
        for(ll j=4;j<8;j++){
            if(is_pawn[j][queen_y]){
                is_captured[j][queen_y]=true;
                break;
            }
        }
        for(ll j=0;j<4;j++){
            if(is_pawn[queen_x][j]){
                is_captured[queen_x][j]=true;
                break;
            }
        }
        for(ll j=4;j<8;j++){
            if(is_pawn[queen_x][j]){
                is_captured[queen_x][j]=true;
                break;
            }
        }
        for(ll j=0;j<4;j++){
            if(is_pawn[j][j+queen_y]){
                is_captured[j][queen_y]=true;
                break;
            }
        }
        for(ll j=4;j<8;j++){
            if(is_pawn[j][j+queen_y]){
                is_captured[j][queen_y]=true;
                break;
            }
        }
        for(ll j=0;j<4;j++){
            if(is_pawn[queen_x][i]){
                is_captured[j][queen_y]=true;
                break;
            }
        }
        for(ll j=4;j<8;j++){
            if(is_pawn[queen_x][i]){
                is_captured[j][queen_y]=true;
                break;
            }
        }
    }
    for(ll i=0;i<8;i++){
        for(ll j=0;j<8;j++){
            if(is_captured[i][j])pawns_captured_count++;
        }
    }
    cout<<pawns_captured_count<<endl;
    return 0;
}
/*
h1
b5
d7
h6
c5
f5
e3
3
*/
