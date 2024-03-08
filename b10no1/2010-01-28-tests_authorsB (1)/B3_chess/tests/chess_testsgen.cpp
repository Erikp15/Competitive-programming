#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <ctime>
using namespace std;

char bat[200] = "for %%i in (00 01 02 03 04 05 06 07 08 09 10) do chess.exe<chess.%%i.in>chess.%%i.sol\n",
     name[40],
     pos [11][200]= {
      "h1\nb5\nd7\nh6\nc5\nf5\ne3\n",
      "g6\nd2\nf8\nb6\nf4\n",
      "a2\nd2\nc4\nf5\nb6\ne7\nh8\ng3\n",
      "f5\nc5\nc2\nf8\n",
      "e5\nf6\ng7\nc3\nb2\n",
      "b6\nf4\nd2\nf6\nb4\nd6\nf2\nb2\nd8\nd4\n",
      "a8\nb5\nb6\nb7\nc5\nc7\nd3\nd4\nd6\nd7\ne3\ne5\nf4\nf5\ng2\ne4\nc6\n",
      "a2\na3\na4\na5\na6\na7\nb3\nb4\nb5\nb6\nc2\nc4\nc5\nc7\nd2\nd3\nd6\nd7\ne2\ne3\ne6\ne7\nf2\nf4\nf5\nf7\ng3\ng4\ng5\ng6\nh1\nh8\n",
      "b3\nc4\nd5\ne6\nf7\ng8\nh2\n",
      "a3\na4\na6\na7\nb1\nb4\nb6\nc1\nc2\nc8\nd1\nd8\ne1\ne8\nf1\nf2\nf8\ng1\ng2\ng3\ng4\ng6\nh3\nh4\nh6\nh7\nd5\ne5\n",
      "a1\na2\na3\na4\na5\na6\na7\na8\nb1\nb2\nb3\nb4\nb5\nb6\nb7\nb8\nc1\nc2\nc4\nc5\nc6\nc7\nc8\nd1\nd2\nd3\nd4\nd5\nd6\nd7\nd8\ne1\ne2\ne3\ne4\ne5\ne6\ne7\ne8\nf1\nf2\nf3\nf4\nf5\nf7\nf8\ng1\ng2\ng3\ng4\ng5\ng6\ng7\ng8\nh1\nh2\nh3\nh4\nh5\nh6\nh7\nh8\nc3\nf6\n"
     };


int main() {

  ofstream f;
  int i, j;

  for (i=0; i<10; i++) {
    sprintf(name,"chess.0%d.in",i);
    f.open(name);
    f<<pos[i];
    f.close();
  }
  f.open("chess.10.in");
  f<<pos[i];
  f.close();

  f.open("chess.bat");
  f<<bat;
  f.close();
  system ("chess.bat");
  system("del *.bat *.o");

  return 0;

}
