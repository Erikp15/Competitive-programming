#include <iostream>

using namespace std;

int main(){
    long long n,m,a,x,y;
    cin>>n>>m>>a;
    x=n/a;
    n%a!=0 ? x++ : x=x;
    y=m/a;
    m%a!=0 ? y++ : x=x;
    cout<<x*y<<endl;
    return 0;
}
