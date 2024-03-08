#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    cin>>n;
    long long sorted_array[10];
    for(int i=0;i<n;i++){
        cin>>sorted_array[i];
    }
    long long m;
    cin>>m;
    sort(sorted_array,sorted_array+n);
    for(int i=0;i<m;i++){
        long long findthis;
        cin>>findthis;
        long long search_start=0,search_end=n-1,j;
        while(true){
            j=(search_end-search_start)/2+search_start;
            if(findthis==sorted_array[search_end]){
                cout<<"index: "<<search_end<<endl;
                break;
            }
            if(findthis==sorted_array[j]){
                cout<<"index: "<<j<<endl;
                break;
            }
            if(findthis>sorted_array[j]){
                search_start=j;
            }else{
                search_end=j;
            }
        }
    }
    return 0;
}
