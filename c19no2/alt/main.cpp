#include <iostream>

using namespace std;

int main(){
    long long k,m,n;
    cin>>k>>m>>n;
    long long nums[50],wayssofar[50],totalcount=0;
    for(long long i=1;i<m;i++){
        for(long long i=0;i<){
            for(long long j=0;j<n;j++){
                nums[j]=0;
                wayssofar[j]=0;
            }
            wayssofar[0]=1;
            nums[0]=i;
            for(long long f=1;f<n;f++){
                if(nums[f-1]+k>=m && nums[f-1]-k<=1){
                    cout<<0<<endl;
                    return 0;
                }
                if(nums[f-1]-k<=1){
                    nums[f]=nums[f-1]+k;
                    wayssofar[f]=wayssofar[f-1]+1;
                    continue;
                }
                if(nums[f-1]+k>=m){
                    nums[f]=nums[f-1]-k;
                    wayssofar[f]=wayssofar[f-1]+1;
                    continue;
                }
                nums[f];
            }
        }
    }
    cout << "Hello world!" << endl;
    return 0;
}
