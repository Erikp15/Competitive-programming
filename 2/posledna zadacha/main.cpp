#include <iostream>
#include <string.h>
#include <stack>
using namespace std;
long long a[5000000],b[5000000];
int main(){
    long long n,old;
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>a[i];
        cin>>b[i];
        if(i>0 and a[i-1]+b[i-1]>=a[i]){
            old=a[i-1]+b[i-1];
        }
    }

    cout << old << endl;
    return 0;
}
