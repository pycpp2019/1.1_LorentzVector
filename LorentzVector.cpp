#include "LorentzVector.h"
#include <iostream>
#include <math.h>

LorentzVector::LorentzVector() {
    t_ = 0;
    x_ = 0;
    y_ = 0;
    z_ = 0;
}
LorentzVector::LorentzVector(double T, double X, double Y, double Z) : t_(T), x_(X), y_(Y), z_(Z) {}

double LorentzVector::t() const {
    return t_;
}
double LorentzVector::x() const {
    return x_;
}
double LorentzVector::y() const {
    return y_;
}
double LorentzVector::z() const {
    return z_;
}
double LorentzVector::norm() const {
    return sqrt(fabs(- t_*t_ + x_*x_ + y_*y_ + z_*z_));
}

void LorentzVector::t(double v) {
    t_ = v;
}
void LorentzVector::x(double v) {
    x_ = v;
}
void LorentzVector::y(double v) {
    y_ = v;
}
void LorentzVector::z(double v) {
    z_ = v;
}

LorentzVector LorentzVector::add(const LorentzVector& b) const {
    double T = t_ + b.t_;
    double X = x_ + b.x_;
    double Y = y_ + b.y_;
    double Z = z_ + b.z_;
    return LorentzVector(T, X, Y, Z);
}
LorentzVector LorentzVector::sub(const LorentzVector& b) const {
    double T = t_ - b.t_;
    double X = x_ - b.x_;
    double Y = y_ - b.y_;
    double Z = z_ - b.z_;
    return LorentzVector(T, X, Y, Z);
}
LorentzVector LorentzVector::mul(double l) const {
    double T = l*t_;
    double X = l*x_;
    double Y = l*y_;
    double Z = l*z_;
    return LorentzVector(T, X, Y, Z);
}
void LorentzVector::zboost(double beta) {
    double G = sqrt(1 - beta*beta);
    double T = (t_ + beta*z_)/G;
    double X = x_;
    double Y = y_;
    double Z = (z_ + beta*t_)/G;
    t_ = T;
    x_ = X;
    y_ = Y;
    z_ = Z;
}
double LorentzVector::dot(const LorentzVector& b) const {
    return -t_*b.t_ + x_*b.x_ + y_*b.y_ + z_*b.z_;
}
void LorentzVector::read() {
    std::cin >> t_ >> x_ >> y_ >> z_;
}
void LorentzVector::print() const {
    std::cout << "(" << t_ << "; " << x_ << "; " << y_ << "; " << z_ << ")";
}
