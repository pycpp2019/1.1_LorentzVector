#include <iostream>
#include <cmath>
#include "LorentzVector.h"

using namespace std;


LorentzVector::LorentzVector(){
         t1=0;
         x1=0;
         y1=0;
         z1=0;
    };
LorentzVector::LorentzVector( double x, double y, double z,double t ){
         t1=t;
         x1=x;
         y1=y;
         z1=z;
    }

double LorentzVector::  t () const {
        return this->t1;
    }
double LorentzVector:: x () const {
        return this->x1;
    }
double LorentzVector:: y ()const {
        return this->y1;
    }
double LorentzVector:: z () const {
        return this->z1;
    }
double LorentzVector:: norm() const {
        return sqrt(fabs((this->t())*(this->t())-(this->x())*(this->x())-(this->y())*(this->y())-(this->z())*(this->z())));
    }

void LorentzVector:: x (double x) {
            x1=x;
    }
void LorentzVector:: y (double y) {
            y1=y;
    }
void LorentzVector:: z (double z) {
            z1=z;
    }
void LorentzVector:: t (double t) {
            t1=t;
    }
LorentzVector LorentzVector:: add (const LorentzVector& other) const {
        LorentzVector V=LorentzVector(this->x()+other.x(),this->y()+other.y(),this->z()+other.z(),this->t()+other.t());
        return V;
    }
LorentzVector LorentzVector:: sub (const LorentzVector& other) const {
        LorentzVector V(this->x()-other.x(),this->y()-other.y(),this->z()-other.z(),this->t()-other.t());
        return V;
    }
LorentzVector LorentzVector:: mul (double a) const {
        LorentzVector V(this->x()*a,this->y()*a,this->z()*a,this->t()*a);
        return V;
    }
void LorentzVector:: zboost (double beta) {
        double Gamma=1/sqrt(1-beta*beta);
        this->z(Gamma*(z1-beta*t1));
        this->t(Gamma*(t1-beta*x1));
    }
double LorentzVector:: dot (const LorentzVector& other) const {
     return this->x()*other.x()+this->y()*other.y()+this->z()*other.z()-this->t()*other.t();
    }
void LorentzVector:: read (){
        double t,x,y,z;
        cin >> t >> x >> y >> z;
        this->t(t);
        this->x(x);
        this->y(y);
        this->z(z);
    }
void LorentzVector:: print() const {
        cout <<this->t() <<" "<< this->x()<<" " << this->y()<<" " << this->z() << endl;
    }

