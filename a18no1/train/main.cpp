#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("train.20.in","r",stdin);
    //freopen("output.txt","w",stdout);
/*
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
*/
    int n;
    cin>>n;
    int all_perms[5][n];
    string answer;
    for(int i=0;i<5;i++){
        for(int j=0;j<n;j++){
            cin>>all_perms[i][j];
        }
    }
    for(int i=0;i<5;i++){
        stack<int> track_c;
        vector<int> track_a;
        bool is_possible=true;
        for(int j=n;j>0;j--){
            track_a.push_back(j);
        }
        for(int j=0;j<n;j++){
            int curr_cart=all_perms[i][j],curr_top;
            if(!track_c.empty()){
                curr_top=track_c.top();
            }else{
                curr_top=0;
            }
            if(curr_cart==curr_top){
                track_c.pop();
                continue;
            }
            if(curr_cart>curr_top){
                while(curr_cart!=track_a[track_a.size()-1]){
                    track_c.push(track_a[track_a.size()-1]);
                    track_a.pop_back();
                }
                track_a.pop_back();
            }else{
                is_possible=false;
                break;
            }
        }
        answer+=(is_possible+'0');
    }
    cout << answer << endl;
    return 0;
}
