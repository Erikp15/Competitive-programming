#include <iostream>

using namespace std;
bool arr[1000];
int main(){
    int n,m;
    cin>>n;
    int coins[1000];
    for(int i=0;i<n;i++){
        cin>>coins[i];
        arr[coins[i]]=true;
    }
    cin>>m;
    for(int i=0;i<m;i++){
        if(arr[i]==true){
            for(int j=0;j<n;j++){
                arr[i+coins[j]]=true;
            }
        }
    }
    cout << arr[m] << endl;
    return 0;
}
