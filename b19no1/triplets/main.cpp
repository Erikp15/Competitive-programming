#include <iostream>

using namespace std;
bool rad[201][201][201];
int main(){
    int n;
    cin>>n;
    int a[201],counter=0,counter2=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(!(a[i]>=a[j]+a[k] or a[j]>=a[i]+a[k] or a[k]>=a[j]+a[i]) and rad[a[i]][a[j]][a[k]]==false and !(a[i]==a[j] or a[j]==a[k] or a[k]==a[i])){
                    counter2++;
                    rad[a[i]][a[j]][a[k]]=true;
                    rad[a[i]][a[k]][a[j]]=true;
                    rad[a[j]][a[i]][a[k]]=true;
                    rad[a[j]][a[k]][a[i]]=true;
                    rad[a[k]][a[j]][a[i]]=true;
                    rad[a[k]][a[i]][a[j]]=true;
                }
            }
        }
    }
    for(long long i=0;i<201;i++){
        for(long long j=0;j<201;j++){
            for(long long k=0;k<201;k++){
                if(rad[i][j][k]==true){counter++;}
            }
        }
    }
    cout<<counter2<<endl;
    return 0;
}
