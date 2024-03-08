#include <iostream>

using namespace std;
bool radix[10000];
int main(){
    long long n,a,b;
    cin>>n>>a>>b;
    long long nums[n],shortensum=0,counter=0;
    radix[0]=true;
    for(long long i=0;i<n;i++){
        cin>>nums[i];
        shortensum+=nums[i];
        for(long long j=0;j<shortensum;j++){
            if(radix[j]==true){
                radix[j+nums[i]]=true;
            }
        }
        radix[nums[i]]=true;
    }
    for(long long i=a;i<=b;i++){
        if(radix[i]==true){
            counter++;
        }
    }
    cout<<counter<<endl;
    return 0;
}
