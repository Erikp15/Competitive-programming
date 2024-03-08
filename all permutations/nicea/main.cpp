#include <iostream>

using namespace std;

int main(){
    long long n,k;
    cin>>n>>k;
    long long arr[n];
    for(int i=0;i<n;i++){
        arr[i]=0;
    }
    while(true){
        for(int j=n-1;j>=0;j--)cout<<arr[j]<<" ";
        cout<<endl;
        int i=0;
        while(arr[i]==k-1){
            arr[i]=0;
            i++;
        }
        if(i==n)break;
        arr[i]++;
    }
    return 0;
}
