#include <iostream>

using namespace std;

typedef long long ll;

class point{
public:
    ll value;
    ll k_used;
    point(){
        value=0;
        k_used=0;
    }
};

    ll each_node_value[1001][1001];
    point best_so_far[1001][1001];

int main(){
    //freopen("maxsum.10.in","r",stdin);
    ll n,k;
    cin>>n>>k;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cin>>each_node_value[i][j];
        }
    }
    for(ll m=0;m<=k;m++){
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                if(best_so_far[i][j-1].value+each_node_value[i][j]>best_so_far[i][j].value){
                    best_so_far[i][j].value=best_so_far[i][j-1].value+each_node_value[i][j];
                    best_so_far[i][j].k_used=best_so_far[i][j-1].k_used;
                }
                if(best_so_far[i-1][j].value+each_node_value[i][j]>best_so_far[i][j].value){
                    best_so_far[i][j].value=best_so_far[i-1][j].value+each_node_value[i][j];
                    best_so_far[i][j].k_used=best_so_far[i-1][j].k_used;
                }
                if(best_so_far[i][j+1].value+each_node_value[i][j]>best_so_far[i][j].value){
                    best_so_far[i][j].value=best_so_far[i][j+1].value+each_node_value[i][j];
                    best_so_far[i][j].k_used=best_so_far[i][j+1].k_used+1;
                }
                if(best_so_far[i+1][j].value+each_node_value[i][j]>best_so_far[i][j].value){
                    best_so_far[i][j].value=best_so_far[i+1][j].value+each_node_value[i][j];
                    best_so_far[i][j].k_used=best_so_far[i+1][j].k_used+1;
                }
            }
        }
    }
    cout<<best_so_far[n-1][n-1].value<<endl;
    return 0;
}
/*
3 1
1 1 0
1 1 0
1 1 1

4 4
1 1 1 0
1 0 1 0
1 1 1 0
0 0 1 2
*/
