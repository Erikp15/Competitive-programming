#include <iostream>
#include <iomanip>
using namespace std;

int comb(int a, int b){
    int ans = 1;
    for (int i=0; i<a; ++i){
        ans*=b-i;
        ans/=i+1;
    }
    return ans;
}

int n, m, p;
double ans=0;

int main(){
    cin>>n>>m;
    for (p=-1; n>0; ++p) n/=2;

    double prob=1;
    for (int i=0; i<p; ++i) prob*=2.0/3;

    for (int i=0; m > 0; ++i){
        int c = comb(i, p);
        ans += prob*min(c, m);
        m -= min(c, m);
        prob/=2;
    }
    cout<<fixed<<setprecision(10)<<ans<<"\n";
    return 0;
}
