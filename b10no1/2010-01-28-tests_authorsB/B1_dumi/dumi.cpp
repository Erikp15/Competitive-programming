#include <iostream>
#include <string>
using namespace std;
int main ()
{
    char duma[21],max_duma[21];
    int n,i,j,len_duma,br=0,suma,stepen, max=0,symbol;
    cin>>n;
    for (i=1; i<=n; i++)
    {
        cin>>duma;
        len_duma=strlen(duma);
        suma=0;
        stepen=1;
        for (j=0; j<len_duma; j++)
        {
            if (duma[j]>96) symbol=duma[j]-96;
            else symbol=duma[j]-64;
            suma=suma+stepen*symbol;
            stepen=stepen*2;
        }  
        if (suma>max) {
                       strcpy(max_duma,duma);
                       max=suma;
                       }
    }
    cout<<max_duma<<endl;
    system ("pause");
    return 0;
}
