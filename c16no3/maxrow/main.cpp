#include <iostream>
#include <string>
using namespace std;

int main(){
    string massage;
    cin>>massage;
    int minsofar=massage[0]-'0',counter=1,arr[1001];
    for(int i=1;i<massage.length();i++){
        int current=massage[i]-'0';
        int times=i;
        while(current<minsofar){
            if(times==massage.length() and current<minsofar){
                cout<<-1<<endl;
                return 0;
            }
            current=current*10+massage[times+1]-'0';
            times++;
        }
        counter++;
        arr[counter]=current;
        minsofar=current;
        i=times;

    }
    cout <<counter<< endl;
    for(int i=0;i<counter;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
