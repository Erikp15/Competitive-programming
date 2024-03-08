#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll Size=1e2+1;

class state{
public:
    ll depth,link,terminal_link;
    ll is_terminal;
    ll last_char;
    ll next[26];
    state(){
        this->is_terminal=0;
        this->depth=0;
        this->link=0;
        for(ll i=0;i<26;i++){
            this->next[i]=0;
        }
    }
};

string a,p[Size];
state states[Size];
ll sz;
vector<pair<ll,ll>> ans;

void add(string s,ll match){
    ll pos=0;
    for(ll i=0;i<s.size();i++){
        if(!states[pos].next[s[i]-'a']){
            states[pos].next[s[i]-'a']=++sz;
            states[sz].depth=states[pos].depth+1;
            states[sz].last_char=s[i]-'a';
            pos=sz;
        }else{
            pos=states[pos].next[s[i]-'a'];
        }
    }
    states[pos].is_terminal=match;
}

void get_links(){
    queue<pair<ll,ll>> to_process;
    to_process.push({0,-1});
    while(!to_process.empty()){
        ll curr_state=to_process.front().first;
        ll pos=to_process.front().second;
        ll cha=states[curr_state].last_char;
        to_process.pop();
        if(curr_state!=0){
            pos=states[pos].link;
            while(pos!=-1 and !states[pos].next[cha]){
                pos=states[pos].link;
            }
            if(pos==-1){
                states[curr_state].link=0;
                states[curr_state].terminal_link=0;
            }else{
                states[curr_state].link=states[pos].next[cha];
                if(states[states[pos].next[cha]].is_terminal){
                    states[curr_state].terminal_link=states[pos].next[cha];
                }else{
                    states[curr_state].terminal_link=states[states[pos].next[cha]].terminal_link;
                }
            }
        }
        for(ll i=0;i<26;i++){
            ll next=states[curr_state].next[i];
            if(next){
                to_process.push({next,curr_state});
            }
        }
    }
}

void use_text(string s){
    ll pos=0;
    for(ll i=0;i<s.size();i++){
        if(states[pos].next[s[i]-'a']){
            pos=states[pos].next[s[i]-'a'];
        }else{
            while(pos!=-1 and !states[pos].next[s[i]-'a']){
                pos=states[pos].link;
            }
            if(pos==-1){
                pos=0;
            }else{
                pos=states[pos].next[s[i]-'a'];
            }
        }

        if(states[pos].is_terminal){
            ans.push_back({states[pos].is_terminal,i+2-states[pos].depth});
        }
        ll term=states[pos].terminal_link;
        while(states[term].is_terminal){
            ans.push_back({states[term].is_terminal,i+2-states[term].depth});
            term=states[term].terminal_link;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    states[0].link=-1;
    states[0].depth=0;
    sz=0;
    for(ll i=0;i<n;i++){
        cin>>p[i];
        add(p[i],i+1);
    }
    get_links();
    cin>>a;
    use_text(a);
    sort(ans.begin(),ans.end());
    for(ll i=0;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
    return 0;
}
/*
4
bab
bac
cbd
aba
abacb

5
abacb
bab
bac
cbd
aba
abacbdababacbd

5
a
aa
aaa
aaaa
aaaaa
aaaaaaaaaa
*/
