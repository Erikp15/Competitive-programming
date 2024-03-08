#include <bits/stdc++.h>

using namespace std;

    short int tribonacci[3];

int main(){
    long long p,curr_index=0;
    cin>>p;
    tribonacci[0]=0%p;
    tribonacci[1]=0%p;
    tribonacci[2]=1%p;
    for(int i=3;;i++){
        curr_index++;
        int tmp=tribonacci[0];
        tribonacci[0]=tribonacci[1];
        tribonacci[1]=tribonacci[2];
        tribonacci[2]=(tmp+tribonacci[0]+tribonacci[1])%p;
        if(tribonacci[0]==0 and tribonacci[1]==0 and tribonacci[2]==1){
            cout<<curr_index<<endl;
            return 0;
        }
    }
    return 0;
}
