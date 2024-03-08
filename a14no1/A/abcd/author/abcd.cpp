#include <iostream>
#include <cstring>
using namespace std;
char cons[32],vow[8];//�������� � ������ � "������� ���"
char syllable[128][4];//������ � "������� ���"
long N;
int c,v,p;//���� ��������, ���� ������, ���� ������
void inp()
{char a[32],s[8];
 cin>>a>>s>>N;
//�������� �� ������ � �������� � "������� ���"
 c=v=0;
 for (int i=0;a[i];i++)
  if (strchr(s,a[i])) vow[v++]=a[i];
  else cons[c++]=a[i];
//���������� �� ��������
 p=0;
 for (int i=0;i<c;i++)
  for (int j=0;j<v;j++) 
 {syllable[p][0]=cons[i];
  syllable[p][1]=vow[j];
  syllable[p++][2]=0;
 }
}
int main()
{ long long t,s,d;
  char num[32];//"�������" �� ���������� 120 �� �������� (p<=120)
               //� 32 �� ���� (N<2^32)
  inp();
//�������� �� ���� p-���� ����� � �������, 
//����� ������ �� �� ���������
  t=0;s=0;d=1;
  while (s<N) {t++;d*=p;s+=d;}
  s-=d;
  s=N-1-s;
//����������� �� s � t ����� �� ������ ������� � ������ p
  for (int i=t-1;i>=0;i--)
  {num[i]=s%p;
   s/=p;
  }
//��������� �� ���������
  for (int i=0;i<t;i++) cout<<syllable[(int)num[i]];
  cout<<endl;
  return 0;
}