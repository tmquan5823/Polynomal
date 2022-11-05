#include"Polynomial.h"

int main(){
    Polynomial Pn(3);
    Polynomial Qn(Pn);
    Polynomial Kn;
    cin>>Kn;
    cout<<Pn<<"\n"<<Qn<<"\n"<<Kn<<endl;
    return 0;
}