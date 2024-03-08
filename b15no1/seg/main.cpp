#include <bits/stdc++.h>

using namespace std;

struct line{
    long long start;
    long long finish;
};
bool operator>(const line& a,const line& b){
    return a.start < b.start;
}

    line allines[10001];

int main(){
    long long n;
    cin>>n;
    long long longestsofar=0,numberoflines=0;
    for(int i=0;i<n;i++){
        cin>>allines[i].start>>allines[i].finish;
    }
    sort(allines,allines+n,greater<line>());
    for(int i=0;i<n;){
        long long currend=allines[i].finish,currstart=allines[i].start;
        while(allines[i].start<=currend and i<n){
            currend=max(currend,allines[i].finish);
            i++;
        }
        numberoflines++;
        longestsofar=max(longestsofar,currend-currstart);
    }
    cout << numberoflines<<" "<<longestsofar << endl;
    return 0;
}
