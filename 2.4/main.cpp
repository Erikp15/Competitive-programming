#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

class student{
public:
    string name;
    ll num;
    ld grade;
    student(){
        cin>>num>>name>>grade;
    }
};

int main(){
    fstream file;
    file.open("output24.txt",ios::out);
    ll n=10,bad=0;
    //cin>>n;
    student students[n];
    ld avg=0;
    for(ll i=0;i<n;i++){
        if(students[i].grade>=5.5){
            file<<students[i].name<<endl;
        }
        avg+=students[i].grade;
        if(students[i].grade<=4.5 and students[i].grade>=3.0){
            bad++;
        }
    }
    file<<avg/n<<endl<<bad<<endl;
    return 0;
}
