#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    double tri_x,tri_y,box_x[4],box_y[4],box_z[4];
    cin>>tri_x>>tri_y;
    if(tri_x>tri_y)swap(tri_x,tri_y);
    for(ll i=0;i<4;i++){
        cin>>box_x[i]>>box_y[i]>>box_z[i];
        double tmp=box_x[i];
        box_x[i]=min(min(box_x[i],box_y[i]),box_z[i]);
        if(box_x[i]==tmp){
            box_y[i]=min(box_y[i],box_z[i]);
        }
        if(box_x[i]==box_y[i]){
            box_y[i]=min(tmp,box_z[i]);
        }
        if(box_x[i]==box_z[i]){
            box_y[i]=min(tmp,box_y[i]);
        }
    }
    for(ll i=0;i<4;i++){
        cout<<box_y[i]*tri_x/tri_y<<" "<<box_x[i]<<endl;
        if(box_y[i]*tri_x/tri_y+box_x[i]<=tri_x and box_x[i]<=tri_x and box_y[i]<=tri_y){
            cout<<"1"<<endl;
        }else{
            cout<<"0"<<endl;
        }
    }
    return 0;
}
