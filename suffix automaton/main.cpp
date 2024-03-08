#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class state {
public:
    ll len, link, dp;
    ll next[26];
};

const ll MAX_N=1001;
state states[MAX_N*2];
ll max_elem=1, last=0;

void add(char c) {
    ll curr=max_elem++;
    states[curr].len=states[last].len + 1;
    ll prev=last;
    while(prev!=-1 and !states[prev].next[c-'a']) {
        states[prev].next[c-'a']=curr;
        prev=states[prev].link;
    }
    if(prev==-1){
        states[curr].link=0;
    }else{
        ll next_state=states[prev].next[c-'a'];
        if(states[prev].len+1==states[next_state].len) {
            states[curr].link=next_state;
        }else{
            ll clone=max_elem++;
            states[clone].len=states[prev].len+1;
            for(ll i=0;i<26;i++){
                states[clone].next[i]=states[next_state].next[i];
            }
            states[clone].link=states[next_state].link;
            while(prev!=-1 and states[prev].next[c-'a']==next_state) {
                states[prev].next[c-'a']=clone;
                prev=states[prev].link;
            }
            states[next_state].link=states[curr].link=clone;
        }
    }
    last=curr;
}

void solve(string a,string b){
    states[0].len=0;
    states[0].link=-1;
    max_elem=1;
    last=0;
    cout<<a<<endl;
    cout<<b<<endl;
    for(ll i=0;i<a.size();i++){
        add(a[i]);
    }
    ll best=0,ans=0,pos=0,len=0;
    for(ll i=0;i<b.size();i++){
        while(pos!=-1 and !states[pos].next[b[i]-'a']){
            pos=states[pos].link;
            len=states[pos].len;
        }
        if(states[pos].next[b[i]-'a']){
            pos=states[pos].next[b[i]-'a'];
            len++;
        }
        if(len>best){
            best=len;
            ans=i;
        }
    }
    cout<<best<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll q;
    cin>>q;
    string a,b;
    cin>>a>>b;
    while(q--){
        ll x,y,z;
        cin>>x>>y>>z;
        solve(a.substr(0,x),b.substr(y,z-y));
    }
    return 0;
}
/*
abcbc
*/
