#include <bits/stdc++.h>

using namespace std;

struct min_max{
    long long index;
    long long value;
};



int main(){
    long long n;
    cin>>n;
    long long arr[20001],min_num_so_far=1000001,max_num_so_far=-1000001,longest_so_far=0;
    vector<long long> min_num_index_storage,max_num_index_storage;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]>max_num_so_far){
            max_num_so_far=arr[i];
        }
        if(arr[i]<min_num_so_far){
            min_num_so_far=arr[i];
        }
    }
    if(max_num_so_far==min_num_so_far){cout<<"1"<<" "<<n<<endl;return 0;}
    for(long long i=0;i<n;i++){
        if(arr[i]==max_num_so_far){
            max_num_index_storage.push_back(i);
        }
        if(arr[i]==min_num_so_far){
            min_num_index_storage.push_back(i);
        }
    }
    for(int i=0;i<min_num_index_storage.size();i++){
        for(int j=0;j<max_num_index_storage.size();j++){
            if(abs(min_num_index_storage[i]-max_num_index_storage[j])>longest_so_far){
                longest_so_far=abs(min_num_index_storage[i]-max_num_index_storage[j]);
                min_num_so_far=min_num_index_storage[i];
                max_num_so_far=max_num_index_storage[j];
            }
        }
    }
    cout << min(min_num_so_far+1,max_num_so_far+1)<<" "<<max(min_num_so_far+1,max_num_so_far+1)<< endl;
    return 0;
}
