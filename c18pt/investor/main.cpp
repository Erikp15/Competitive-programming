/*
#include<iostream>

using namespace std;

long long n;
long long last;
long long fib[50];

int main() {
    cin >> n >> last;
    if(n-1>last){cout << 0 << endl; return 0;}
    fib[0] = 1;
    fib[1] = 1;

    for(int i = 2; i < 50; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    long long prevR = fib[n - 2];
    long long currR = fib[n - 3];

    long long prevS = 1;
    long long currS = 0;

    long long prevT = 0;
    long long currT = 1;

    while(currR != 0) {
        long long q = prevR / currR;

        long long nextR = prevR - q * currR;
        long long nextS = prevS - q * currS;
        long long nextT = prevT - q * currT;

        prevR = currR;
        prevS = currS;
        prevT = currT;

        currR = nextR;
        currS = nextS;
        currT = nextT;
    }

    if(last % prevR != 0) {
        cout << 0 << endl;
        return 0;
    }

    long long x0 = prevS * (last / prevR);
    long long y0 = prevT * (last / prevR);
    long long p = y0 / fib [n - 3];
    long long l = x0 / fib [n - 2];
    if(x0 % fib [n - 2] == 0 or x0 < 0){
        l++;
    }
    if(y0 % fib [n - 3] == 0 or y0 < 0){
        p--;
    }
    if(p < l){cout << 0 << endl; return 0;}
    cout << p - l + 1 << endl;
    return 0;
}
*/
#include<iostream>
using namespace std;

long long n;
long long last;
long long fib[50];

int main() {
    cin >> n >> last;

    fib[0] = 1;
    fib[1] = 1;

    for(int i = 2; i < 50; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    long long prevR = fib[n - 2];
    long long currR = fib[n - 3];

    //cout << "fib N-2 = " << prevR << endl;
    //cout << "fib N-3 = " << currR << endl;

    /// currS * fib[n - 2] + currT * fib[n - 3] == currR
    long long prevS = 1;
    long long currS = 0;

    long long prevT = 0;
    long long currT = 1;

    while(currR != 0) {
        long long q = prevR / currR;

        long long nextR = prevR - q * currR;
        long long nextS = prevS - q * currS;
        long long nextT = prevT - q * currT;

        prevR = currR;
        prevS = currS;
        prevT = currT;

        currR = nextR;
        currS = nextS;
        currT = nextT;
    }

    long long x0 = prevS * (last / prevR);
    long long y0 = prevT * (last / prevR);

    //cout << x0 << " " << y0 << endl;


    long long L = -x0 / fib[n - 3];
    //cout << x0 << " " << fib[n - 3] << " " << L << endl;
    if(x0 % fib[n - 3] == 0 || x0 < 0) {
        ++L;
    }


    long long P = y0 / fib[n - 2];
    //cout << y0 << " " << fib[n - 2] << " " << P << endl;
    if(y0 % fib[n - 2] == 0 || y0 < 0) {
        --P;
    }

    if(P < L) {
        cout << 0 << endl;
    }
    else {
        cout << P - L + 1;
    }

    return 0;
}
