#include <iostream>

using namespace std;
long long sums[1000000];
bool countofsequences[2000000];
int main(){
    long long n;
    cin>>n;
    long long nums[1000],counttotal=0,addition=0,oldsum,diff=1000000;

    for(long long i=0;i<n;i++){
        cin>>nums[i];
    }
    for(long long i=0;i<n;i++){
        oldsum=addition;
        if(countofsequences[nums[i]+diff]==false){
            sums[addition]=nums[i];
            countofsequences[nums[i]+diff]=true;
            addition++;
        }
        for(long long j=0;j<oldsum;j++){
            if(countofsequences[sums[j]+nums[i]+diff]==false){
                sums[addition]=nums[i]+sums[j];
                countofsequences[nums[i]+sums[j]+diff]=true;
                addition++;
            }
        }

    }
    for(long long i=0;i<addition;i++){
        counttotal++;
    }
    cout << counttotal << endl;
    return 0;
}
