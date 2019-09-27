#include<iostream>
#include <cmath>
#include "LorentzVector.h"
using namespace std;
LorentzVector::LorentzVector(double a, double b, double c, double d)
{
  this->x1=a;
  this->y1=b;
  this->z1=c;
  this->t1=d;
}

LorentzVector::LorentzVector()
{
    this->x1=0; this->y1=0; this->z1=0; this->t1=0;
}

double LorentzVector::t() const
{
    return this->t1;
}

double LorentzVector::x() const
{
    return this->x1;
}

double LorentzVector::y() const
{
    return this->y1;
}

double LorentzVector::z() const
{
    return this->z1;
}

double LorentzVector::norm() const
{
    return sqrt(this->x1*this->x1+this->y1*this->y1+this->z1*this->z1+this->t1*this->t1);
}


void LorentzVector::t(double a)
{
    this->t1=a;
}

void LorentzVector::x(double a)
{
    this->x1=a;
}

void LorentzVector::y(double a)
{
    this->y1=a;
}

void LorentzVector::z(double a)
{
    this->z1=a;
}

void LorentzVector::read()
{
    cout<<"x=";
     cin >> this->x1;
     cout<<endl<<"y=";
     cin >> this->y1;
     cout<<endl<<"z=";
     cin >> this->z1;
     cout<<endl<<"t=";
     cin >> this->t1;
}

LorentzVector LorentzVector::add(const LorentzVector& other) const
{
    LorentzVector v;
    v.t(this->t1+other.t());
    v.x(this->x1+other.x());
    v.y(this->y1+other.y());
    v.z(this->z1+other.z());
    return v;

}

 LorentzVector LorentzVector::sub(const LorentzVector& other) const
 {
     LorentzVector v;
    v.t(this->t1-other.t());
    v.x(this->x1-other.x());
    v.y(this->y1-other.y());
    v.z(this->z1-other.z());
    return v;
 }

LorentzVector LorentzVector::mul(double a) const
{
 LorentzVector v;
 v.t(this->t1*a);
 v.x(this->x1*a);
 v.y(this->y1*a);
 v.z(this->z1*a);
 return v;
}

double LorentzVector::dot(const LorentzVector& other) const
{
    double dot;
    dot = this->x1*other.x()+this->y1*other.y()+this->z1*other.z()+this->t1*other.t();
    return dot;
}

void LorentzVector::zboost(double beta)
{
    int c=3*pow(10,8);
    double V=c*beta;
    double gamma = 1/(sqrt(1-beta*beta));
    double x2=gamma*(this->x1-V*this->t1);
    this->t1=gamma*(this->t1-V*this->x1/c*c);
    this->x1=x2;
}

void LorentzVector::print() const
{
    cout<<"(" << this->x1 << "," << this->y1 << "," << this->z1 << "," << this->t1 << ")" << endl;

}

int main()
{
 return 0;
}