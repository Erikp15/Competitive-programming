#include <iostream>


class fraction{
private:
    int nominator,denominator;

public:
    fraction(int inputnominator,int inputdenominator){
        this->nominator=inputnominator;
        this->denominator=inputdenominator;

    }
    int getnominator(){
        return this->nominator;
    }
    int getdenominator(){
        return this->denominator;
    }
    void setnominator(int inputset){
        this->nominator=inputset;
    }
    void setdenominator(int inputset){
        this->denominator=inputset;
    }
    void print(){
        std::cout<<this->nominator<<"/"<<this->denominator<<std::endl;
    }
};


fraction operator*(fraction init,fraction init2){
    fraction c(init.getnominator()*init2.getnominator(),init.getdenominator()*init2.getdenominator());
    return c;
}

fraction operator/(fraction init,fraction init2){
    fraction c(init.getnominator()*init2.getdenominator(),init.getdenominator()*init2.getnominator());
    return c;
}
fraction operator+(fraction init,fraction init2){
    fraction c(init.getnominator()*init2.getdenominator()+init2.getnominator()*init.getdenominator(),init.getdenominator()*init2.getdenominator());
    return c;
}
fraction operator-(fraction init,fraction init2){
    fraction c(init.getnominator()*init2.getdenominator()-init2.getnominator()*init.getdenominator(),init.getdenominator()*init2.getdenominator());
    return c;
}
bool operator>(fraction init,fraction init2){
    fraction c(init.getnominator()*init2.getdenominator()+init2.getnominator()*init.getdenominator(),init.getdenominator()*init2.getdenominator());
    return c;
}
bool operator<(fraction init,fraction init2){
    fraction c(init.getnominator()*init2.getdenominator()-init2.getnominator()*init.getdenominator(),init.getdenominator()*init2.getdenominator());
    return c;
}


int main(){
    int a,b,c,d;
    std::cin>>a>>b>>c>>d;
    fraction frac1(a,b),frac2(c,d);
    frac1.print();
    frac2.print();
    fraction frac3=frac1*frac2;
    frac3.print();
    frac3=frac1/frac2;
    frac3.print();
    frac3=frac1+frac2;
    frac3.print();
    frac3=frac1-frac2;
    frac3.print();
    return 0;
}
