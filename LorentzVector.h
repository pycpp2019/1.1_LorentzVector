class LorentzVector{
    private:
    double x, y, z, t;
    public: 
    LorentzVector();
    LorentzVector(double , double , double , double);
    double get_t() const;
    double get_x() const;
    double get_y() const;
    double get_z() const;
    double get_norm() const;
    void change_t(double x);
    void change_x(double x);
    void change_y(double x);
    void change_z(double x);
    LorentzVector add(const LorentzVector& other) const;
    LorentzVector sub(const LorentzVector& other) const;
    LorentzVector mul(double a) const;
    void zboost(double beta);
    double dot(const LorentzVector& other) const;
    void read();
    void print() const;
};
