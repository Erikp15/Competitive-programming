#include <bits/stdc++.h>

using namespace std;

long long timetoexe[1000000],movierequest[1000000];

int main(){
    long long n,m,t,l,maxtimesofar=0;
    cin>>n>>m>>t>>l;
    for(int i=0;i<n;i++){
        cin>>movierequest[i];
        timetoexe[movierequest[i]]++;
    }
    sort(timetoexe,timetoexe+n+1,greater<long long>());

    for(int i=0;i<n+1;i++){
        if(timetoexe[i]==0){
            break;
        }
        timetoexe[i]=timetoexe[i]*(t+l)+(i/m)*t;
        if(timetoexe[i]>maxtimesofar){
            maxtimesofar=timetoexe[i];
        }
    }
    cout << maxtimesofar<<endl;
    return 0;
}
