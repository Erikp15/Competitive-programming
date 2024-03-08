#include <iostream>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(ll m=0;m<3;m++){
        string n;
        cin>>n;
        if(n.size()==1){
            for(ll i=1;i<n[0]-'0';i++){
                if(i>2 and n[0]-'0'-i>2){
                    cout<<false<<endl;
                    break;
                }
                if(i==n[0]-'0'-1){
                    cout<<true<<endl;
                }
            }
        }else if(n[0]=='1' and n[1]!='9'){
            cout<<false<<endl;
        }else{
            for(ll i=0;i<n.size();i++){
                if(n[i]<='5'){
                    cout<<true<<endl;
                    break;
                }
                if(i==n.size()-1){
                    cout<<false<<endl;
                }
            }
        }
        /*
        if(n[0]=='1'){
            if(n[n.size()-1]!='9'){
                cout<<false<<endl;
            }else{
                cout<<true<<endl;
            }
        }else if(n[0]=='2'){
            cout<<true<<endl;
        }else if(n[0]=='3'){
            cout<<true<<endl;
        }else if(n[0]=='4'){
            cout<<true<<endl;
        }else if(n[0]=='5'){
            cout<<true<<endl;
        }else if(n.size()==1){
            for(ll i=1;i<n[0]-'0';i++){
                if(i>2 or n[0]-'0'-i>2){
                    cout<<false<<endl;
                }
            }
        }else{
            ll sum=0;
            for(ll i=0;i<n.size();i++){
                sum+=n[i]-'0';
            }
            if(sum<=7){
                cout<<true<<endl;
            }else{
                cout<<false<<endl;
            }
        }
        */
    }
    return 0;
}
