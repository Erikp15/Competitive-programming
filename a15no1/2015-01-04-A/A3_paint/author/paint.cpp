#include <iostream>
using namespace std;
//���������� �� �������, ����� �� ������
//�� ������� ���� lev, � ���������� ������� �� �������� offs
long long No(int lev, long long offs)
{long long one=1;
 if (!lev) return 0;
 long long size=(one<<lev);//���� �������� �� ������
 long long start=size-1;//���-��� ������� �� ������
 if (offs&1) start+=(size>>1);//������ �� ��������� (����� �� 0)
 return start+(offs>>1);   
}
//���������� �� ������������ (���� � ����������) �� �������� �����
void Coord(long long n,int &lev,long long &offs)
{long long one=1;
 long long m=1;
 //���������� �� ������
 lev=-1;
 while (n>=m-1){m<<=1;lev++;}
 
 long long size=(one<<lev);//���� ����� �� ������
 long long start=size-1;//���-��� �������
 offs=0;//������� ����������
 //��� ��������� � �� ������� ��������:
 if (n>=start+(size>>1)){offs++;n-=(size>>1);}
 //���������� �� ������������
 offs+=((n-start)<<1);
}
void solve(long long N,long long &prev,long long &nextL,long long &nextR)
{int lev;
 long long offs;
 Coord(N,lev,offs);//���������� �� ���������� ����� (����, ����������)
 prev=No(lev-1,offs>>1);//�����, �������� �� ������ (���� ���� ��-���� � ���������� �� ������������)
 //�����, �������� �� ��������: ���� ���� ��-���� � ������ ���������� (+1 �� ������ ���)
 nextL=No(lev+1,2*offs);
 nextR=No(lev+1,2*offs+1);
}
int main()
{long long N,prev,nextL,nextR;
 cin>>N;
 solve(N,prev,nextL,nextR);
 cout<<prev<<endl;
 cout<<nextL<<' '<<nextR<<endl;
 return 0;
}