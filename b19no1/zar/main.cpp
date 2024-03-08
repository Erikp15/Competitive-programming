#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,countk=0;
    cin>>n;
    long long left[n],right[n];
    vector<int> eachk;
    for(int i=0;i<n;i++){
        cin>>left[i]>>right[i];
        if(eachk.empty()){
            for(int j=left[i]/6-1;j<=left[i];j++){
                int correct=j*7-left[i],wrong=right[i],matchcount=0;
                while(correct>0 or wrong>0){
                    if(correct>0 and wrong<=0 or correct<=0 and wrong>0){matchcount=0;break;}
                    if(correct%10==wrong%10){matchcount++;}
                    correct/=10;
                    wrong/=10;
                }
                if(matchcount==1){eachk.push_back(j);countk++;}
            }
        }else{
            for(int j=0;j<eachk.size();j++){
                if(eachk[j]==-1){continue;}
                if(eachk[j]>left[i] or eachk[j]<left[i]/6-1 or eachk[j]>10000){
                    eachk[j]=-1;
                    countk--;
                    continue;
                }
                int correct=eachk[j]*7-left[i],wrong=right[i],matchcount=0;
                while(correct>0 or wrong>0){
                    if(correct>0 and wrong<=0 or correct<=0 and wrong>0){matchcount=0;break;}
                    if(correct%10==wrong%10){matchcount++;}
                    correct/=10;
                    wrong/=10;
                }
                if(matchcount!=1){
                    eachk[j]=-1;
                    countk--;
                }
            }
        }
    }
    cout<<countk<<endl;
    for(int i=0;i<eachk.size();i++){
        if(eachk[i]==-1){continue;}
        cout<<eachk[i]<<" ";
    }
    cout<<endl;
    return 0;
}
