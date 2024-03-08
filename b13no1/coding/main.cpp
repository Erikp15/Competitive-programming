#include <bits/stdc++.h>

using namespace std;

int main(){
    string encoded_number,all_possible_digits[10];
    cin>>encoded_number;
    vector<int> all_answers;
    all_possible_digits[0]="11";
    all_possible_digits[1]="100";
    all_possible_digits[2]="101";
    all_possible_digits[3]="110";
    all_possible_digits[4]="111";
    all_possible_digits[5]="1000";
    all_possible_digits[6]="1001";
    all_possible_digits[7]="1010";
    all_possible_digits[8]="1011";
    all_possible_digits[9]="1100";
    for(int i=0;i<100000;i++){
        string curr_string_of_num="";
        int curr_number_index=i;
        while(curr_number_index>=0){
            curr_string_of_num+=all_possible_digits[curr_number_index%10];
            //cout<<all_possible_digits[curr_number_index%10]<<endl;
            if(curr_number_index==0)break;
            curr_number_index/=10;
        }
        if(encoded_number.compare(curr_string_of_num)==0){
            all_answers.push_back(i);
        }
    }
    if(all_answers.empty()){cout<<-1<<endl;return 0;}
    sort(all_answers.begin(),all_answers.end());
    for(int i=0;i<(int)all_answers.size();i++){
        cout<<all_answers[i]<<endl;
    }
    return 0;
}
