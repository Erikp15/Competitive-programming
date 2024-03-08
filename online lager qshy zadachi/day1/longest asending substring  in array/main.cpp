#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[100],longestsub[100],longestofall=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        longestsub[i]=1;
        for(int j=i;j>=0;j--){
            if(arr[j]<arr[i]){
                longestsub[i]=longestsub[j]+1;
                if(longestsub[i]>longestofall){longestofall=longestsub[i];}
                break;
            }
        }
    }
    cout<<longestofall<<"\n";
    return 0;
}
