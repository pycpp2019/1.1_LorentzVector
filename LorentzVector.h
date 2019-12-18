#pragma once

class LorentzVector {
private:
    double t1, x1, y1, z1, norm1;
public:
    LorentzVector();
    LorentzVector(double t, double x, double y, double z);

    double t() const;
    double x() const;
    double y() const;
    double z() const;
    double norm() const;

    void t(double x);
    void x(double x);
    void y(double x);
    void z(double x);

    LorentzVector add(const LorentzVector& other) const;
    LorentzVector sub(const LorentzVector& other) const;
    LorentzVector mul(double a) const;
    void zboost(double beta);
    double dot(const LorentzVector& other) const;
    void read();
    void print() const;
};
