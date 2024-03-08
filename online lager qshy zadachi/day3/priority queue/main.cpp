#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<int> heap;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        heap.push(a*-1);
    }
    while(!heap.empty()){
        cout<<heap.top()*-1<<" ";
        heap.pop();
    }
    cout<<"\n";
}
