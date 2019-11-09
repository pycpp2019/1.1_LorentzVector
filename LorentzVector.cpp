#include <iostream>
#include <cmath>
using namespace std;

class LorentzVector {
    double x1;
    double y1;
    double z1;
    double t1;

public:
    LorentzVector(){};
    LorentzVector(double x, double y, double z, double t){
         this->t1=t;
         this->x1=x;
         this->y1=y;
         this->z1=z;
    }

    double t () const {
        return this->t1;
    }
    double x () const {
        return this->x1;
    }
    double y ()const {
        return this->y1;
    }
    double z () const {
        return this->z1;
    }
    double norm() const {
        return sqrt(fabs((this->t())*(this->t())-(this->x())*(this->x())-(this->y())*(this->y())-(this->z())*(this->z())));
    }

    void x (double x) {
            x1=x;
    }
    void y (double y) {
            y1=y;
    }
    void z (double z) {
            z1=z;
    }
    void t (double t) {
            t1=t;
    }
    LorentzVector add (const LorentzVector& other) const {
        LorentzVector V(this->x()+other.x(),this->y()+other.y(),this->z()+other.z(),this->t()+other.t());
        return V;
    }
    LorentzVector sub (const LorentzVector& other) const {
        LorentzVector V(this->x()-other.x(),this->y()-other.y(),this->z()-other.z(),this->t()-other.t());
        return V;
    }
    LorentzVector mul (double a) const {
        LorentzVector V(this->x()*a,this->y()*a,this->z()*a,this->t()*a);
        return V;
    }
    void zboost (double beta) {
        double Gamma=sqrt(1-beta*beta);
        this->z(this->z()/Gamma);
        this->t(this->t()*Gamma);
    }
    double dot (const LorentzVector& other) const {
     return this->x()*other.x()+this->y()*other.y()+this->z()*other.z()+this->t()*other.t();
    }
    void read (){
        double t,x,y,z;
        cin >> t >> x >> y >> z;
        this->t(t);
        this->x(x);
        this->y(y);
        this->z(z);
    }
    void print() const {
        cout <<this->t() << this->x() << this->y() << this->z() << endl;
    }
};

