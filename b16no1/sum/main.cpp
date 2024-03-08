#include <bits/stdc++.h>

using namespace std;

    long long all_solutions_tree[3001][13];

int main(){
    long long n,total_n_sum=0;
    cin>>n;
    all_solutions_tree[0][0]=1;
    all_solutions_tree[1][0]=1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<12;j++){
            long long step_back=pow(2,j);
            for(int m=j;m>=0;m--){
                if(step_back<=i){
                    all_solutions_tree[i][j]+=all_solutions_tree[i-step_back][m];
                }
            }
        }
    }
    for(int i=0;i<12;i++){
        total_n_sum+=all_solutions_tree[n][i];
    }
    cout << total_n_sum << endl;
    return 0;
}
