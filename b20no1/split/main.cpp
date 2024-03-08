#include <bits/stdc++.h>

using namespace std;

int main(){
    string arr;
    cin>>arr;
    long long sub1count=0,sub0count=0,totalsubarr=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]=='1'){sub1count++;}
        if(arr[i]=='0'){sub0count++;}
        if(sub1count==sub0count){
            totalsubarr++;
            sub0count=0;
            sub1count=0;
        }
    }
    cout << totalsubarr << endl;
    return 0;
}
