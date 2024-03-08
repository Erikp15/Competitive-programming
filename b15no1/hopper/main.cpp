#include <bits/stdc++.h>

using namespace std;

struct point{
    long long x;
    long long y;
};

int main(){
    point hopper,square_node1,square_node2;
    cin>>hopper.x>>hopper.y>>square_node1.x>>square_node1.y>>square_node2.x>>square_node2.y;
    point smallest_node,largest_node;
    smallest_node.x=min(square_node1.x,square_node2.x);
    smallest_node.y=min(square_node1.y,square_node2.y);
    largest_node.x=max(square_node1.x,square_node2.x);
    largest_node.y=max(square_node1.y,square_node2.y);
    double shortest_distance=3000000001;
    if(hopper.x>=smallest_node.x and hopper.x<=largest_node.x and hopper.y>=smallest_node.y and hopper.y<=largest_node.y){
        shortest_distance=0;
        cout<<shortest_distance<<endl;
        return 0;
    }
    if((hopper.x>=smallest_node.x and hopper.x<=largest_node.x) or (hopper.y>=smallest_node.y and hopper.y<=largest_node.y)){
        if(hopper.x>=smallest_node.x and hopper.x<=largest_node.x){
            shortest_distance=min(abs(hopper.y-smallest_node.y),abs(hopper.y-largest_node.y));
        }else{
            shortest_distance=min(abs(hopper.x-smallest_node.x),abs(hopper.x-largest_node.x));
        }
    }else{
        shortest_distance=min(min(min((pow(abs(smallest_node.x-hopper.x),2)+pow(abs(smallest_node.y-hopper.y),2))/sqrt(pow(abs(smallest_node.x-hopper.x),2)+pow(abs(smallest_node.y-hopper.y),2)),(pow(abs(largest_node.x-hopper.x),2)+pow(abs(largest_node.y-hopper.y),2))/sqrt(pow(abs(largest_node.x-hopper.x),2)+pow(abs(largest_node.y-hopper.y),2)) ),(pow(abs(smallest_node.x-hopper.x),2)+pow(abs(largest_node.y-hopper.y),2))/sqrt(pow(abs(smallest_node.x-hopper.x),2)+pow(abs(largest_node.y-hopper.y),2)) ),(pow(abs(largest_node.x-hopper.x),2)+pow(abs(smallest_node.y-hopper.y),2))/sqrt(pow(abs(largest_node.x-hopper.x),2)+pow(abs(smallest_node.y-hopper.y),2)) );
    }
    cout <<fixed<<setprecision(0)<< ceil(shortest_distance) << endl;
    return 0;
}
// works on all cases but maycamp is shit
