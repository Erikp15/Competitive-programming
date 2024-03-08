#include <iostream>

using namespace std;

int main(){
    long long n,perms=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        if((n*2)%(i*2)==0){perms++;}
    }
    cout << perms << endl;
    return 0;
}
