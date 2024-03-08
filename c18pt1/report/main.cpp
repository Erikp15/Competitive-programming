#include <iostream>

using namespace std;

long long nums[10000],smallestforthis[10000];
int callback(long long a){
    if(){}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>nums[i];
    }
    for(long long i=1;i<n;i++){
        if(nums[i]>nums[i-1]){
            smallestforthis[i]=i;
        }else{
            if(nums[i]==nums[i-1]){
                smallestforthis[i]=smallestforthis[i-1];
            }else{
                callback(i-2);
            }
        }
    }
    for(long long i=0;i<n;i++){
        cout << smallestforthis[i] <<" ";
    }
    cout<<endl;
    return 0;
}
/*
#include<iostream>
using namespace std;

const int MAX_N = 1e5;
int arr[MAX_N];
int ans[MAX_N];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    ans[0] = -1;
    for(int i = 1; i < n; ++i) {
        int currInd = i - 1;

        while(currInd != -1 && arr[currInd] >= arr[i]) {
            currInd = ans[currInd];
        }

        ans[i] = currInd;
    }

    for(int i = 0; i < n; ++i) {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}*/
