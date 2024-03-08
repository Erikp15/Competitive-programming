#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin>>n;
    n++;
    ll row=pow(2,60);
    ll depth=60;
    for(;n/row==0;depth--){
        row/=2;
    }
    ll remainder=n-pow(2,depth);
    ll prev_pow=pow(2,depth-1);
    if(remainder>=row/2){
        remainder-=row/2;
        if(remainder%2==0){
            cout<<prev_pow-1+remainder/2<<endl;
        }else{
            cout<<prev_pow-1+remainder/2+prev_pow/2<<endl;
        }
        remainder+=row/2;
    }else{
        if(remainder%2==0){
            cout<<prev_pow-1+remainder/2<<endl;
        }else{
            cout<<prev_pow-1+remainder/2+prev_pow/2<<endl;
        }
    }
    ll next_pow=pow(2,depth+1);
    if(remainder>=row/2){
        remainder-=row/2;
        if(remainder%2==0){
            cout<<next_pow+remainder*2<<" ";
            cout<<next_pow+remainder*2+row<<endl;
        }else{
            cout<<next_pow+remainder*2<<" ";
            cout<<next_pow+remainder*2+row<<endl;
        }
    }else{
        if(remainder%2==0){
            cout<<next_pow-1+remainder*2<<" ";
            cout<<next_pow-1+remainder*2+row<<endl;
        }else{
            cout<<next_pow-1+remainder*2<<" ";
            cout<<next_pow-1+remainder*2+row<<endl;
        }
    }
    return 0;
}
/*
0
1 10
101 111 110 1000
1001
*/
