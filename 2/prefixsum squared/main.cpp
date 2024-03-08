#include <iostream>

using namespace std;

int main(){
    long long n,k;
    cin>>n>>k;
    long long table[n][n],prefixsum[n][n],requeststartX[k],requeststartY[k],requestendX[k],requestendY[k];
    for(long long i=0;i<n;i++){
        for(long long j=0;j<n;j++){
            cin>>table[i][j];
            prefixsum[i][j]=0;
            for(long long l=0;l<i;l++){
                for(long long q=0;q<j;q++){
                    prefixsum[i][j]+=prefixsum[l][q];
                }
            }
        }
    }


    for(long long i=0;i<k;i++){
        cin>>requeststartX[i]>>requeststartY[i]>>requestendX[i]>>requestendY[i];
        if(i==0){cout<<prefixsum[requestendX[i]][requestendY[i]]<<endl;continue;}
        cout<<prefixsum[requestendX[i]][requestendY[i]]-prefixsum[requestendX[i]][0]-prefixsum[0][requestendY[i]]+prefixsum[requeststartX[i]-1][requeststartY[i]-1]<<endl;
    }
    return 0;
}
arena.olimpici
codeforces
smgprogramirane.boards.net
