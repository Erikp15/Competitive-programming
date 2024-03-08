#include <iostream>

using namespace std;

    long long answer[51];

int main(){
    long long n,a;
    cin>>n>>a;
    answer[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=i-1;j>=i-a;j--){
            if(j<0)break;
            answer[i]+=answer[j];
        }
    }
    cout << answer[n] << endl;
    return 0;
}
