#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    long long n;
    cin>>n;
    long long a[n],countt=0;
    for(int i=1;i<=n;i++){
        a[i-1]=i;
    }

      do{
        long long test=0,fuck=1;
        for(int i=n-1;i>=0;i--){
            if(a[i]>9){
                test+=a[i]%10*fuck;
                fuck*=10;
                test+=a[i]/10*fuck;
                fuck*=10;
            }else{
                test+=a[i]*fuck;
                fuck*=10;
            }
        }
        if(test%16==0){cout<<test<<" ";countt++;}
    }while(next_permutation(a,a+n));
    cout << countt << endl;
    return 0;
}

/*6
123456 134256 135264 145632 146352 153264 156432 164352 213456 231456 241536 245136
314256 315264 321456 345216 346512 351264 352416 364512 415632 416352 421536
425136 435216 436512 451632 453216 463152 465312 513264 516432 531264 532416
541632 543216 614352 634512 643152 645312

6
1264 1456 1536 1632 2416 3152 3216 3264 3456 4256 4352 4512 5136 5216 5264 5312
5632 6352 6432 6512
