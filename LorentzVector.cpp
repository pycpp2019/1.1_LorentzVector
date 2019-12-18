#include <iostream>
#include <cmath>
#include "LorentzVector.h"

using namespace std;

LorentzVector::LorentzVector(){
    this->t1 = 0;
    this->x1 = 0;
    this->y1 = 0;
    this->z1 = 0;
};

LorentzVector::LorentzVector(double t, double x, double y, double z){
    this->t1 = t;
    this->x1 = x;
    this->y1 = y;
    this->z1 = z; 
};


double LorentzVector::t() const{
    return this->t1;
};
double LorentzVector::x() const{
    return this->x1;
};
double LorentzVector::y() const{
    return this->y1;
};
double LorentzVector::z() const{
    return this->z1;
};
double LorentzVector::norm() const{
    double norm = sqrt(fabs(x1*x1+y1*y1+z1*z1-t1*t1));
    return norm;
};

void LorentzVector::t(double x){
    this->t1 = x;
};
void LorentzVector::x(double x){
    this->x1 = x;
};
void LorentzVector::y(double x){
    this->y1 = x;
};
void LorentzVector::z(double x){
    this->z1 = x;
};

LorentzVector LorentzVector::add(const LorentzVector& other) const{
    LorentzVector v (
    this->t1 + other.t(),
    this->x1 + other.x(),
    this->y1 + other.y(),
    this->z1 + other.z());
    return v;    
};
LorentzVector LorentzVector::sub(const LorentzVector& other) const{
    LorentzVector v (
    this->t1 - other.t(),
    this->x1 - other.x(),
    this->y1 - other.y(),
    this->z1 - other.z());
    return v;
};
LorentzVector LorentzVector::mul(double a) const{
    LorentzVector v (
    this->t1 * a,
    this->x1 * a,
    this->y1 * a,
    this->z1 * a);
    return v;
};

void LorentzVector::zboost(double beta){
    double z = (this->z1 - beta)/(sqrt(1 - beta * beta));
};

double LorentzVector::dot(const LorentzVector& other) const{
    return (this->x1 * other.x() + this->y1 * other.y() + this->z1 * other.z() - this->t1 * other.t());
};

void LorentzVector::read(){
    cin >> this->t1 >> this->x1 >> this->y1 >> this->z1;
};

void LorentzVector::print() const{
    cout << this->t1 << ", " << this->x1 << ", " << this->y1 << ", " << this->z1 << endl;
};
