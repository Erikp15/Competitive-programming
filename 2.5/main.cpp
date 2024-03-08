#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll cstock=1;

class stock{
public:
    string name,type;
    ld weight,price;
    stock(){
        cout<<"input stock "<<cstock<<" : "<<endl;
        cin>>name>>type>>weight>>price;
        cstock++;
    }
};

int main(){
    ll n,bad=0;
    cout<<"input stock amount: "<<endl;
    cin>>n;
    stock stocks[n];
    ll q;
    cout<<"input number of querys: "<<endl;
    cin>>q;
    while(q--){
        ld price,c=0;
        cin>>price;
        for(ll i=0;i<n;i++){
            if(price<stocks[i].price){
                c++;
                cout<<stocks[i].name<<endl;
            }
        }
        cout<<c<<endl;
    }
    return 0;
}
