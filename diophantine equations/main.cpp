#include <bits/stdc++.h>

using namespace std;

int main(){
    long long a,b,c,x=10000000,y=10000000,lcm=1;
    cin>>a>>b>>c;
    while(1) {
        if( lcm%a==0 && lcm%c==0 ) {
            break;
        }
        lcm++;
    }
    for(int i=-lcm;i<=lcm;i++){
        if((c-a*i)%b==0){
            if(abs(i)+abs((c-(a*i))/b)<abs(x)+abs(y)){
                x=i;
                y=(c-(a*i))/b;
            }
        }
    }

    cout <<a<<"*"<<x<<"+"<<b<<"*"<<y<<"="<<c<< endl;
    cout<<"smallest number of calculations is: "<<abs(x)+abs(y)<<endl;
    cout<<"lcm: "<<lcm<<endl;
    return 0;
}
