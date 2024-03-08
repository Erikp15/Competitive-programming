#include <iostream>
#include <queue>
using namespace std;

int main(){
    long long n,p;
    queue<int> l;
    cin>>n>>p;
    l.push(1);
    while(l.size()!=0){
        long long x=l.front();
        l.pop();
        cout<<x<<endl;
        if(x*p<=n){
            l.push(x*p);
        }
        if(x*p+1<=n){
            l.push(x*p+1);
        }

    }
    return 0;
}
