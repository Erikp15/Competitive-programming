#include <bits/stdc++.h>

using namespace std;

    int num_of_each_dig[10];

int main(){
    string input_num;
    cin>>input_num;
    string min_num, max_num, sum_num;
    for(int i=0;i<(int)input_num.size();i++){
        num_of_each_dig[input_num[i]-'0']++;
    }
    for(int i=0;i<10;i++){
        if(i==0 and num_of_each_dig[i]>0){
            for(int j=1;j<10;j++){
                if(num_of_each_dig[j]>0){
                    min_num.push_back(j+'0');
                    num_of_each_dig[j]--;
                    break;
                }
            }
        }
        for(int j=0;j<(int)num_of_each_dig[i];j++){
            min_num.push_back(i+'0');
        }
        num_of_each_dig[i]=0;
    }
    for(int i=0;i<(int)input_num.size();i++){
        num_of_each_dig[input_num[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        for(int j=0;j<(int)num_of_each_dig[i];j++){
            max_num.push_back(i+'0');
        }
        num_of_each_dig[i]=0;
    }
    /*
    for(int i=0;i<min_num.size();i++){
        cout<<min_num[i];
    }
    cout<<endl;
    for(int i=0;i<max_num.size();i++){
        cout<<max_num[i];
    }
    */
    int carry=0;
    for(int i=0;i<(int)min_num.size();i++){
        sum_num.push_back((min_num[min_num.size()-i-1]-'0'+max_num[min_num.size()-i-1]-'0'+carry)%10+'0');
        carry=(min_num[min_num.size()-i-1]-'0'+max_num[min_num.size()-i-1]-'0'+carry)/10;
    }
    if(carry>0)sum_num.push_back(carry+'0');
    for(int i=sum_num.size()-1;i>=0;i--){
        cout<<sum_num[i];
    }
    cout<<endl;
    return 0;
}
