#include <iostream>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int arr[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(i==0 and j==0){
                continue;
            }
            if(i-1<0){
                arr[i][j]=arr[i][j-1]+arr[i][j];
            }else{
                if(j-1<0){
                    arr[i][j]=arr[i-1][j]+arr[i][j];
                }else{
                    arr[i][j]=max(arr[i-1][j],arr[i][j-1])+arr[i][j];
                }
            }
        }
    }
    cout<<arr[n-1][m-1]<<"\n";
    return 0;
}
