#include <iostream>

using namespace std;
    long long arr[200000];
int main(){
    long long n,i=0,j=0,bestisofarlength=0,bestisofarcount=0,bestjsofarlength=0,bestjsofarcount=0;
    cin>>n;
    for(int k=0;k<n;k++){
        cin>>arr[k];
    }
    while(i!=n-j){
        if(bestisofarlength==bestjsofarlength){
            bestisofarlength+=arr[i];
            bestisofarcount=i;
            bestjsofarcount=j;
            i++;
        }else{
            if(bestisofarlength>bestjsofarlength){
                bestjsofarlength+=arr[n-j-1];
                j++;
            }else{
                bestisofarlength+=arr[i];
                i++;
            }
        }
    }
    cout << bestisofarcount+bestjsofarcount << endl;
    return 0;
}
