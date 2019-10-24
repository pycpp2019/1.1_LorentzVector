#include<iostream>
#include<cmath>
#include"LorentzVector.h"
using namespace std;

    LorentzVector::LorentzVector(){
        for(int i = 0; i < 4;i++){
            this->data[i] = 0.0;
        };
    };
    LorentzVector::LorentzVector(double t, double x, double y, double z){
        this->data[0] = t;
        this->data[1] = x;
        this->data[2] = y;
        this->data[3] = z;
    };

    double LorentzVector::t() const{   return this->data[0];   };
    double LorentzVector::x() const{   return this->data[1];   };
    double LorentzVector::y() const{   return this->data[2];   };
    double LorentzVector::z() const{   return this->data[3];   };
    double LorentzVector::norm() const{
        double n = -(this->data[0])*(this->data[0]);
        for(int i = 1;i < 4; i++){n += this->data[i]*this->data[i];}
        if (n >= 0){
            n = sqrt(n);
        }else{
            n = sqrt(-n);
        }
        return n;
    };

    void LorentzVector::t(double x){   this->data[0] = x; return;  };
    void LorentzVector::x(double x){   this->data[1] = x; return;  };
    void LorentzVector::y(double x){   this->data[2] = x; return;  };
    void LorentzVector::z(double x){   this->data[3] = x; return;  };


    LorentzVector LorentzVector::add(const LorentzVector& other) const{
        LorentzVector v(this->data[0] + other.t(),this->data[1] + other.x(),this->data[2] + other.y(),this->data[3] + other.z());
        return v;
    };
    LorentzVector LorentzVector::sub(const LorentzVector& other) const{
        LorentzVector v(this->data[0] - other.t(),this->data[1] - other.x(),this->data[2] - other.y(),this->data[3] - other.z());
        return v;
    };
     LorentzVector LorentzVector::mul(double a) const{
        LorentzVector v(this->data[0]*a,this->data[1]*a,this->data[2] *a,this->data[3]*a);
        return v;
    };

    void LorentzVector::zboost(double beta){
        double a =(this->data[3]-beta*this->data[0])/(sqrt(1-beta*beta));
        this->data[0]=(this->data[0]-beta*this->data[3])/(sqrt(1-beta*beta));
        this->data[3] = a;
    };

    double LorentzVector::dot(const LorentzVector& other) const{
        double v = - this->data[0] * other.t() + this->data[1] * other.x()+ this->data[2] * other.y()+this->data[3] * other.z();
        return v;
    };
    void LorentzVector::read(){
        for(int i=0;i<4;i++){
        cin >> this->data[i];
        }
        return;
    };
    void LorentzVector::print() const{
        cout << "{";
        for(int i = 0; i < 4; i++){
            cout << this->data[i];
            if(i < 3)cout << ";";
        };
        cout << "}"<<endl;
    };


