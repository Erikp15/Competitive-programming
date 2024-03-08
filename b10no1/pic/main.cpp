#include <iostream>

using namespace std;

typedef long long ll;

    ll is_island[102][102],is_land[102][102];

void is_half_island(ll x,ll y){
    if(is_land[x-1][y-1]){
        if(is_island[x-1][y-1]!=2){
            is_island[x-1][y-1]=2;
            is_island[x][y]=2;
            is_half_island(x-1,y-1);
        }
    }
    if(is_land[x-1][y]){
        if(is_island[x-1][y]!=2){
            is_island[x-1][y]=2;
            is_island[x][y]=2;
            is_half_island(x-1,y);
        }
    }
    if(is_land[x-1][y+1]){
        if(is_island[x-1][y+1]!=2){
            is_island[x-1][y+1]=2;
            is_island[x][y]=2;
            is_half_island(x-1,y+1);
        }
    }
    if(is_land[x][y-1]){
        if(is_island[x][y-1]!=2){
            is_island[x][y-1]=2;
            is_island[x][y]=2;
            is_half_island(x,y-1);
        }
    }
    if(is_land[x][y]){
        if(is_island[x][y]!=2){
            is_island[x][y]=2;
        }
    }
    if(is_land[x][y+1]){
        if(is_island[x][y+1]!=2){
            is_island[x][y+1]=2;
            is_island[x][y]=2;
            is_half_island(x,y+1);
        }
    }
    if(is_land[x+1][y-1]){
        if(is_island[x+1][y-1]!=2){
            is_island[x+1][y-1]=2;
            is_island[x][y]=2;
            is_half_island(x+1,y-1);
        }
    }
    if(is_land[x+1][y]){
        if(is_island[x+1][y]!=2){
            is_island[x+1][y]=2;
            is_island[x][y]=2;
            is_half_island(x+1,y);
        }
    }
    if(is_land[x+1][y+1]){
        if(is_island[x+1][y+1]!=2){
            is_island[x+1][y+1]=2;
            is_island[x][y]=2;
            is_half_island(x+1,y+1);
        }
    }
}

int main(){
    ll m,n,island_count=0;
    cin>>m>>n;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cin>>is_land[i][j];
            is_island[i][j]=is_land[i][j];
        }
    }
    for(ll i=1;i<=m;i++){
        if(is_land[1][i]==1){
            is_half_island(1,i);
        }
    }
    for(ll i=1;i<=m;i++){
        if(is_land[n][i]==1){
            is_half_island(n,i);
        }
    }
    for(ll i=1;i<=n;i++){
        if(is_land[i][1]==1){
            is_half_island(i,1);
        }
    }
    for(ll i=1;i<=n;i++){
        if(is_land[i][m]==1){
            is_half_island(i,m);
        }
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(is_island[i][j]==1){
                is_half_island(i,j);
                island_count++;
            }
        }
    }
    /*
    cout<<endl;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cout<<is_land[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(ll i=0;i<=n+1;i++){
        for(ll j=0;j<=m+1;j++){
            cout<<is_island[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    cout<<island_count<<endl;
    return 0;
}
/*
10 5
1 1 0 0 0 0 0 0 0 0
0 1 1 0 0 0 0 1 0 0
0 0 0 0 0 0 0 0 1 0
0 0 1 0 0 1 0 0 0 0
0 0 0 0 1 0 0 0 0 0
2
*/
