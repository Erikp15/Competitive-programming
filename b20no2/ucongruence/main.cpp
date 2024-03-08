#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n,u;
    cin>>n>>u;
    vector<int> all_numbers(n);
    set<int> unused;

    for(auto i=n-1;i>=0;--i)cin>>all_numbers[i];

    for(auto i=1;i<=u;i++)if(find(all_numbers.begin(),all_numbers.end(),i)!=all_numbers.end()-1)unused.insert(i);

    while(true){
        auto curr_pos=0;
        if(unused.empty()){
            unused.insert(all_numbers[curr_pos]);
            curr_pos++;
        }
        while(all_numbers[curr_pos]>*unused.rbegin()){

            unused.insert(all_numbers[curr_pos]);
            curr_pos++;
        }
        if(curr_pos>=n)break;
        unused.insert(all_numbers[curr_pos]);
        all_numbers[curr_pos]=*upper_bound(unused.begin(),unused.end(),all_numbers[curr_pos]);
        unused.erase(all_numbers[curr_pos]);
        for(auto i=curr_pos-1;i>=0;i--){
            all_numbers[i]=*unused.begin();
            unused.erase(unused.begin());
        }
        for(auto i=n-1;i>=0;--i)cout<<all_numbers[i]<<" ";
        cout<<endl;
    }
    return 0;
}
