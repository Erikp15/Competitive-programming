#include <cstdio>
#include <stack>
using namespace std;

int n;
int p;
int v;

int main() {
  int t;
  int rez;
  stack<int> st;
  scanf("%d",&n);
  for (t=1;t<=5;t++) {
    st = stack<int>();
    v=1;
    rez=1;
    for (int i=1;i<=n;i++){
        scanf("%d", &p);
        while (v<=p){
            st.push(v);
            v++;
        }
        if (p == st.top())
            st.pop();
        else {
            rez=0;
        }
    }
    printf("%d",rez);
  }
  printf("\n");


return 0;
}
