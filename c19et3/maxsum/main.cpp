/*#include <iostream>

using namespace std;
int fora[100000],forb[100000];
bool forabool[10000],forbbool[10000];
int maxfora[10000],maxforb[10000];
int a[100000],b[1000];
int main(){
    long long n,k;
    cin>>n>>k;
    forabool[0]=true;
    forbbool[0]=true;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    for(long long i=0;i<k;i++){
        cin>>b[i];
    }
    fora[0]=a[0];
    forb[0]=a[n-1];
    for(long long i=0;i<n;i++){
        for(long long j=0;j<k;j++){
            if(i>=b[j]){
                fora[i]=fora[i-b[j]]+a[i];
                forabool[i]=true;
                continue;
            }
            if(forabool[i-b[j]]==true){
                fora[i]=fora[i-b[j]]+a[i];
                forabool[i]=true;
            }
        }
    }
    for(long long i=0;i<n;i++){
        cout << fora[i] << " ";
    }
    return 0;
}
*/
#include<iostream>
#include<vector>
using namespace std;

int n, m, k;

string currStr;
vector<int> currInd;

bool inSubseq[28];

void countOccurences(int numbersLeft, int currHash) {
    if(numbersLeft == 0) {
        /// TODO: do task stuff

        for(int i = 0; i < currInd.size(); ++i) {
            cout << currStr[currInd[i]];
        }

        cout << " " << currHash;

        cout << endl;

        return;
    }

    int nextNumber;
    if(currInd.empty()) {
        nextNumber = 0;
    }
    else {
        nextNumber = currInd[currInd.size() - 1] + 1;
    }

    for(; nextNumber < currStr.size(); ++nextNumber) {
        if(inSubseq[currStr[nextNumber] - 'a']) {
            continue;
        }

        currInd.push_back(nextNumber);
        inSubseq[currStr[nextNumber] - 'a'] = true;
        int nextHash = currHash * m + (currStr[nextNumber] - 'a');

        countOccurences(numbersLeft - 1, nextHash);

        inSubseq[currStr[nextNumber] - 'a'] = false;
        currInd.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;

    for(int i = 0; i < n; ++i) {
        cin >> currStr;
        countOccurences(k, 0);

        /// TODO: dobavi 1 za vsichki
        /// stringove, koito v momenta sa bili sreshnati
    }

    /// TODO: nameri maks

    return 0;
}
