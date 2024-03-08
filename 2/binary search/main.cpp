#include <iostream>

using namespace std;
int a[10]={1,2,4,5,10,12,13,456,12345,1000000},start=0,lengthofstring=10;
int doesitexist(int n){
    long long res,i=n;
    if(n==a[(start+lengthofstring)/2]){return lengthofstring/2;}
    if(n<a[(start+lengthofstring)/2]){lengthofstring/=2;res=doesitexist(i);}
    if(n>a[(start+lengthofstring)/2]){start=lengthofstring/2;lengthofstring/=2;res=doesitexist(i);}
    return res;
}
int main(){
    long long n;
    cin>>n;
    cout << doesitexist(n) << endl;
    return 0;
}
