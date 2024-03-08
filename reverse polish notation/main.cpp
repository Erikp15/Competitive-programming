#include <bits/stdc++.h>

using namespace std;

void operate(char operator_,stack<int>& numbers,vector<char>& notation){
    int number_1,number_2;
    bool is_empty_=false;
    if(!numbers.empty()){number_1=numbers.top(); numbers.pop(); is_empty_=true;}
    if(!numbers.empty()){
        number_2=numbers.top(); numbers.pop();
        notation.push_back(number_2+'0');
    }
    if(is_empty_==true){
        notation.push_back(number_1+'0');
    }
    notation.push_back(operator_);
}

bool is_a_operator(char operator_){
    return operator_=='+' || operator_=='-' || operator_=='*' || operator_=='/';
}

int priority(char operator_){
    if(operator_=='+' || operator_=='-'){
        return 1;
    }
    if(operator_=='*' || operator_=='/'){
        return 2;
    }
    return -1;
}

vector<char> convert_to_polish(string& equation,vector<char>& polish_notation){
    stack<int> numbers;
    stack<char> operators;
    for(int i=0;i<(int)equation.size();i++){
        if(equation[i]=='('){
            operators.push(equation[i]);
        }else{
            if(equation[i]==')'){
                while(operators.top()!='('){
                    operate(operators.top(),numbers,polish_notation);
                    operators.pop();
                }
                operators.pop();
            }else{
                if(is_a_operator(equation[i])){
                    while(!operators.empty() and priority(equation[i])<=priority(operators.top())){
                        operate(operators.top(),numbers,polish_notation);
                        operators.pop();
                    }
                    operators.push(equation[i]);
                }else{
                    int number=0;
                    while(i<(int)equation.size() and equation[i]<='9' and equation[i]>='0'){
                        number=number*10+equation[i]-'0';
                        i++;
                    }
                    i--;
                    numbers.push(number);
                }
            }
        }
    }
    while(!operators.empty()){
        operate(operators.top(),numbers,polish_notation);
        operators.pop();
    }
    return polish_notation;
}

int main(){
    string equation;
    vector<char> reverse_polish_notation,standard_notation;
    cin>>equation;
    reverse_polish_notation=convert_to_polish(equation,reverse_polish_notation);
    for(int i=0;i<(int)reverse_polish_notation.size();i++){
        cout<<reverse_polish_notation[i];
    }

    cout<<endl;
    return 0;
}
/*
1+2*3*4+(5-6)*(7*8+9)
*/
