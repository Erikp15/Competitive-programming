#include <iostream>
using namespace std;
int N;
char a[36][36];
char b[37];
int main()
{char start;
 cin>>N;
 for (int i=0;i<N;i++)
  cin>>&b[i*N];
 b[N*N]=0;
 for (int p=0;p<N;p++)  //סכוהגאש םאבמנ מע N נוהא
 {if (!p) start=0;
  else start=a[(p-1)*N][0]+1;
  for (int r=0;r<N;r++)   //סכוהגאש נוה ג םאבמנא
  {if (r) start=a[p*N+r-1][N-1]+1;
   for (int c=0;c<N*N;c++)  //סכוהגאשא ךכועךא
    a[p*N+r][c]=(start+c)%(N*N);
  }
 }
 for (int r=0;r<N*N;r++)
 {for (int c=0;c<N*N;c++) cout<<b[(int)a[r][c]];
  cout<<endl;   
 }
 return 0;
}