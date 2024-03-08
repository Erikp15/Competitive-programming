#include <bits/stdc++.h>

class number{
    private:
        long long value;

    public:
        long long index;
        number(long long start_index,long long start_value){
            index=start_index; value=start_value;
        }
        long long get_value(){
            return value;
        }
        void change_value(long long change_to){
            value=change_to;
        }
        bool operator >(const number& a)const{
            if(a.value==value){
                return a.index<index;
            }
            return a.value<value;
        }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    long long n;
    std::cin>>n;
    std::set<number,std::greater<number> > sorted_numbers;
    for(auto i=0;i<n;++i){
        long long b; std::cin>>b;
        number a(i,b);
        sorted_numbers.insert(a);
    }
    for(auto it:sorted_numbers)std::cout<<it.get_value()<<" ";

    return 0;
}
