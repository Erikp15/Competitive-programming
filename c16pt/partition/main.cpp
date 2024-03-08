#include <iostream>

using namespace std;

bool prefix[200001];
long long ournumbers[200001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long m,n,nums[201],maxsum=0,sizeofournums=0;
    cin>>m;
    for(long long j=0;j<m;j++){
        maxsum=0;
        sizeofournums=0;
        cin>>n;
        prefix[0]=true;
        for(long long i=0;i<n;i++){
            cin>>nums[i];
            maxsum+=nums[i];
            ournumbers[sizeofournums]=nums[i];
            prefix[nums[i]]=true;
            for(long long d=0;d<=sizeofournums;d++){
                if(prefix[ournumbers[d]+nums[i]]==false){
                    prefix[ournumbers[d]+nums[i]]=true;
                    cout<<ournumbers[d]+nums[i]<<" ";
                    ournumbers[sizeofournums]=ournumbers[d]+nums[i];
                    sizeofournums++;
                }
            }
        }
        if(maxsum%2!=0){cout<<"0"<<endl; continue;}
        cout<<endl<<prefix[maxsum/2]<<endl;
        for(long long a=0;a<maxsum;a++){prefix[a]=false;}
    }
    return 0;
}
//https://pastebin.com/GY1hkTWG










































/*
/// пролетен, 2016, С2

#include<iostream>
#include<vector>
using namespace std;

const int MAX_SUM = 200000;

bool sumPossible[MAX_SUM + 1];
vector<int> sumsSoFar;

void reset() {
    sumsSoFar.clear();

    for(int i = 0; i <= MAX_SUM; ++i) {
        sumPossible[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for(int currT = 0; currT < t; ++currT) {
        int n;
        cin >> n;

        int totalSum = 0;
        for(int i = 0; i < n; ++i) {
            int currNumber;
            cin >> currNumber;
            totalSum += currNumber;

            int numberOfSumsBeforeCurrent = sumsSoFar.size();

            if(!sumPossible[currNumber]) {
                sumPossible[currNumber] = true;
                sumsSoFar.push_back(currNumber);
            }

            for(int j = 0; j < numberOfSumsBeforeCurrent; ++j) {
                int newSum = sumsSoFar[j] + currNumber;

                if(!sumPossible[newSum]) {
                    sumPossible[newSum] = true;
                    sumsSoFar.push_back(newSum);
                }
            }
        }

        if(totalSum % 2 != 0) {
            cout << 0;
        }
        else if(!sumPossible[totalSum / 2]) {
            cout << 0;
        }
        else {
            cout << 1;
        }

        cout << endl;

        reset();
    }


    return 0;
}
*/
