#include<iostream>
#include<stack>
using namespace std;

stack<char> t;

string r,s;

char mul(char a, char b)
{
  if((a=='1')&&(b=='1')) return '1';
  else return '0';
}

char sum(char a, char b)
{
  if((a=='1')&&(b=='1')) return '0';
  else if((a=='0')&&(b=='0')) return '0';
  else return '1';
}

int run()
{
  while(!t.empty()) t.pop();
  r.clear();
  s.clear();
  cin >> s;
  int e;
  for(int i=0;i<s.size();i++)
  {
    if((s[i]>='0')&&(s[i]<='9')) e=((int)(s[i]-'0'))%2;
    else r = r + (e==0?'0':'1')+s[i];
  }
  r = r + (e==0?'0':'1');

  r = r + '+';
  char c='0';
  int i=0;
  while(i<r.size())
  {
    char p=r[i];i++;
    if(r[i]=='*') t.push(p);
    else if(r[i]=='+')
    {
     while(!t.empty()){char v=t.top();t.pop();p=mul(p,v);}
     c = sum(c,p);
    }
    i++;
  }

   cout << c << endl;
}

int main()
{
  int nt; cin >> nt;
  for(int i=1;i<=nt;i++) run();
}
