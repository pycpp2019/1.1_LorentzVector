#include <iostream>
#include <math.h>
#include "LorentzVector.h"
using namespace std;
 LorentzVector:: LorentzVector(){
        t(0);x(0); y(0);z(0);
        }

LorentzVector::LorentzVector(double T, double X, double Y, double Z){
        t(T); x(X); y(Y); z(Z);}

double LorentzVector::t() const{
return p;
}
void LorentzVector::zboost ( double beta ) {
double Q = sqrt(1-beta*beta);
double P = (p + beta*d)/Q;
double B = b;
double C = c;
double D = (d + beta*d)/Q;
p = P;
b = B;
c = C;
d = D;
}
void LorentzVector::read(){
cin>>p>>b>>c>>d;
}
double LorentzVector::x() const{
return b;
}

double LorentzVector::y() const{
return c;
}

double LorentzVector::z() const{
return d;
}

double LorentzVector::norm() const{
return sqrt((p*p)-b*b-c*c-d*d);

}
    void LorentzVector::t(double x){
    this -> p = x;//имя передаваемого параметра может совпадать с полем класса, поэтому this
    }

    void LorentzVector::x(double x){
    this -> b = x;
    }

    void LorentzVector::y(double x){
    this -> c = x;
    }

    void LorentzVector::z(double x){
    this -> d = x;
    }
    void LorentzVector:: print() const {
    cout << "LorentzVector is " <<"{"<<t() << ',' << x() <<','<< y() << ',' << z() <<"}"<< endl;
    }
    LorentzVector LorentzVector :: mul (double a) const{
    LorentzVector third(p*a,b*a,c*a,d*a);
    return third;
    }
    LorentzVector LorentzVector::add ( const LorentzVector& other ) const {
    LorentzVector third(p+other.t(), b+other.x(), c+other.y(), d+other.z());
    return third;
    }//сложение векторов
    LorentzVector LorentzVector::sub ( const LorentzVector& other ) const {
    LorentzVector third(p-other.t(), b-other.x(), c-other.y(), d-other.z());
    return third;
    }
    double LorentzVector::dot(const LorentzVector& other) const{
    return p*other.t()- b*other.x()-c*other.y()-d+other.z();
    }
