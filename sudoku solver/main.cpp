#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    string input[9];
    ll sudoku[9][9];
    bool is_present[9][9][9];

bool check_col(ll c,ll num){
    for(ll i=0;i<9;i++){
        if(sudoku[i][c]==num){
            return true;
        }
    }
    return false;
}

bool check_row(ll r,ll num){
    for(ll i=0;i<9;i++){
        if(sudoku[r][i]==num){
            return true;
        }
    }
    return false;
}

bool check_box(ll x,ll y,ll num){
    for(ll i=0;i<3;i++){
        for(ll j=0;j<3;j++){
            if(sudoku[i+x][j+y]==num){
                return true;
            }
        }
    }
    return false;
}

bool empty_space(ll &x,ll &y){
    for(x=0;x<9;x++){
        for(y=0;y<9;y++){
            if(sudoku[x][y]==0){
                return true;
            }
        }
    }
    return false;
}

bool is_valid(ll x,ll y,ll num){
    return (!check_row(x,num) and !check_col(y,num) and !check_box(x-x%3,y-y%3,num));
}

bool solve(){
    ll free_pos_x,free_pos_y;
    if(!empty_space(free_pos_x,free_pos_y)){
        return true;
    }
    for(ll n=1;n<=9;n++){
        if(is_valid(free_pos_x,free_pos_y,n)){
            sudoku[free_pos_x][free_pos_y]=n;
            if(solve()){
                return true;
            }
            sudoku[free_pos_x][free_pos_y]=0;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        for(ll i=0;i<9;i++){
            cin>>input[i];
        }
        for(ll i=0;i<9;i++){
            for(ll j=0;j<9;j++){
                sudoku[i][j]=input[i][j]-'0';
            }
        }
        if(solve()){
            for(ll i=0;i<9;i++){
                for(ll j=0;j<9;j++){
                    if(j==3 or j==6)cout<<" | ";
                    cout<<sudoku[i][j]<<" ";
                }
                if(i==2 or i==5){
                    cout<<endl;
                    for(ll j=0;j<9;j++){
                        cout<<"---";
                    }
                }
                cout<<endl;
            }
        }else{
            cout<<"No Solution"<<endl;
        }
    }
    return 0;
}
/*
1
306508400
520000000
087000031
003010080
900863005
050090600
130000250
000000074
005206300

*/
