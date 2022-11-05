#include"Polynomial.h"
#include<cmath>

//Khoi tao
Polynomial::Polynomial(int n){
    this->n = n;
    if(this->n != 0){
        this->a = new int[n + 1];
        for(int i = 0;i <= this->n;i++){
            cout<<"a["<<i<<"] = ";
            cin>>this->a[i];
        }
    }
    else{
        this->a = nullptr;
    }
}

Polynomial::Polynomial(const Polynomial& Pn){
    this->n = Pn.n;
    this->a = new int[n + 1];
    for(int i = 0;i<=this->n;i++){
        *(this->a + i) = *(Pn.a + i);
    }
}

//Huy
Polynomial::~Polynomial(){
    delete[] a;
}

//Set
void Polynomial::set_n(const int& m){
    this->n = m;
    if(this->a == nullptr){
        this->a = new int[m + 1];
    }
    else{
        delete[] this->a;
        this->a = new int[m + 1];
    }
}

//Toan tu truy cap
int &Polynomial::operator[](const int& index){
    static int t = 0;
    if(index >= 0 && index <= this->n){
        return *(this->a + index);
    }
    return t;
}

//Toan tu +
Polynomial Polynomial::operator+(const Polynomial& Pn){
    Polynomial Qn;
    if(this->n >= Pn.n){
        Qn.set_n(this->n);
        for(int i = 0;i<=Qn.n;i++){
            if(i <= Pn.n)
                *(Qn.a + i) = *(this->a + i) + *(Pn.a + i);
            else 
                *(Qn.a + i) = *(this->a + i);
        }
    }
    else 
    {
        Qn.set_n(Pn.n);
        for(int i = 0;i<=Qn.n;i++){
            if(i <= this->n)
                *(Qn.a + i) = *(this->a + i) + *(Pn.a + i);
            else 
                *(Qn.a + i) = *(Pn.a + i);
        }
    }
    return Qn;
}

//Toan tu -
Polynomial operator - (const Polynomial &Pn, const Polynomial &Qn){
    Polynomial Kn;
    if(Pn.n >= Qn.n){
        Kn.set_n(Pn.n);
        for(int i = 0;i<=Kn.n;i++){
            if(i <= Qn.n)
                *(Kn.a + i) = *(Pn.a + i) - *(Qn.a + i);
            else 
                *(Kn.a + i) = *(Pn.a + i);
        }
    }
    else 
    {
        Kn.set_n(Qn.n);
        for(int i = 0;i<=Kn.n;i++){
            if(i <= Pn.n)
                *(Kn.a + i) = *(Pn.a + i) + *(Qn.a + i);
            else 
                *(Kn.a + i) = *(Qn.a + i) * (-1);
        }
    }
    return Kn;
}

//Toan tu =
const Polynomial& Polynomial::operator = (const Polynomial& Pn){
    this->n = Pn.n;
    if(this->a != nullptr){
        delete[] this->a;
    }
    this->a = new int[this->n + 1];
    for(int i = 0;i<=this->n;i++){
        (*this)[i] = *(Pn.a + i);
    }
}

//Toan tu ()
long long Polynomial::operator()(const int& x){
    long long Pn = 0;
    for(int i = 0;i<=this->n;i++){
        Pn += *(this->a + i) * pow(x,i);
    }
    return Pn;
}

//Toan tu xuat
ostream &operator<<(ostream& o, const Polynomial&  Pn){
    for(int i = Pn.n;i > 0; i--){
        if(*(Pn.a + i) != 0)
        {
            if(*(Pn.a + i - 1) >= 0 ){
            o<<*(Pn.a + i)<<"x^"<<i<<" + ";
        }
        else{
            o<<*(Pn.a + i)<<"x^"<<i<<" - ";
            *(Pn.a + i - 1) *= -1;
        }
        }
    }
    o<<*(Pn.a);
    return o;
}

//Toan tu nhap
istream& operator>>(istream& i, Polynomial& Pn){
    cout<<"Nhap n = ";
    i>>Pn.n;
    delete[] Pn.a;
    Pn.a = new int[Pn.n];
    for(int i = 0;i <= Pn.n;i++){
        cout<<"a["<<i<<"] = ";
        cin>>Pn.a[i];
    }
    return i;
}