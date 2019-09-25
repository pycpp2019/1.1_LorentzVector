class LorentzVector {
private:
    double coord[4];
public:
    LorentzVector();
    LorentzVector(double, double, double, double);

    double t() const;
    double x() const;
    double y() const;
    double z() const;
    double norm() const;

    void t(double);
    void x(double);
    void y(double);
    void z(double);

    LorentzVector add(const LorentzVector& other) const;
    LorentzVector sub(const LorentzVector& other) const;
    LorentzVector mul(double a) const;
    void zboost(double beta);
    double dot(const LorentzVector& other) const;
    void read();
    void print() const;
};
