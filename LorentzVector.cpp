#include <iostream>
#include <cmath>

#include "LorentzVector.h"


LorentzVector::LorentzVector() {
    for (int i = 0; i < 4; ++i) {
        this->coord[i] = 0.0;
    }
}
LorentzVector::LorentzVector(double t, double x, double y, double z) {
    this->coord[0] = t;
    this->coord[1] = x;
    this->coord[2] = y;
    this->coord[3] = z;
}

double LorentzVector::t() const {
    return this->coord[0];
}
double LorentzVector::x() const {
    return this->coord[1];
}
double LorentzVector::y() const {
    return this->coord[2];
}
double LorentzVector::z() const {
    return this->coord[3];
}
double LorentzVector::norm() const {
    double n2 = this->dot(*this);
    return (n2 >= 0.0 ? 1.0 : -1.0)*sqrt(fabs(n2));
}

void LorentzVector::t(double v) {
    this->coord[0] = v;
}
void LorentzVector::x(double v) {
    this->coord[1] = v;
}
void LorentzVector::y(double v) {
    this->coord[2] = v;
}
void LorentzVector::z(double v) {
    this->coord[3] = v;
}

LorentzVector LorentzVector::add(const LorentzVector& other) const {
    LorentzVector v(*this);
    for (int i = 0; i < 4; ++i) {
        v.coord[i] += other.coord[i];
    }
    return v;
}
LorentzVector LorentzVector::sub(const LorentzVector& other) const {
    LorentzVector v(*this);
    for (int i = 0; i < 4; ++i) {
        v.coord[i] -= other.coord[i];
    }
    return v;
}
LorentzVector LorentzVector::mul(double a) const {
    LorentzVector v(*this);
    for (int i = 0; i < 4; ++i) {
        v.coord[i] *= a;
    }
    return v;
}
void LorentzVector::zboost(double beta) {
    double gamma = 1.0/sqrt(1.0 - beta*beta);
    double t = this->t();
    double z = this->z();
    this->t(gamma*(t - beta*z));
    this->z(gamma*(z - beta*t));
}
double LorentzVector::dot(const LorentzVector& other) const {
    return
        this->t()*other.t() +
        -this->x()*other.x() +
        -this->y()*other.y() +
        -this->z()*other.z();
}
void LorentzVector::read() {
    for (int i = 0; i < 4; ++i) {
        std::cin >> this->coord[i];
    }
}
void LorentzVector::print() const {
    std::cout << "{";
    for (int i = 0; i < 4; ++i) {
        std::cout << this->coord[i];
        if (i != 3) {
            std::cout << ", ";
        }
    }
    std::cout << "}" << std::endl;
}
