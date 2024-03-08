#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    cin>>n;
    string equations[11];
    for(int i=0;i<n;i++){
        cin>>equations[i];
    }
    for(int i=0;i<n;i++){
        vector<char>format,mult;
        char lastdig=equations[i][0];
        for(int j=0;j<equations[i].length();j++){
            if(equations[i][j]=='+' or equations[i][j]=='*'){
                format.push_back(equations[i][j-1]);
                format.push_back(equations[i][j]);
            }
        }
        format.push_back(equations[i][equations[i].size()-1]);
        lastdig=format[0];
        for(int j=1;j<format.size();j+=2){
            if(format[j]=='+'){
                mult.push_back(lastdig);
                mult.push_back(format[j]);
                lastdig=format[j+1];
            }
            if(format[j]=='*'){
                if(((lastdig-'0')*(format[j+1]-'0'))%2==0){
                    lastdig='0';
                }else{
                    lastdig='1';
                }
            }
        }
        mult.push_back(lastdig);
        lastdig=mult[0];
        for(int j=1;j<mult.size();j+=2){
            if((lastdig-'0'+mult[j+1]-'0')%2==0){
                lastdig='0';
            }else{
                lastdig='1';
            }
        }
        cout<<lastdig<<endl;
    }
    return 0;
}
