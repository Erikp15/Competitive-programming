#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    long long all_points[n];
    for(int i=0;i<n;i++){
        cin>>all_points[i];
    }
    long long best_so_far=0,p1=0,p2=n-1;
    while(p1!=p2){
        if((p2-p1)*min(all_points[p1],all_points[p2])>best_so_far){
            best_so_far=(p2-p1)*min(all_points[p1],all_points[p2]);
        }
        if(all_points[p1]>all_points[p2]){
            p2--;
        }else{
            p1++;
        }
    }
    cout << best_so_far << endl;
    return 0;
}
