#include <iostream>

using namespace std;
int nod(long long a,long long b){
    long long res=1;
    for(long long i=2;i<=min(a,b);i++){
        if(a%i==0 and b%i==0){res=i;}
    }
    return res;
}
int main(){
    long long a,b,c,i=1;
    cin>>a>>b>>c;
    if(c%nod(a,b)!=0){cout<<"Impossible"<<endl;return 0;}
    while(true){
        long long res=c-i*max(a,b);
        if(res%min(a,b)==0 and res/min(a,b)!=0){
            if(i<0){
                cout<<-i+res/min(a,b)<<endl;return 0;
            }
            if(res/min(a,b)<0){
                cout<<-res/min(a,b)+i<<endl;return 0;
            }
            if(res/min(a,b)<0 and i<0){
                cout<<-res/min(a,b)-i<<endl;return 0;
            }
            cout<<res/min(a,b)+i<<endl;return 0;
        }
        i++;
    }
    return 0;
}
