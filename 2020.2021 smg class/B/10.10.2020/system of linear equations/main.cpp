#include <iostream>

using namespace std;

    double all_variables[1000];

int main(){
    long long n;
    cin>>n;
    double all_equations[100][101];
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++){
            cin>>all_equations[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            double mult_by=0;
            if(all_equations[j][i]!=0){
                mult_by=-all_equations[i][i]/all_equations[j][i];
            }else{
                break;
            }
            for(int k=0;k<n+1;k++){
                all_equations[j][k]=all_equations[j][k]*mult_by;
                all_equations[j][k]=all_equations[i][k]+all_equations[j][k];
            }
        }
    }

    for(int i=n-1;i>=0;i--){
        double total_sum=0;
        for(int j=n-1;j>=0;j--){
            if(all_equations[i][j-1]!=0){
                total_sum+=all_equations[i][j]*all_variables[j];
            }else{
                all_variables[i]=(all_equations[i][n]-total_sum)/all_equations[i][j];
                break;
            }
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<all_variables[i]<<" ";
    }

    cout<<endl;
    return 0;
}
/*
3
4 -3 7 8
9 2 1 -4
7 5 4 3

2
8 2 17
5 10 20

3
1 1 1 6
0 2 5 -4
2 5 -1 27
*/
