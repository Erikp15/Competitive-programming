#include<iostream>
using namespace std;

const int MAX_N = 200;

string a, b;
int ans[MAX_N][MAX_N];

int main() {
    cin>>a;
    for(int i=a.size()-1;i>=0;i--){
        b[a.size()-i-1]=a[i];
    }
    for(int i=0;i<a.size()+1;i++){
        ans[i][0]=0;
    }
    for(int i=0;i<a.size()+1;i++){
        ans[0][i]=0;
    }
    for(int i=1;i<a.size()+1;i++){
        for(int j=1;j<a.size()+1;j++){
            if(a[i-1]==b[j-1]){
                ans[i][j]=ans[i-1][j-1]+1;
            }else{
                ans[i][j]=max(ans[i][j-1],ans[i-1][j]);
            }
        }
    }
    for(int i=0;i<a.size()+1;++i){
        for(int j=0;j<a.size()+1;++j) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<ans[a.size()][a.size()] << endl;

    return 0;

}
/*
#include<iostream>
using namespace std;

const int MAX_N = 1001;

string a, b;
int ans[MAX_N][MAX_N];

int main() {
    cin >> a >> b;

    for(int i = 0; i < a.size() + 1; ++i) {
        ans[i][0] = 0;
    }

    for(int i = 0; i < b.size() + 1; ++i) {
        ans[0][i] = 0;
    }

    for(int i = 1; i < a.size() + 1; ++i) {
        for(int j = 1; j < b.size() + 1; ++j) {
            if(a[i - 1] == b[j - 1]) {
                ans[i][j] = ans[i - 1][j - 1] + 1;
            }
            else {
                ans[i][j] = max(ans[i][j - 1], ans[i - 1][j]);
            }
        }
    }

    for(int i = 0; i < a.size() + 1; ++i) {
        for(int j = 0; j < b.size() + 1; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    cout << ans[a.size()][b.size()] << endl;

    string lcs;
    int aInd = a.size(), bInd = b.size();

    ///while(ans[aInd][bInd] != 0) {
    while(aInd != 0 && bInd != 0) {
        if(a[aInd - 1] == b[bInd - 1]) {
            lcs.push_back(a[aInd - 1]);

            --aInd;
            --bInd;
        }
        else if(ans[aInd - 1][bInd] < ans[aInd][bInd - 1]){
            --bInd;
        }
        else {
            --aInd;
        }
    }

    for(int i = lcs.size() - 1; i >= 0; --i) {
        cout << lcs[i];
    }

    return 0;
}
*/
