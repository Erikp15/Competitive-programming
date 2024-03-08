#include "grader.h"
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string find_next(string p){
    map<char,ll> char_2_order;
    map<ll,char> order_2_char;
    char_2_order['A']=1;
    char_2_order['C']=2;
    char_2_order['G']=3;
    char_2_order['T']=4;
    order_2_char[1]='A';
    order_2_char[2]='C';
    order_2_char[3]='G';
    order_2_char[4]='T';
    string ans,temp;
    ans=""; temp="";
    ll k=p.size();
    temp=p;
    pair<string,string> res=get_min_max(temp);
    if(res.first.size()!=0){
        return res.first;
    }
    for(ll i=k-1;i>=0;i--){
        ll cha=char_2_order[p[i]];
        if(cha==1){
            temp[i]='_';
            res=get_min_max(temp);
            continue;
        }
        if(cha==2){
            temp[i]='G';
            res=get_min_max(temp);
            if(res.first.size()!=0){
                for(ll j=i+1;j<k;j++){
                    temp[j]='?';
                }
                res=get_min_max(temp);
                return res.first;
            }
        }
        temp[i]='T';
        res=get_min_max(temp);
        if(res.first.size()!=0){
            for(ll j=i+1;j<k;j++){
                temp[j]='?';
            }
            res=get_min_max(temp);
            return res.first;
        }
    }
    return "";
}

/*
AC__
TTTT


"ACCA"
"ACCT"
"ACGT"
"AGCT"
"GGCA"
"TAAC"
"TATA"
"TATT"
"TTTA"
*/
