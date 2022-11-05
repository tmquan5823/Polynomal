#include<iostream>
using namespace std;

class Polynomial{
    private:
        int n;
        int *a;
    public:
        Polynomial(int n = 0);
        Polynomial(const Polynomial&);
        ~Polynomial();
        void set_n(const int&);
        int &operator[](const int&); 
        Polynomial operator + (const Polynomial&);
        friend Polynomial operator - (const Polynomial&, const Polynomial&);
        const Polynomial& operator = (const Polynomial&);
        long long operator() (const int&);
        friend ostream& operator <<(ostream&, const Polynomial&);
        friend istream& operator >>(istream&, Polynomial&);
};