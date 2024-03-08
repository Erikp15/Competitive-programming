#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin>>n;
    int all_lines[101][4];
    int all_unique_angles_count=0;
    for(int i=0;i<n;i++){
        cin>>all_lines[i][0]>>all_lines[i][1]>>all_lines[i][2]>>all_lines[i][3];
        bool is_unique=true;
        for(int j=0;j<i;j++){
            if((all_lines[i][0]-all_lines[i][2])*(all_lines[j][1]-all_lines[j][3])==(all_lines[i][1]-all_lines[i][3])*(all_lines[j][0]-all_lines[j][2])){
                is_unique=false;
            }
        }
        all_unique_angles_count+=is_unique;
    }
    cout << all_unique_angles_count << endl;
    return 0;
}
/*
2
1 1 2 2
4 1 3 2
*/
