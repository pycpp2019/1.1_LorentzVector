#include<iostream>
#include <cmath>
#include "LorentzVector.h"
using namespace std;
LorentzVector::LorentzVector(double a, double b, double c, double d)
{
  this->x=a;
  this->y=b;
  this->z=c;
  this->t=d;
}

LorentzVector::LorentzVector()
{
    x=0; y=0; z=0; t=0;
}

double LorentzVector::get_t() const
{
    return this->t;
}

double LorentzVector::get_x() const
{
    return this->x;
}

double LorentzVector::get_y() const
{
    return this->y;
}

double LorentzVector::get_z() const
{
    return this->z;
}

double LorentzVector::get_norm() const
{
    return sqrt(this->x*this->x+this->y*this->y+this->z*this->z+this->t*this->t);
}


void LorentzVector::change_t(double a)
{
    this->t=a;
}

void LorentzVector::change_x(double a)
{
    this->x=a;
}

void LorentzVector::change_y(double a)
{
    this->y=a;
}

void LorentzVector::change_z(double a)
{
    this->z=a;
}

void LorentzVector::read()
{
    cout<<"x=";
     cin >> this->x;
     cout<<endl<<"y=";
     cin >> this->y;
     cout<<endl<<"z=";
     cin >> this->z;
     cout<<endl<<"t=";
     cin >> this->t;
}

LorentzVector LorentzVector::add(const LorentzVector& other) const
{
    LorentzVector v;
    v.change_t(this->t+other.get_t());
    v.change_x(this->x+other.get_x());
    v.change_y(this->y+other.get_y());
    v.change_z(this->z+other.get_z());
    return v;

}

 LorentzVector LorentzVector::sub(const LorentzVector& other) const
 {
     LorentzVector v;
    v.change_t(this->t-other.get_t());
    v.change_x(this->x-other.get_x());
    v.change_y(this->y-other.get_y());
    v.change_z(this->z-other.get_z());
    return v;
 }

LorentzVector LorentzVector::mul(double a) const
{
 LorentzVector v;
 v.change_t(this->t*a);
 v.change_x(this->x*a);
 v.change_y(this->y*a);
 v.change_z(this->z*a);
 return v;
}

double LorentzVector::dot(const LorentzVector& other) const
{
    double dot;
    dot = this->x*other.get_x()+this->y*other.get_y()+this->z*other.get_z()+this->t*other.get_t();
    return dot;
}

void LorentzVector::zboost(double beta)
{
    int c=3*pow(10,8);
    double V=c*beta;
    double gamma = 1/(sqrt(1-beta*beta));
    double x2=gamma*(this->x-V*t);
    this->t=gamma*(this->t-V*this->x/c*c);
    this->x=x2;
    cout<<"beta="<<beta<<", gamma="<<gamma<<", V="<<V<<endl;
}

void LorentzVector::print() const
{
    cout<<"(" << this->x << "," << this->y<< "," << this->z << "," << this->t << ")" << endl;

}

main()
{
 return 0;
}