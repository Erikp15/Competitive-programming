#include <iostream>
#include <string>
using namespace std;
bool alphabet[26];
int whichshoulditbe[26];
int main(){
    string a;
    cin>>a;
    int whichon=1;
    for(long long i=0;i<a.length();i++){
        alphabet[a[i]-'A']=true;
    }
    for(int i=0;i<26;i++){
        if(alphabet[i]==true){
            whichshoulditbe[i]=whichon;
            whichon++;
        }
    }
    for(long long i=0;i<a.length();i++){
        cout<< char(whichshoulditbe[a[i]-'A']+'A'-1);
    }
    cout<<endl;
    whichon=0;
    for(int i=25;i>=0;i--){
        if(alphabet[i]==true){
            whichshoulditbe[i]=whichon;
            whichon++;
        }
    }
    for(long long i=0;i<a.length();i++){
        cout<< char('Z'-whichshoulditbe[a[i]-'A']);
    }
    cout<<endl;
    return 0;
}
