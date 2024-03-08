#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=51;
bool is_passable[Size][Size],visited[Size][Size];
char dir[Size][Size];
ll n,m,a,b,c,d;
queue<pair<ll,ll>> to_process;

void bfs(ll x,ll y){
    if(x==0 and y==0)return;
    if(x>0){
        if(!visited[x-1][y] and is_passable[x-1][y]==false){
            dir[x-1][y]='U';
            visited[x-1][y]=true;
            to_process.push({x-1,y});
        }
    }
    if(x<n-1){
        if(!visited[x+1][y] and is_passable[x+1][y]==false){
            dir[x+1][y]='D';
            visited[x+1][y]=true;
            to_process.push({x+1,y});
        }
    }
    if(y>0){
        if(!visited[x][y-1] and is_passable[x][y-1]==false){
            dir[x][y-1]='L';
            visited[x][y-1]=true;
            to_process.push({x,y-1});
        }
    }
    if(y<m-1){
        if(!visited[x][y+1] and is_passable[x][y+1]==false){
            dir[x][y+1]='R';
            visited[x][y+1]=true;
            to_process.push({x,y+1});
        }
    }
    auto next=to_process.front();
    to_process.pop();
    bfs(next.first,next.second);
}

void finish_sol(string ans){
    dir[a][b]='0';
    visited[a][b]=true;
    bfs(a,b);
    ll x=0,y=0;
    string tmp;
    while(x!=a or y!=b){
        tmp+=dir[x][y];
        if(dir[x][y]=='R'){
            y--;
            continue;
        }
        if(dir[x][y]=='L'){
            y++;
            continue;
        }
        if(dir[x][y]=='D'){
            x--;
            continue;
        }
        if(dir[x][y]=='U')x++;
    }
    reverse(tmp.begin(),tmp.end());
    ans+=tmp;
    cout<<ans.size()<<endl<<ans<<"\n";
}

void solve(){
    cin>>n>>m>>a>>b>>c>>d;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>is_passable[i][j];
        }
    }
    string ans="";
    if(a==c and b==d){
        finish_sol(ans);
    }
    ll counter=0;
    while(a!=c or b!=d){
        while((b>0 and is_passable[a][b-1]==false) or (d>0 and is_passable[c][d-1]==false)){
            ans+='L';
            if(b>0 and is_passable[a][b-1]==false){
                b--;
            }
            if(d>0 and is_passable[c][d-1]==false){
                d--;
            }
        }
        if(counter%2==0){
            ans+='D';
            if(a<n-1){
                a++;
            }
            if(c<n-1){
                c++;
            }
        }else{
            ans+='U';
            if(a>0){
                a--;
            }
            if(c>0){
                c--;
            }
        }
        counter++;
    }
    finish_sol(ans);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}

/*
2 5 1 4 0 2
0 1 0 0 0
0 0 0 1 0
*/
