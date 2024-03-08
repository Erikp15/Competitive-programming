#include <iostream>
#include <cstring>
using namespace std;
char digChar(int d)//�������� "�����" � ��������� ������
{if (d<10) return d+'0';
 return d-10+'A';
}
int DigVal(char d)//����� ��������� �������� �� ������
{if (d<='9') return d-'0';
 return d-'A'+10;
}
int atoiMod(const char *a,int mod)//������ �������� �� ����� ����� �
                                  //��������� �����, �������� ���� ���, 
                                  //�� ������ �����
{unsigned long long r=0;
 while (*a>='0' && *a<='9') r=(10ULL*r+*a++-'0')%mod;
 return r;
}
int cycle(int f1,int f2,int radix)//������ ������ �� ����������
                                  //��� ����� �� �������� �� ��������
                                  //����� � ����� ���� � ������ ��
                                  //�������� �������
{int i,mod,t1,t2,t;
 mod=radix*radix;
 f1%=mod;
 f2%=mod;
 t1=f1;t2=f2;
 for (i=3;true;i++)
 {t=(t1+t2)%mod;
  t1=t2;
  t2=t;
  if (t1==f1 && t2==f2) return i-2;
 }  
}
//������� �� �������� �� �������� �����
void sol(int p,const char *n,const char *s1,const char *s2)
{int t,f1,f2,d,m,r;
 //���������� �� ����������� �� f1 � f2
 t=strlen(s1);
 if (t==1) f1=DigVal(*s1);
 else f1=p*DigVal(s1[t-2])+DigVal(s1[t-1]);   
 t=strlen(s2);
 if (t==1) f2=DigVal(*s2);
 else f2=p*DigVal(s2[t-2])+DigVal(s2[t-1]);
 //�������� �� ������ �� ���������� ��� �����
 d=cycle(f1,f2,p);
 //���������� �� ����������� ���� �� ��������
 m=atoiMod(n,d);
 if (!m) m=d;
 //�������� � ��������� �� ������������� �����
 //� ������ ������� � ������ radix
 t=p*p;
 switch(m)
 {case 1:{r=f1;break;}
  case 2:{r=f2;break;}   
  default:for (int i=3;i<=m;i++)
          {r=(f1+f2)%t;
           f1=f2;
           f2=r;   
          }
 }
 cout<<digChar(r/p)<<endl;
}
int main()
{int radix;
 char f1[128],f2[128],n[128];
 cin>>radix>>n>>f1>>f2;
 sol(radix,n,f1,f2);
 return 0;
}
