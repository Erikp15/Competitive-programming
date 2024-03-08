#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

    vector<ll> all_syls;
    map<ll,string> syl_2_pos;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string alphabet,vowels,non_vowels,actual_vowels;
    cin>>alphabet>>vowels;
    ll n;
    cin>>n;
    for(ll i=0;i<(ll)alphabet.size();i++){
        bool is_vowel=false;
        for(ll j=0;j<(ll)vowels.size();j++){
            if(alphabet[i]==vowels[j]){
                is_vowel=true;
            }
        }
        if(!is_vowel){
            non_vowels+=alphabet[i];
        }else{
            actual_vowels+=alphabet[i];
        }
    }
    for(ll i=0;i<(ll)non_vowels.size();i++){
        for(ll j=0;j<(ll)actual_vowels.size();j++){
            string tmp;
            tmp+=(char)non_vowels[i];
            tmp+=(char)actual_vowels[j];
            syl_2_pos.insert(make_pair(i*vowels.size()+j,tmp));
        }
    }
    ll base=(non_vowels.size()*vowels.size());
    ll syl_length=1,sum=pow(base,syl_length);
    while(n/sum>0){
        syl_length++;
        sum+=pow(base,syl_length);
    }
    sum-=pow(base,syl_length);
    if(n==sum){
        for(ll i=0;i<syl_length-1;i++){
            cout<<syl_2_pos[non_vowels.size()*vowels.size()-1];
        }
        cout<<endl;
        return 0;
    }
    n=n-sum;
    syl_length--;
    for(ll i=0;i<=syl_length;i++){
        all_syls.push_back(n%(non_vowels.size()*vowels.size()));
        n/=(non_vowels.size()*vowels.size());
    }
    for(ll i=(ll)all_syls.size()-1;i>=0;i--){
        if(i!=0){
            cout<<syl_2_pos[all_syls[i]];
        }else{
            cout<<syl_2_pos[all_syls[i]-1];
        }
    }
    cout<<endl;
    return 0;
}
/*
RBAZ
AR
20
ZAZA
*/
