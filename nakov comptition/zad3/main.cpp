#include <iostream>

using namespace std;

int main(){
    char restaurant,dish,order;
    long long amount;
    cin>>dish>>restaurant>>amount>>order;
    if(dish=='sashimi'){
        if(restaurant=='Sushi Zone'){
            if(order=='Y'){
                cout<<amount*4.99+amount*4.99/5<<endl;
                return 0;
            }else{
                cout<<amount*4.99<<endl;
                return 0;
            }
        }
        if(restaurant=='Sushi Time'){
            if(order=='Y'){
                cout<<amount*5.49+amount*5.49/5<<endl;
                return 0;
            }else{
                cout<<amount*5.49<<endl;
                return 0;
            }
        }
        if(restaurant=='Sushi Bar'){
            if(order=='Y'){
                cout<<amount*5.25+amount*5.25/5<<endl;
                return 0;
            }else{
                cout<<amount*5.25<<endl;
                return 0;
            }
        }
    }
        if(restaurant=='Asian Pub'){
            if(order=='Y'){
                cout<<amount*4.50+amount*4.50/5<<endl;
                return 0;
            }else{
                cout<<amount*4.50<<endl;
                return 0;
            }
        }
    if(dish=='maki'){
        if(restaurant=='Sushi Zone'){
            if(order=='Y'){
                cout<<amount*5.29+amount*5.29/5<<endl;
                return 0;
            }else{
                cout<<amount*5.29<<endl;
                return 0;
            }
        }
        if(restaurant=='Sushi Time'){
            if(order=='Y'){
                cout<<amount*4.69+amount*4.69/5<<endl;
            }else{
                cout<<amount*4.69<<endl;
            }
        }
        if(restaurant=='Sushi Bar'){
            if(order=='Y'){
                cout<<amount*5.55+amount*5.55/5<<endl;
                return 0;
            }else{
                cout<<amount*5.55<<endl;
                return 0;
            }
        }
        if(restaurant=='Asian Pub'){
            if(order=='Y'){
                cout<<amount*4.80+amount*4.80/5<<endl;
            }else{
                cout<<amount*4.80<<endl;
            }
        }
    }
    if(dish=='uramaki'){
        if(restaurant=='Sushi Zone'){
            if(order=='Y'){
                cout<<amount*5.99+amount*5.99/5<<endl;
                return 0;
            }else{
                cout<<amount*5.99<<endl;
                return 0;
            }
        }
        if(restaurant=='Sushi Time'){
            if(order=='Y'){
                cout<<amount*4.49+amount*4.49/5<<endl;
                return 0;
            }else{
                cout<<amount*4.49<<endl;
                return 0;
            }
        }
        if(restaurant=='Sushi Bar'){
            if(order=='Y'){
                cout<<amount*6.25+amount*6.25/5<<endl;
                return 0;
            }else{
                cout<<amount*6.25<<endl;
                return 0;
            }
        }
        if(restaurant=='Asian Pub'){
            if(order=='Y'){
                cout<<amount*5.50+amount*5.50/5<<endl;
                return 0;
            }else{
                cout<<amount*5.50<<endl;
                return 0;
            }
        }
    }
    if(dish=='temaki'){
        if(restaurant=='Sushi Zone'){
            if(order=='Y'){
                cout<<amount*4.29+amount*4.29/5<<endl;
                return 0;
            }else{
                cout<<amount*4.29<<endl;
                return 0;
            }
        }
        if(restaurant=='Sushi Time'){
            if(order=='Y'){
                cout<<amount*5.19+amount*5.19/5<<endl;
                return 0;
            }else{
                cout<<amount*5.19<<endl;
                return 0;
            }
        }
        if(restaurant=='Sushi Bar'){
            if(order=='Y'){
                cout<<amount*4.75+amount*4.75/5<<endl;
                return 0;
            }else{
                cout<<amount*4.75<<endl;
                return 0;
            }
        }
        if(restaurant=='Asian Pub'){
            if(order=='Y'){
                cout<<amount*5.50+amount*5.50/5<<endl;
                return 0;
            }else{
                cout<<amount*5.50<<endl;
                return 0;
            }
        }
    }
    cout << restaurant<<" is invalid restaurant!" << endl;
    return 0;
}
