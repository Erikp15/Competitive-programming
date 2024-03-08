#include <bits/stdc++.h>

using namespace std;

struct bracket{
    long long index;
    long long paired_partner_index=-1;
};

int main(){
    string equation;
    cin>>equation;
    bracket all_brackets[equation.length()];
    for(int i=0;i<equation.length();i++){
        if(equation[i]=='('){
            for(int j=i;j<equation.length();j++){
                if(equation[i]=='('){
                    all_brackets[i].index
                }
            }
        }
    }
    cout << "Hello world!" << endl;
    return 0;
}
