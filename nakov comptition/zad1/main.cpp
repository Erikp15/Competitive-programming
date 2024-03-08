#include <iostream>

using namespace std;

int main(){
    long long x,y,z;
    cin>>x>>y>>z;
    double gas=29.40,foodandsuv=3*x+3*y,hotel=z*0.8+z*0.85+z*0.9,total=0.00;
    total=1.85*gas+foodandsuv+hotel;
    cout <<"Money needed: " <<total << endl;
    return 0;
}
