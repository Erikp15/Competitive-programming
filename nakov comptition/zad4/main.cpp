#include <iostream>

using namespace std;

int main(){
    long long guestcost,total=0,guests=0;
    char group;
    cin>>guestcost;
    while(group!='The'){
        cin>>group;
        if(group<5){total+=100*group;}else{total+=70*group;}
        guests+=group;
    }
    if(total>=guestcost){cout <<"You have " <<guests<<" guests and "<<total-guestcost<<" leva left."<< endl;}else{cout <<"You have " <<guests<<" guests and "<<total<<" leva income, but no singer."<< endl;}
    return 0;
}
