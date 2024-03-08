#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=2e5+1;
string a,b;
ll radix_a[26],radix_b[26];
bool is_match[26][26];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b;
    for(ll i=0;i<26;i++){
        for(ll j=0;j<26;j++){
            is_match[i][j]=true;
        }
    }
    for(ll i=0;i<a.size();i++){
        radix_a[a[i]-'a']++;
        radix_b[b[i]-'a']++;
    }
    for(ll i=0;i<26;i++){
        if(radix_a[i]==0){
            is_match[i][i]=false;
        }else{
            is_match[i][i]=(radix_a[i]==radix_b[i]);
        }
    }
    for(ll i=0;i<26;i++){
        radix_a[i]=0;
        radix_b[i]=0;
    }
    for(ll i=0;i<26;i++){
        for(ll p1=0,p2=0;p1<a.size()-1 or p2<a.size()-1;){
            if(p1<a.size()-1 and (a[p1]!='a'+i or p2==a.size()-1)){
                radix_a[a[p1]-'a']++;
                p1++;
            }
            if(p2<a.size()-1 and (b[p2]!='a'+i or p1==a.size()-1)){
                radix_b[b[p2]-'a']++;
                p2++;
            }
            if(a[p1]=='a'+i and b[p2]=='a'+i){
                radix_a[a[p1]-'a']++;
                radix_b[b[p2]-'a']++;
                for(ll j=0;j<26;j++){
                    if(i!=j)
                        is_match[i][j]=(is_match[i][j] && (radix_a[j]==radix_b[j]));
                }
                p1++;
                p2++;
            }
            //cout<<i<<endl;
        }
        for(ll i=0;i<26;i++){
            radix_a[i]=0;
            radix_b[i]=0;
        }
    }
    ll q;
    cin>>q;
    while(q--){
        string query;
        cin>>query;
        bool is_valid=true;
        for(ll i=0;i<query.size();i++){
            for(ll j=i;j<query.size();j++){
                is_valid=(is_valid && is_match[query[i]-'a'][query[j]-'a']);
            }
        }
        if(is_valid){
            cout<<"Y";
        }else{
            cout<<"N";
        }
    }
    cout<<endl;
    return 0;
}
/*
aaasdfafdsf
aaaasdfasdf
1
a
*/
