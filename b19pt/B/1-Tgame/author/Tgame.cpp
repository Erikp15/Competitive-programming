#include <iostream>
#include <iomanip>
using namespace std;

struct node{
    int leafs;
    int l, r;
};

int n, m;
node tree[5200];

double dp[5200][4096];
bool calc[5200][4096];

int dfs(int v){
    if (tree[v].l == -1) return tree[v].leafs = 1;
    return tree[v].leafs = dfs(tree[v].l) + dfs(tree[v].r);
}

double ans(int v, int ones){
    if (calc[v][ones]) return dp[v][ones];
    calc[v][ones] = true;
    if (tree[v].leafs == ones)
        return dp[v][ones] = 1;
    if (ones == 0)
        return dp[v][ones] = 0;

    dp[v][ones] = -1;
    int l = tree[tree[v].l].leafs, r = tree[tree[v].r].leafs;
    for (int i = max(0, ones-r); i <= min(l, ones); ++i){
        double ans_l = ans(tree[v].l, i), ans_r = ans(tree[v].r, ones-i);
        double cans = (min(ans_l, ans_r) + 2*max(ans_l, ans_r))/3;
        if (cans > dp[v][ones]) dp[v][ones] = cans;
    }
    return dp[v][ones];
}

int main(){
    cin>>n>>m;
    for (int i=0; i<n; ++i){
        cin>>tree[i].l;
        if (tree[i].l != -1){
            cin>>tree[i].r;
            --tree[i].l;
            --tree[i].r;
        }
    }
    dfs(0);
    cout<<fixed<<setprecision(10)<<ans(0, m)<<endl;
    return 0;
}
