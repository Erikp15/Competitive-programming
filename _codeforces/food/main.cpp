#include <bits/stdc++.h>
#include <random>

using namespace std;

string a[20];

void gen(){
    a[0]="indian";
    a[1]="duner";
    a[2]="burger";
    a[3]="pizza";
    a[4]="bds";
    a[5]="chinese";
    a[6]="rolling dogs";
    a[7]="divaka";
    a[8]="kfc";
    a[9]="wok to walk";
    srand(time(nullptr));
    cout<< a[(rand() % 10)]<<endl;
}

int main(){
    gen();
    return 0;
}
