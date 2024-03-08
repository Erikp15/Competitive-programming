#include <iostream>

using namespace std;
    long long a[100000],count3[100000],count2[100000],biggestcount=-999999;

int main(){
    long long n;
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    count3[0]=a[0]*3;
    count2[0]=a[0]*2;
    for(long long i=1;i<n;i++){
        count2[i]=max(count2[i-1]+a[i]*2,count3[i-1]+a[i]*2);
        count3[i]=count2[i-1]+a[i]*3;
    }
    if(count2[n-1]>count3[n-1]){
        cout << count2[n-1] << endl;
    }else{
        cout << count2[n-1] << endl;
    }

    return 0;
}
