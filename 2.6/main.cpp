#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

class student{
public:
    string name;
    ll group;
    ld ses;
    student(){
        cin>>name>>group>>ses;
    }
    bool operator<(const student& a){
        return this->group<a.group;
    }
};

int main(){
    fstream file;
    file.open("output26.txt",ios::out);
    ll n=10;
    //cin>>n;
    student stud1[n];
    sort(stud1,stud1+n);
    for(ll i=0;i<n;i++){
        if(stud1[i].ses>4.0){
            file<<stud1[i].name<<endl;
        }
    }
    return 0;
}
