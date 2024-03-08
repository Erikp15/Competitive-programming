#include <iostream>

using namespace std;
long long cheat[100000],answer[100000];
int main(){
    long long n;
    cin>>n;
    long long arr[100000];
    for(long long i=0;i<n;i++){
        cin>>arr[i];
        cheat[arr[i]]++;
    }

    for(long long i=1;i<100000;i++){
        cheat[i]=cheat[i-1]+cheat[i];
    }
    long long m;
    cin>>m;
    for(long long i=0;i<m;i++){
        long long a,b;
        cin>>a>>b;
        answer[i]=cheat[b]-cheat[a-1];
    }
    for(long long i=0;i<m;i++){
        cout<<answer[i]<<endl;
    }
    return 0;
}
