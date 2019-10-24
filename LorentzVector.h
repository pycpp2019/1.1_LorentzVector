class LorentzVector {
private:
    double t_;
    double x_;
    double y_;
    double z_;
public:
    LorentzVector();
    LorentzVector(double, double, double, double);

    double t() const;
    double x() const;
    double y() const;
    double z() const;
    double norm() const;

    void t(double v);
    void x(double v);
    void y(double v);
    void z(double v);

    LorentzVector add(const LorentzVector& other) const;
    LorentzVector sub(const LorentzVector& other) const;
    LorentzVector mul(double l) const;
    void zboost(double beta);
    double dot(const LorentzVector& other) const;
    void read();
    void print() const;
};

