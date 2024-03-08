#include <iostream>

using namespace std;

int main(){
    long long n,k;
    cin>>n>>k;
    long long numbers[n],prefixsum[n],orderstart[k],orderend[k];
    for(long long i=0;i<n;i++){
        cin>>numbers[i];
        if(i==0){prefixsum[i]=numbers[i];continue;}
        prefixsum[i]=prefixsum[i-1]+numbers[i];
    }
    for(long long i=0;i<k;i++){
        cin>>orderstart[i]>>orderend[i];
        cout<<prefixsum[orderend[i]]-prefixsum[orderstart[i]]+numbers[orderstart[i]];
    }
    return 0;
}
