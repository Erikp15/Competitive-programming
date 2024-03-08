#include <iostream>

using namespace std;
long long arr[300000];
int main(){
    long long n,r,icount=0,jcount=1,totalcount=0;
    cin>>n>>r;
    for(long i=0;i<n;i++){
        cin>>arr[i];
    }
    while(icount!=n-1){
        if(arr[jcount]-arr[icount]>r){
            totalcount+=n-jcount;
            icount++;
            if(icount==jcount and jcount!=n){
                jcount++;
            }
        }else{
            if(jcount!=n){
                jcount++;
            }else{
                icount++;
            }
        }
    }
    cout << totalcount << endl;
    return 0;
}
