#include<iostream>
#include<string>
using namespace std;

extern std::string find_reverse (int, int, int[][2]);

static const int MAXM=1.5e6;
static int connections[MAXM][2];
int main () {
    int n,m;
    cin >> n >> m ;
    for (int i=0; i<m; i++) {
        cin >> connections[i][0] >> connections[i][1] ;
    }
    string ans=find_reverse(n,m,connections);
    cout << ans ;
    cout << endl ;
}
