#include <iostream>
#include <math.h>
using namespace std;

int main(){
    double x,y,z,a;
    cin>>x>>y>>z>>a;
    double volume=x*y*z,volumeperroom=8.4;
    if(floor(volume/volumeperroom>10)){cout<<"The spacecraft is too big."<<endl;}
    if(floor(volume/volumeperroom<10) && floor(volume/volumeperroom>3)){cout<<"The spacecraft holds "<<floor(volume/volumeperroom)<<" astronauts."<<endl;}
    if(floor(volume/volumeperroom<3)){cout<<"The spacecraft is too small."<<endl;}
    return 0;
}
