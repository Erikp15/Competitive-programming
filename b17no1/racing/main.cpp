#include <iostream>

using namespace std;

long long fastestsofar[1002];

int main(){
    long long n,minpitstop=101;
    cin>>n;
    long long pitstopcost[1002];
    for(int i=1;i<=n;i++){
        cin>>pitstopcost[i];
        if(minpitstop>pitstopcost[i]){minpitstop=pitstopcost[i];}
        fastestsofar[i]=100001;
    }
    pitstopcost[n+1]=0;
    fastestsofar[0]=0;
    for(int i=1;i<=n+1;i++){
        long long minsofar=100001;
        if(minsofar>fastestsofar[i-1]){minsofar=fastestsofar[i-1];}
        if(minsofar>fastestsofar[i-2]){minsofar=fastestsofar[i-2];}
        if(minsofar>fastestsofar[i-3]){minsofar=fastestsofar[i-3];}
        fastestsofar[i]=minsofar+pitstopcost[i];
    }
    if(fastestsofar[n+1]==0){
        cout << minpitstop << endl;
    }else{
        cout << fastestsofar[n+1] << endl;
    }
    return 0;
}
