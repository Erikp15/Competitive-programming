#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
int main(int argc, const char* argv[]){
    ifstream sol(argv[2]), out(argv[3]);
    double correct, output, dummy;
    sol>>correct;
    if (!(out>>output)){
        cerr<<"Wrong output format\n";
        cout<<0<<endl;
        return 0;
    }
    if (out>>dummy || !out.eof()){
        cerr<<"Wrong output format\n";
        cout<<0<<endl;
        return 0;
    }
    if (fabs(correct - output) > 1e-8){
        cerr<<"Wrong answer\n";
        cout<<0<<endl;
        return 0;
    }else{
        cerr<<"Correct\n";
        cout<<1<<endl;
    }
    return 0;
}
