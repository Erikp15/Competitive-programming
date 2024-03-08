#include <bits/stdc++.h>

using namespace std;

int main(){
    long long magic_numbers[9],magic_square_count=0,sum_in_each_row=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>magic_numbers[i*3+j];
            sum_in_each_row+=magic_numbers[i*3+j];
        }
    }
    sum_in_each_row/=3;
    sort(magic_numbers,magic_numbers+9);
    do{

        if(magic_numbers[0]+magic_numbers[1]+magic_numbers[2]!=sum_in_each_row){continue;}
        if(magic_numbers[3]+magic_numbers[4]+magic_numbers[5]!=sum_in_each_row){continue;}
        if(magic_numbers[6]+magic_numbers[7]+magic_numbers[8]!=sum_in_each_row){continue;}
        if(magic_numbers[0]+magic_numbers[3]+magic_numbers[6]!=sum_in_each_row){continue;}
        if(magic_numbers[1]+magic_numbers[4]+magic_numbers[7]!=sum_in_each_row){continue;}
        if(magic_numbers[2]+magic_numbers[5]+magic_numbers[8]!=sum_in_each_row){continue;}
        if(magic_numbers[0]+magic_numbers[4]+magic_numbers[8]!=sum_in_each_row){continue;}
        if(magic_numbers[2]+magic_numbers[4]+magic_numbers[6]!=sum_in_each_row){continue;}
        magic_square_count++;
    }while(next_permutation(magic_numbers,magic_numbers+9));

    cout << magic_square_count << endl;
    return 0;
}
/*
1 2 3 4 5 6 7 8 9

9 8 7 3 1 2 4 5 6

1 1 1 1 1 1 1 1 1
*/
